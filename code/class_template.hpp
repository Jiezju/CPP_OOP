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
	// class body 内的成员函数 自动成为 inline function
	T real() const { return re; }
	void function();
	// ...
};

// 类的方法定义 也可以放在 Complex.cpp 中
// 类的 body 外定义 加上 inline
inline void Complex<T>::function()
{
	// ...
}



#endif