#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace cv;


Mat src; Mat bw;
char window_name1[] = "Unprocessed Image";
char window_name2[] = "Processed Image";

double weight_func(KeyPoint * keypoint, KeyPoint * oldMax);
double distance_between_pts(double x_1, double y_1, double x_2, double y_2);

KeyPoint* maxSizePoint(std::vector<KeyPoint> keypoints, KeyPoint * oldMax)
{
    KeyPoint* maxPoint = new KeyPoint(0.0, 0.0, 0.0);
    double max_weight = 0;
    for (unsigned int i = 0; i < keypoints.size(); i++) {
      double keypoint_weight = weight_func(&keypoints[i], oldMax);
      if (keypoint_weight > max_weight) {
        *maxPoint = keypoints[i];
        max_weight = keypoint_weight;
      }
    }
    return maxPoint;
}

// In general
// weight = (distance from old max * distance_weight) + (point size * size_weight)
double weight_func(KeyPoint * keypoint, KeyPoint * oldMax) 
{
  double distance_weight = 0.40;
  double distance_numerator = 200000;
  double size_weight = 0.75;

  Point2f p1 = oldMax->pt;
  Point2f p2 = keypoint->pt;
  double total_distance_weight = distance_weight *(distance_numerator / distance_between_pts(p1.x, p1.y, p2.x, p2.y));
  double total_size_weight = size_weight * keypoint->size;
  return total_distance_weight + total_size_weight;
  
}


double distance_between_pts(double x_1, double y_1, double x_2, double y_2)
{
  double distance = pow(x_2 - x_1, 2) + pow(y_2 - y_1,2);
  return pow(distance, 0.5);
}



int main( int argc, char** argv )
{
    // 18.111.40.224
    /// Load the source image
    VideoCapture cap(0);
    //cap.set(CV_CAP_PROP_EXPOSURE, -2);
    //cap.set(CV_CAP_PROP_GAIN, 0);
    //cap.set(CV_CAP_PROP_ISO_SPEED, 0);
    //cap.set(CV_CAP_PROP_WHITE_BALANCE_U, 0);
    //cap.set(CV_CAP_PROP_WHITE_BALANCE_V, 0);
    KeyPoint* mainPoint = new KeyPoint(0.0, 0.0, 0.0);

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


        mainPoint = maxSizePoint(keypoints, mainPoint);
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
