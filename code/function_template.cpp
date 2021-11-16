#include <iostream>

class stone
{
private:
	int _w, _h, _weight;
public:
	stone(int w, int h, int we): _w(w), _h(h), _weight(we) {}

	// 要想使用 min 函数，就必须重载 < 函数 
	bool operator< (const stone& rhs)
	{
		return _weight < rhs._weight;
	}
};

template<typename T>
inline const T& min(const T& a, const T& b)
{
	return b < a ? b:a;
}

int main()
{
	stone r1(2,3), r2(3,3), r3;
	r3 = min(r1, r2); // 函数模板 不需要显式声明 min<stone>()

	return 0;
}