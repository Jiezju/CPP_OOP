class Account
{
public:
	static double m_rate;
	static void set_rate(const double& x) { m_rate = x; }
};

// 静态成员一定要初始化
double Account::m_rate = 8.0;

int main()
{	
	// 静态成员调用方法 1. 通过 class name 调用
	Account::set_rate(5.0);

	// 静态成员调用方法 2. 通过 对象 调用
	Account a;
	a.set_rate(7.0);

	return 0;
}