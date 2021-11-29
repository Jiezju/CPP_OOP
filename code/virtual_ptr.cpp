class A
{
public:
	virtual void vfunc1() ;
	virtual void vfunc2() {};
		    void func1();
		    void func2();
private:
	int m_data1, m_data2;
};

class B : public A
{
public:
	virtual void vfunc1();
		    void func2(); // 子类成员函数与父类成员函数同名
private:
	int m_data3;	
};

class C : public B
{
public:
	virtual void vfunc1();
		    void func2();
private:
	int m_data4;
};