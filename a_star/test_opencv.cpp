#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main() {
    cout << "OpenCV version: " << CV_VERSION << endl;
    cv::Mat img(200, 200, CV_8UC3, cv::Scalar(0, 255, 0));
    cv::imshow("Test Window", img);
    cv::waitKey(0);
    return 0;
}
