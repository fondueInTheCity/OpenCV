﻿#include "lab3.h"

void laba3() {
    cv::Mat frame;
    cv::VideoCapture cap;
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    cap.open(deviceID + apiID);

    for (;; cap.read(frame)) {
        //sobel(&frame);
        //laplas(&frame);
        canny(&frame);

        imshow("Live", frame);
        if (cv::waitKey(5) >= 0)
            break;
    }
}

void sobel(cv::Mat* mat) {
    int ddepth = CV_16S;
    double alpha = 0.5, beta = 0.5;
    cv::Mat grayImg, xGrad, yGrad, xGradAbs, yGradAbs, grad;

    GaussianBlur(*mat, *mat, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);     // преобразование в оттенки серого     
    cvtColor(*mat, grayImg, CV_RGB2GRAY);     // вычисление производных по двум направлениям     
    Sobel(grayImg, xGrad, ddepth, 1, 0); // по Ox     
    Sobel(grayImg, yGrad, ddepth, 0, 1); // по Oy     // преобразование градиентов в 8-битные     
    convertScaleAbs(xGrad, xGradAbs);
    convertScaleAbs(yGrad, yGradAbs);     // поэлементное вычисление взвешенной      // суммы двух массивов     
    addWeighted(xGradAbs, alpha, yGradAbs, beta, 0, *mat);
}



void laplas(cv::Mat* mat) {
    cv::Mat grayImg, laplacianImg, laplacianImgAbs;
    int ddepth = CV_16S;

    GaussianBlur(*mat, *mat, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
    cvtColor(*mat, grayImg, CV_RGB2GRAY);
    Laplacian(grayImg, laplacianImg, ddepth);
    convertScaleAbs(laplacianImg, *mat);
}

void canny(cv::Mat* mat) {
    cv::Mat grayImg;
    double lowThreshold = 70, uppThreshold = 260;

    blur(*mat, *mat, cv::Size(3, 3));
    cvtColor(*mat, grayImg, CV_RGB2GRAY);
    Canny(grayImg, *mat, lowThreshold, uppThreshold);
}