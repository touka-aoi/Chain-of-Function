#pragma once
#ifdef _DEBUG
#pragma comment(lib, "opencv_world490d.lib")
#else
#pragma comment(lib, "opencv_world490.lib")
#endif
#include <list>
#include <opencv2/opencv.hpp>

namespace fc 
{

	// Moduleは呼び出しの振る舞いを定義する基底クラス
	class Module {
	public:
		virtual void* call(void* input) = 0;
		virtual ~Module() {}
	};

	class Function : public Module {
	public:
		virtual void* call(void* input) = 0;
	private:
	};

	class Container : public Module {
	public:
		Container(std::list<Module*> modules);
		void* call(void* input) override;
	private:
		std::list<Module*> _functions_list;
	};
}

namespace fc {

	class ResizeFunction : public Function {
	public:
		ResizeFunction(int width, int height);
		void* call(void* input) override;
	private:
		int _width;
		int _height;
	};
}