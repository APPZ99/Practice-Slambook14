#include "DBoW3/DBoW3.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    cout << "reading images... " << endl;
    vector<Mat> images; 
    for(int i = 0; i < 10; i++)
    {
        string path = "./data/" + to_string(i + 1) + ".png";
        images.push_back(imread(path));
    }

    cout << "detecting ORB features ... " << endl;
    Ptr<Feature2D> detector = ORB::create();
    vector<Mat> descriptors;
    for(Mat& image : images)
    {
        vector<KeyPoint> KeyPoint;
        Mat descriptor;
        detector->detectAndCompute(image, Mat(), KeyPoint, descriptor);
        descriptors.push_back(descriptor);
    }

    cout << "creating vocabulary ... " << endl;
    DBoW3::Vocabulary vocab;
    vocab.create(descriptors);
    cout << "vocabulary info: " << vocab << endl;
    vocab.save("vocabulary.yml.gz");
    cout << "done" << endl;

    return 0;
}

