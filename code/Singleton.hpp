/* 单例模式 */

class A
{

public:
	static A& getInstance();
	setUp() 
	{ 
		//...;
	}

private:
	// 构造函数 private
	A();
	A(const A& rhs);
	// ...
};

inline A& A::getInstance
{
	static A a; // a 只初始化一次
	return a;
}

int main()
{
	A::getInstance().setUp();
}