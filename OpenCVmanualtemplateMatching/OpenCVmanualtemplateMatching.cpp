// OpenCVmanualtemplateMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace cv;

int main()
{
	Mat source = imread("C:\\Users\\Rok\\Desktop\\input.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat templ = imread("C:\\Users\\Rok\\Desktop\\template.png", CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat buffer(Size(templ.cols, templ.rows),5);
	Mat buffer2(Size(templ.cols, templ.rows),5);

	buffer.setTo(Scalar(0.0f));
	buffer2.setTo(Scalar(0.0f));


	Mat result(Size(source.cols - templ.cols + 1, source.rows - templ.rows + 1),5);

	result.setTo(Scalar(1.0f));


	for (int i = 0; i < source.rows - templ.rows; i++) { //go through image
		for (int j = 0; j < source.cols - templ.cols; j++) {
			source(Rect(j,i,templ.cols,templ.rows)).copyTo(buffer);

		//	imshow("rekt",source(Rect(0, 1, templ.cols, templ.rows)));

		//	waitKey();
		//	imshow("buffer", buffer);
		//	waitKey(1);

			for (int ti = 0; ti < templ.rows; ti++) {
				for (int tj = 0; tj < templ.cols; tj++) {
					//printf("%d %d\n", ti, tj);
					buffer2.at<float>(Point(tj, ti)) = pow(templ.at<float>(Point(tj, ti)) - buffer.at<float>(Point(tj, ti)), 2);
				//	printf("%f\t", buffer2.at<float>(Point(tj, ti)));
				}
				printf("\n");
			}


			/*for (int ti = 0; ti < templ.rows; ti++) {
				for (int tj = 0; tj < templ.cols; tj++) {
					printf("%f  ", buffer2.at<float>(Point(tj, ti)));
				}
				printf("\n");
			}*/

			//return 0;
		//	imshow("b2", buffer2);
			
			result.at<float>(Point(j,i)) = (float)sum(buffer2).val[0] / (templ.cols * templ.rows);


			/*printf("%f\n", sum(buffer2).val[0]);

			printf("%f\n", (float)sum(buffer2).val[0] / (templ.cols * templ.rows));*/

		//	printf("result: %f", result.at<float>(Point(j, i)));
			//imshow("r", result);
			waitKey(1);
		//	buffer2.deallocate();
		}
		
		//printf("%d  %d test\n", i, j);
	}

	imshow("r", result);

	/*for (int i = 0; i <= result.cols; i++) {
		for (int j = 0; j <= result.rows; j++) {
			result.at<float>(Point(i, j)) = 1.0f;
			result.at<float>(Point(j, i)) = 0.5f;
			imshow("r", result);
			waitKey(0.01);
		}
	}*/

	
	printf("done\n");
	imshow("result", result);

	waitKey();
    return 0;
}

