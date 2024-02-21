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
template<typename T, typename Args>
class Module {
public:
	virtual std::list<T> call(std::list<Args>& args) = 0;
	virtual ~Module() {}
};

// Container��Module���i�[���K�p���钊�ۃN���X
template<typename T, typename Args>
class Container : Module<T, Args> {
public:
	Container(std::list<Args>& args);
	std::list<T> call(std::list<Args>& args);
	~Container() {}
private:
	std::list<Args> _function_list;
};

// Founction�͏������L�q���ꂽ���ۃN���X
template<typename T, typename Args>
class Function : Module<T, Args> {
public:
	virtual std::list<T> call(std::list<Args>& args) = 0;
	virtual ~Function() {}
private:
	std::list<Args> _argument_list;
};

// ���T�C�Y�������s���֐�
template<typename T, typename Args>
class Resize : public Function<T, Args> {
public:
	Resize(int resize_x, int resize_y);
	std::list<T> call(std::list<cv::Mat>& args) override;
	~Resize() {}
private:
	std::list<int> _argument_list;
};

