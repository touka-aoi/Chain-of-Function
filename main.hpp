#pragma once
#ifdef _DEBUG
#pragma comment(lib, "opencv_world490d.lib")
#else
#pragma comment(lib, "opencv_world490.lib")
#endif
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

// Moduleは呼び出しの振る舞いを定義する基底抽象クラス
template<typename T, typename Args>
class Module {
public:
	virtual std::list<T> call(std::list<Args>& args) = 0;
	virtual ~Module() {}
};

// ContainerはModuleを格納し適用する抽象クラス
template<typename T, typename Args>
class Container : Module<T, Args> {
public:
	Container(std::list<Args>& args);
	std::list<T> call(std::list<Args>& args);
	~Container() {}
private:
	std::list<Args> _function_list;
};

// Founctionは処理が記述された抽象クラス
template<typename T, typename Args>
class Function : Module<T, Args> {
public:
	virtual std::list<T> call(std::list<Args>& args) = 0;
	virtual ~Function() {}
private:
	std::list<Args> _argument_list;
};

// リサイズ処理を行う関数
template<typename T, typename Args>
class Resize : public Function<T, Args> {
public:
	Resize(int resize_x, int resize_y);
	std::list<T> call(std::list<cv::Mat>& args) override;
	~Resize() {}
private:
	std::list<int> _argument_list;
};

