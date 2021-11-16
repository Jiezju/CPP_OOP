// 防卫式声明 __MYCOMPLEX__ 可以随便命名
#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex; 
complex&
  __doapl (complex* ths, const complex& r);
complex&
  __doami (complex* ths, const complex& r);
complex&
  __doaml (complex* ths, const complex& r);


class complex
{
public:
  // 构造函数 有默认参数的构造函数； pass by value； 初始化列表 
  complex (double r = 0, double i = 0): re (r), im (i) { // 可能分配内存}
  // 默认构造函数
  complex () : re (0), im (0) { }
  
  // 操作函数 成员函数
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  
  // 获取数据属性的成员函数 如果不改动数据，就必须 const，
  double real () const { return re; }
  double imag () const { return im; }
private:
  double re, im;
  
  // friend 保证了这些函数能够访问 成员变量
  friend complex& __doapl (complex *, const complex&);
  friend complex& __doami (complex *, const complex&);
  friend complex& __doaml (complex *, const complex&);
};

// 定义在类的body内默认是 inline 函数，在外部定义则需要显式 inline
inline complex& // 具体的实现
__doapl (complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}
 
// 操作符重载 左边参数被隐藏（this） 这是接口
inline complex& // 由于非 local object 所以可以引用传出
complex::operator += (const complex& r) // 右边不会被改变 所以 const
{
  return __doapl (this, r); // this 表示隐藏的左数
}

inline complex&
__doami (complex* ths, const complex& r)
{
  ths->re -= r.re;
  ths->im -= r.im;
  return *ths;
}
 
inline complex&
complex::operator -= (const complex& r)
{
  return __doami (this, r);
}
 
inline complex&
__doaml (complex* ths, const complex& r)
{
  double f = ths->re * r.re - ths->im * r.im;
  ths->im = ths->re * r.im + ths->im * r.re;
  ths->re = f;
  return *ths;
}

inline complex&
complex::operator *= (const complex& r)
{
  return __doaml (this, r);
}
 
inline double
imag (const complex& x)
{
  return x.imag ();
}

inline double
real (const complex& x)
{
  return x.real ();
}

// + 的运算符重载，不声明为成员函数，主要是存在其他类型与 complex 进行计算
inline complex // 存在 local object 不允许 return by reference
operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
}

inline complex
operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
  return complex (x + real (y), imag (y));
}

inline complex
operator - (const complex& x, const complex& y)
{
  return complex (real (x) - real (y), imag (x) - imag (y));
}

inline complex
operator - (const complex& x, double y)
{
  return complex (real (x) - y, imag (x));
}

inline complex
operator - (double x, const complex& y)
{
  return complex (x - real (y), - imag (y));
}

inline complex
operator * (const complex& x, const complex& y)
{
  return complex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

inline complex
operator * (const complex& x, double y)
{
  return complex (real (x) * y, imag (x) * y);
}

inline complex
operator * (double x, const complex& y)
{
  return complex (x * real (y), x * imag (y));
}

complex
operator / (const complex& x, double y)
{
  return complex (real (x) / y, imag (x) / y);
}

inline complex
operator + (const complex& x)
{
  return x;
}

inline complex
operator - (const complex& x)
{
  return complex (-real (x), -imag (x));
}

inline bool
operator == (const complex& x, const complex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator == (const complex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}

inline bool
operator == (double x, const complex& y)
{
  return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const complex& x, const complex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const complex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}

inline bool
operator != (double x, const complex& y)
{
  return x != real (y) || imag (y) != 0;
}

#include <iostream>

// 由于 希望完成 cout<<c1 而不是 c1<< cout ，就必须将输出重载函数置为非成员函数
operator << (ostream& os, const complex& x)
{
	os << real(x) << "," << imag(x) <<"."<<endl;
}

#include <cmath>

inline complex
polar (double r, double t)
{
  return complex (r * cos (t), r * sin (t));
}

inline complex
conj (const complex& x) 
{
  return complex (real (x), -imag (x));
}

inline double
norm (const complex& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

#endif   //__MYCOMPLEX__


// test function

int main()
{
  complex c1(2,1);
  cout << c1.real(); // public funciton 调用
  // cout << c1.re; error 不允许类外访问 private member 

}


