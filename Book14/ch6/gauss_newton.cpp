#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv)
{
    // 生成数据
    double ar = 1.0, br = 2.0, cr = 1.0;    // 真实参数值
    double ae = 2.0, be = -1.0, ce = 5.0;   // 估计参数值
    int N = 100;                            // 数据个数
    double w_sigma = 1.0;                   // 噪声Sigma值
    double inv_sigma = 1.0 / w_sigma;
    cv::RNG rng;                            // OpenCV随机数生成器
    vector<double> x_data, y_data;
    // 带噪声数据
    for(int i = 0; i< N; i++)
    {
        double x = i / 100.0;
        x_data.push_back(x);
        y_data.push_back(exp(ar * x * x + br * x +cr) + rng.gaussian(w_sigma * w_sigma));
    }

    // Gauss-Newton
    int iteration = 100;                    // 迭代次数
    double cost = 0, last_cost = 0;         // 代价

    // chrono计时
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    for(int iter = 0; iter < iteration; iter++)
    {
        // 声明增量方程参数
        Matrix3d H = Matrix3d::Zero();      // Hessian = J * (W^2)^{-1} * J^T
        Vector3d b = Vector3d::Zero();      // bias = - J * (W^2)^{-1} * error
        cost = 0;

        for(int i = 0; i < N; i++)
        {
            // 取数据点
            double xi = x_data[i], yi = y_data[i];
            // 定义误差函数
            double error = yi - exp(ae * xi * xi + be * xi + ce);
            // 声明雅可比矩阵
            Vector3d J;
            J[0] = -xi * xi * exp(ae * xi * xi + be * xi + ce);
            J[1] = -xi * exp(ae * xi * xi + be * xi + ce);  
            J[2] = -exp(ae * xi * xi + be * xi + ce); 

            // 对 H 及 b 进行赋值
            H += inv_sigma * inv_sigma * J * J.transpose();
            b += - inv_sigma * inv_sigma * error * J;

            // 代价
            cost += error * error;
        }

        // 求解方程 Hx = b
        Vector3d dx = H.ldlt().solve(b);
        if(isnan(dx[0]))
        {
            cout << "result is nan!" << endl;
            break;
        }
        if (iter > 0 && cost >= last_cost) 
        {
            cout << "cost: " << cost << ">= last cost: " << last_cost << ", break." << endl;
            break;
        }

        ae += dx[0];
        be += dx[1];
        ce += dx[2];

        last_cost = cost;

        cout << "total cost: " << cost << ", \t\tupdate: " << dx.transpose() <<
            "\t\testimated params: " << ae << "," << be << "," << ce << endl;

    }

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "solve time cost = " << time_used.count() << " seconds. " << endl;

    cout << "estimated abc = " << ae << ", " << be << ", " << ce << endl;

    return 0;
}

