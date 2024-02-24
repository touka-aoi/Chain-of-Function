#pragma once
#ifdef _DEBUG
#pragma comment(lib, "opencv_world490d.lib")
#else
#pragma comment(lib, "opencv_world490.lib")
#endif
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

// Module�͌Ăяo���̐U�镑�����`�����ꒊ�ۃN���X
template<typename Result, typename... Args>
class Module {
public:
	virtual Result call(Args... args) = 0;
	virtual ~Module() {}
};

// Container��Module���i�[���K�p����N���X
template<typename Result, typename... Args>
class Container : Module<Result, Args> {
public:
	Container(Module... modules) {
		(_function_list.push_back(funcs), ...);
	};
	Result call(Args args) override {
		for (auto& function : _function_list) {
			args = function->call(args);
		}
		return args;
	};
	~Container() {}
private:
	std::list<std::shared_ptr<Module<Result, Arg>>> _function_list;
};
