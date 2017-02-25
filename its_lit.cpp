#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

Mat src; Mat dst;
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

        cv::cvtColor(src, dst, COLOR_BGR2GRAY);

        namedWindow( window_name2, WINDOW_AUTOSIZE );
        imshow("Processed Image",dst);

        waitKey(30);

    }
    return 0;
}