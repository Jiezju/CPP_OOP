// 头文件的防卫式声明
#ifndef __COMPLEX_H__
#define __COMPLEX_H__

// 前置声明
class Complex;

// 类的声明 body 部分
template<typename T>
class Complex
{
private:
	T re;
	// ...
public:
	Complex() {}
	~Complex() {}
	void function();
	// ...
};

// 类的方法定义 也可以放在 Complex.cpp 中
void Complex<T>::function()
{
	// ...
}



#endif