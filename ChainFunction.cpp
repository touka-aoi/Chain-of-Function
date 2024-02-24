#include "ChainFunction.hpp"

namespace fc
{
	ResizeFunction::ResizeFunction(int width, int height) {
		_width = width;
		_height = height;
	};

	void* ResizeFunction::call(void* input) {
		cv::Mat& input_mat = *static_cast<cv::Mat*>(input);
		auto output = new cv::Mat;
		cv::resize(input_mat, *output, cv::Size(_width, _height));
		return output;
	};

	Container::Container(std::list<Module*> modules) {
		_functions_list = modules;
	}

	void* Container::call(void* input) {
		void* output = input;
		for (auto function : _functions_list) {
			output = function->call(output);
		}
		return output;
	}
}
