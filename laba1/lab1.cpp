#include "lab1.h"

void laba1(cv::String imagePath) {
    const int N = 2;
    cv::Mat images[N] = { cv::imread(imagePath), cv::imread(imagePath, 0) };
    cv::String names[N] = { "Image RGB", "Image 0" };

    end(N, names, images);
}