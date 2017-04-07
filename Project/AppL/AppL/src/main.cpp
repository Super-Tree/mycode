#include "cv.h"
#include "highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "cvaux.h"

int main2()
{
	IplImage* src = NULL;
	IplImage* floatsrc = NULL;
	IplImage* floathsv = NULL;
	IplImage* floatimgH = NULL;
	IplImage* floatimgS = NULL;
	IplImage* floatimgV = NULL;

	cvNamedWindow("src", 1);
	cvNamedWindow("Hͨ��", 1);
	cvNamedWindow("Sͨ��", 1);
	cvNamedWindow("Vͨ��", 1);

	src = cvLoadImage("lena.jpg", -1);
	cvShowImage("src", src);
	CvSize size = cvGetSize(src);

	//�Ƚ�ͼ��ת����float�͵�
	floatsrc = cvCreateImage(size, IPL_DEPTH_32F, 3);
	floathsv = cvCreateImage(size, IPL_DEPTH_32F, 3);
	floatimgH = cvCreateImage(size, IPL_DEPTH_32F, 1);
	floatimgS = cvCreateImage(size, IPL_DEPTH_32F, 1);
	floatimgV = cvCreateImage(size, IPL_DEPTH_32F, 1);

	//��src��8λת����32λ��float��
	cvConvertScale(src, floatsrc, 1.0 / 255.0, 0);//��һ��֮���ܹ���ʾ
	//cvConvertScale( src, floatsrc, 1, 0 );
	//cvShowImage("floatsrc",floatsrc);
	//cvWaitKey(-1);

	//��float��ͼ�� ��BGRת����HSV  �����Ҫת������������ɫ�ռ� ��ô�ı�CV_BGR2HSV����
	//cvCvtColorҪ���������������ͱ�����ȫ��ͬ������ҪתΪfloat��
	cvCvtColor(floatsrc, floathsv, CV_BGR2HSV);

	//����ͨ��ͼ�� �ֽ��3����ͨ��ͼ��H��Ӧ��ͨ��ʱ0��S��V��Ӧ��ͨ��ʱ1��2
	//cvCvtPixToPlane(picHSV, h_plane, s_plane, v_plane, 0);
	cvSplit(floathsv, floatimgH, floatimgS, floatimgV, NULL);

	cvShowImage("src", src);
	cvShowImage("Hͨ��", floatimgH);
	cvShowImage("Sͨ��", floatimgS);
	cvShowImage("Vͨ��", floatimgV);
	//CV_BGR2HSV

	cvWaitKey(0);

	cvReleaseImage(&src);
	cvReleaseImage(&floathsv);
	cvReleaseImage(&floatimgH);
	cvReleaseImage(&floatimgS);
	cvReleaseImage(&floatimgV);

	return 0;
}
int main( )
{
	Mat src = imread("./data/pic001.png");
	//imshow("origin", src);
	
	//GaussianBlur(src, src, Size(3, 3), 0, 0);
	//src.convertTo(src, CV_32F, 1 / 255.0);

	Mat dst;
	cvtColor(src, dst, CV_RGB2HSV);
	vector<Mat> mv;
	split(src,mv);
	imshow("RGB", dst);
	imshow("H", mv[0]);
	imshow("S", mv[1]);
	imshow("V", mv[2]);
	 
	//Mat dst;
	//GaussianBlur(src, dst, Size(3, 3), 0, 0);
	//imshow("Gaussian", dst);
	//imwrite("./data/Gaussian.jpg", dst);
	//cvtColor(src, dst, CV_BGR2HSV);
	waitKey();
	return 0;
}