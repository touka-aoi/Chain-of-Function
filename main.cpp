#include <iostream>
#include <list>
#include <opencv2/opencv.hpp>
#include "ChainFunction.hpp"

int main()
{
	// 画像の読み込み
	cv::Mat src = cv::imread("./image/test.png");

	// 関数の作成
	fc::ResizeFunction resize1(252, 252);
	fc::ResizeFunction resize2(512, 512);
	fc::ResizeFunction resize3(1024, 1024);

	// コンテナの作成
	fc::Container container(
		{
			&resize1,
			&resize3,
			&resize2,
		}
	);
		
	// コンテナの実行
	void* res = container.call(static_cast<void*>(&src));
	cv::Mat& res_mat = *static_cast<cv::Mat*>(res);

	// 画像の書き込み
	cv::imwrite("./image/test_rewrite.png", res_mat);
}