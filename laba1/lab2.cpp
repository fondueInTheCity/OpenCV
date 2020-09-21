#include "lab2.h"

void laba2(cv::String imagePath) {
    convolution1(imagePath);
    blur2(imagePath);
    erosionAndDilatation3(imagePath);
    canny4(imagePath);
    normalaizeGistogramm5(imagePath);
}

void convolution1(cv::String imagePath) {
    const int N = 2;
    cv::String names[]{ "Initial Image", "Filter2D" };
    const float kernelData[]{ -1.0f, -1.0f, -1.0f, -1.0f, 9.0f, -1.0f, -1.0f, -1.0f, -1.0f };
    const cv::Mat kernel(3, 3, CV_32FC1, (float*)kernelData);
    cv::Mat imageRGB = cv::imread(imagePath, 1), filter2dImage;

    filter2D(imageRGB, filter2dImage, -1, kernel);

    cv::Mat images[]{ imageRGB, filter2dImage };

    end(N, names, images);
}

void blur2(cv::String imagePath) {
    const int N = 5;
    cv::String names[]{ "Initial Image", "Blur2D", "boxFilter", "gaussianBlur", "medianBlur" };
    cv::Mat imageRGB(imread(imagePath, 1)), blurImage, boxFilterImage, gaussianBlurImage, medianBlurImage;

    cv::blur(imageRGB, blurImage, cv::Size(3, 3));
    boxFilter(imageRGB, boxFilterImage, -1, cv::Size(3, 3));
    GaussianBlur(imageRGB, gaussianBlurImage, cv::Size(3, 3), 1.0);
    medianBlur(imageRGB, medianBlurImage, 1);

    cv::Mat images[]{ imageRGB, blurImage, boxFilterImage, gaussianBlurImage, medianBlurImage };

    end(N, names, images);
}

void erosionAndDilatation3(cv::String imagePath) {
    const int N = 3;
    cv::String names[]{ "Initial Image", "erode", "dilate" };
    cv::Mat imageRGB(imread(imagePath, 1)), erodeImg, dilateImg, element = cv::Mat();

    erode(imageRGB, erodeImg, element);
    dilate(imageRGB, dilateImg, element);

    cv::Mat images[]{ imageRGB, erodeImg, dilateImg, element };

    end(N, names, images);
}

void canny4(cv::String imagePath) {
    const int N = 2;
    cv::String names[]{ "Initial Image", "Canny" };
    cv::Mat img(imread(imagePath, 1)), cannyImg(img);
    double lowThreshold = 70, uppThreshold = 260;

    canny(&cannyImg);

    cv::Mat images[]{ img, cannyImg };

    end(N, names, images);
}

void normalaizeGistogramm5(cv::String imagePath) {
    const int N = 2;
    cv::String names[]{ "Initial", "Eequalize Hist" };
    cv::Mat img(imread(imagePath, 1)), grayImg, equalizeHistImage;

    cv::cvtColor(img, grayImg, CV_RGB2GRAY);
    cv::equalizeHist(grayImg, equalizeHistImage);

    cv::Mat images[]{ img, equalizeHistImage };

    end(N, names, images);
}