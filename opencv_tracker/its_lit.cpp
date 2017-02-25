#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#ifndef CV_VERSION
#define CV_VERSION "welp"
#endif

Mat src; Mat bw;
char window_name1[] = "Unprocessed Image";
char window_name2[] = "Processed Image";

KeyPoint* maxSizePoint(std::vector<KeyPoint> keypoints)
{
    KeyPoint* maxPoint = new KeyPoint(0.0, 0.0, 1);
    for (unsigned int i = 0; i < keypoints.size(); i++) {
      KeyPoint keypoint = keypoints[i];
      if (keypoint.size > maxPoint->size) {
        *maxPoint = keypoint;
      }
    }
    return maxPoint;
}

int main( int argc, char** argv )
{
    // 18.111.40.224
    /// Load the source image
    VideoCapture cap(0);

    while(true){
        cap >> src;

        //Reduces the visible items
        cv::inRange(src, Scalar(245, 245, 245), Scalar(255, 255, 255), bw);
        //cv::dilate(bw, bw, 0);

        SimpleBlobDetector::Params params;

        //Change thresholds
        params.minThreshold = 100;
        params.maxThreshold = 200;

        params.minDistBetweenBlobs = 20;

        params.filterByCircularity = false;
        params.filterByInertia = false;
        params.filterByConvexity = false;

        //Filter by Area.
        params.filterByColor = true;
        params.blobColor = 255;

        params.filterByArea = true;
        params.minArea = 50;
        params.maxArea = 2000000;

        std::vector<KeyPoint> keypoints;


	#if CV_MAJOR_VERSION < 3
        //OpenCV2
        SimpleBlobDetector detector(params);
        detector.detect(bw, keypoints);
	#else
        //OpenCV3
        Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
        detector->detect(bw, keypoints);
        #endif


        KeyPoint* mainPoint = maxSizePoint(keypoints);
        std::vector<KeyPoint> bestPoints;
        if (mainPoint != NULL) {
	  bestPoints.push_back((const KeyPoint) *mainPoint);
        } else {
	  bestPoints.push_back(keypoints[0]);
	}
	Mat im_with_keypoints;
        drawKeypoints(bw, bestPoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
        imshow("keypoints", im_with_keypoints);

        waitKey(1);

    }
    return 0;
}
