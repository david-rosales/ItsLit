#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat src; Mat dst; Mat hsv; Mat new_image;
char window_name1[] = "Unprocessed Image";
char window_name2[] = "Processed Image";



int main( int argc, char** argv )
{
    // 18.111.40.224
    /// Load the source image
    VideoCapture cap(0);
    
    while(true){
        cap >> src;

        //src = imread(argv[1]);

        namedWindow( window_name1, WINDOW_AUTOSIZE );
        imshow("Unprocessed Image",src);

        dst = src.clone();
        hsv = src.clone();

        //cv::cvtColor(src, dst, COLOR_BGR2GRAY);
        cv::cvtColor(dst, dst, COLOR_BGR2HSV);

        cv::inRange(dst, Scalar(0, 0, 245), Scalar(0, 0, 255), hsv);


        SimpleBlobDetector::Params params;
        
        //Change thresholds
        params.minThreshold = 10;
        params.maxThreshold = 2000;

        params.minDistBetweenBlobs = 20;

        params.filterByCircularity = false;
        params.filterByInertia = false;
        params.filterByConvexity = false;

        //Filter by Area.
        params.filterByColor = true;
        params.blobColor = 255;

        params.filterByArea = true;
        params.minArea = 50;
        params.maxArea = 20000000;

        SimpleBlobDetector detector(params);
        
        std::vector<KeyPoint> keypoints;
        detector.detect(hsv, keypoints);

        //namedWindow( window_name2, WINDOW_AUTOSIZE );
        Mat im_with_keypoints;
        drawKeypoints(src, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
 
        // Show blobs
        imshow("keypoints", im_with_keypoints);
        //imshow("Processed Imaged",hsv);

        waitKey(25);

    }
    return 0;
}