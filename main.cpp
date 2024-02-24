#include <iostream>
#include <list>
#include <opencv2/opencv.hpp>
#include "ChainFunction.hpp"

int main()
{
	// �摜�̓ǂݍ���
	cv::Mat src = cv::imread("./image/test.png");

	// �֐��̍쐬
	fc::ResizeFunction resize1(252, 252);
	fc::ResizeFunction resize2(512, 512);
	fc::ResizeFunction resize3(1024, 1024);

	// �R���e�i�̍쐬
	fc::Container container(
		{
			&resize1,
			&resize3,
			&resize2,
		}
	);
		
	// �R���e�i�̎��s
	void* res = container.call(static_cast<void*>(&src));
	cv::Mat& res_mat = *static_cast<cv::Mat*>(res);

	// �摜�̏�������
	cv::imwrite("./image/test_rewrite.png", res_mat);
}