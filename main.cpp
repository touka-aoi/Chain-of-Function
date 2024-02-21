#include "main.hpp"

template<typename T, typename Args>
Container<T, Args>::Container(std::list<Args>& args) {
	_function_list = args; // �֐���o�^
}

// call�֐��́A�󂯎����args���֐����X�g�ɓo�^���ꂽ�֐��ɓn���Ă���
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
	_argument_list = std::list<int>{ resize_x, resize_y }; // ������o�^(252,252)�Ȃ�
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
		// ��O����
	}

	return result;
}

int main() {
	// �摜�̓ǂݍ���
	cv::Mat img = cv::imread("./image/test.png");

	Resize<std::list<cv::Mat>, std::list<cv::Mat>>(252,252)

	// �摜�̏�������
	cv::imwrite("./image/rewrite_test.png", img);
}