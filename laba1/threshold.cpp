#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
String window_name = "Threshold Demo";

String trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
String trackbar_value = "Value";

/// Function headers
void Threshold_Demo(int, void*);

/**
 * @function main
 */
int main2(int argc, char** argv)
{
    /// Load an image
    src = imread("C:\\Users\\fando\\Projects\\sample\\hello-world.png", 1);

    /// Convert the image to Gray
    cvtColor(src, src_gray, CV_BGR2GRAY);

    /// Create a window to display results
    namedWindow(window_name, CV_WINDOW_AUTOSIZE);

    /// Create Trackbar to choose type of Threshold
    createTrackbar(trackbar_type,
        window_name, &threshold_type,
        max_type, Threshold_Demo);

    createTrackbar(trackbar_value,
        window_name, &threshold_value,
        max_value, Threshold_Demo);

    /// Call the function to initialize
    Threshold_Demo(0, 0);

    /// Wait until user finishes program
    while (true)
    {
        int c;
        c = waitKey(20);
        if ((char)c == 27)
        {
            break;
        }
    }
    return 0;
}

void Threshold_Demo(int, void*)
{
    /* 0: Binary
       1: Binary Inverted
       2: Threshold Truncated
       3: Threshold to Zero
       4: Threshold to Zero Inverted
     */

    threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);

    imshow(window_name, dst);
}