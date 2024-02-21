#include "main.hpp"

template<typename T, typename Args>
Container<T, Args>::Container(std::list<Args>& args) {
	_function_list = args; // 関数を登録
}

// call関数は、受け取ったargsを関数リストに登録された関数に渡していく
template<typename T, typename Args>
std::list<T> Container<T, Args>::call(std::list<Args>& args) {
	std::list<T> result;
    for (Module& function : _function_list) {
		args = function->call(args);
	}
	return result;
}

template<typename T, typename Args>
Resize<T, Args>::Resize(int resize_x, int resize_y) {
	_argument_list = std::list<int>{ resize_x, resize_y }; // 引数を登録(252,252)など
}

template<typename T, typename Args>
std::list<T> Resize<T, Args>::call(std::list<cv::Mat>& args) {
	std::list<T> result;
	if (args.size() == 1) {
		cv::Mat img = args.front();
		cv::resize(img, img, cv::Size(_argument_list.front(), _argument_list.back()));
		result.push_back(img);
	}
	else {
		// 例外処理
	}

	return result;
}

int main() {
	// 画像の読み込み
	cv::Mat img = cv::imread("./image/test.png");

	Resize<std::list<cv::Mat>, std::list<cv::Mat>>(252,252)

	// 画像の書き込み
	cv::imwrite("./image/rewrite_test.png", img);
}