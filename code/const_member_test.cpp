//
// Created by bright on 2021/11/8.
//
#include <iostream>

using namespace std;

class A{
private:
    int m_i;
    int m_j;
public:
    A(int i , int j): m_i(i), m_j(j) {}
    int getI() { return m_i; }
    int getJ() { return m_j; }
};

class B{
private:
    int m_i;
    int m_j;
public:
    B(int i , int j): m_i(i), m_j(j) {}
    int getI() const { return m_i; }
    int getJ() const { return m_j; }
};


int main()
{
    const A a(1,2);
    // cout << a.getI()<< endl;  error

    const B b(1,2);
    cout << b.getI()<< endl;

    return 0;
}