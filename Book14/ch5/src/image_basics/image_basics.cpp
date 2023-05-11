#include <iostream>
#include <chrono>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

int main(int argc, char** argv)
{
    // 读取输入图片
    cv::Mat image;
    // cv::imread 读取指定路径下的图片
    image = cv::imread(argv[1]);

    // 判断是否正确读取
    if(image.data == nullptr)
    {
        cerr << "文件" << argv[1] << "不存在" << endl;
        return 0;
    }

    // 输出图片基本信息
    cout << "图片宽: " << image.cols << ", 高：" << image.rows << ", 通道数：" << image.channels() << endl;
    cv::imshow("image", image);  // imshow显示图像
    cv::waitKey(0);              // 暂停程序，等待一个按键输入

    // 判断image的类型
    if (image.type() != CV_8UC1 && image.type() != CV_8UC3) 
    {
        // 图像类型不符合要求
        cout << "请输入一张彩色图或灰度图." << endl;
        return 0;
    }

    // 遍历图像, 请注意以下遍历方式亦可使用于随机像素访问
    // std::chrono 计时
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for(size_t y = 0; y < image.rows; y++)
    {
        // 用cv::Mat::ptr获得图像的行指针
        unsigned char* row_ptr = image.ptr<unsigned char>(y); // row_ptr是第y行的头指针
        for(size_t x = 0; x < image.cols; x++)
        {
            unsigned char* data_ptr = &row_ptr[x * image.channels()]; // data_ptr 指向待访问的像素数据
            // 输出该像素的每个通道,如果是灰度图就只有一个通道
            for(int c = 0; c != image.channels(); c++)
            {
                unsigned char data = data_ptr[c]; // data为I(x,y)第c个通道的值
            }
        }
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>> (t2 - t1);
    cout << "遍历图像用时：" << time_used.count() << " 秒。" << endl;

    // cv::Mat的拷贝
    // 直接赋值不会拷贝数据
    cv::Mat image_another = image;
    // 修改another将导致image发生变化
    image_another(cv::Rect(0, 0, 100, 100)).setTo(0); // 左上角置为零
    cv::imshow("image", image);
    cv::waitKey(0);

    // clone函数进行数据拷贝
    cv::Mat image_clone = image.clone();
    image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
    cv::imshow("image", image);
    cv::imshow("image_clone", image_clone);
    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}