#include<iostream>
using namespace std;
class B {
public:
	B() { cout << "B()" << endl; }
	B(int i) { cout << "B(" << i << ")" << endl; }
	B(char c) { cout << "B(" << c << ")" << endl; }
};

class E
{
public:
	E() { cout << "E()" << endl; }
};
class D:B
{
private:
	E e1;
public:
	using B::B;	//将B的所有构造函数都继承过来
	D() = default;
//因此现在存在3
//D():B(){}
//D(int i):B(i){}	
//D(char c):B(c){}
	D(double x) :e1{},B(static_cast<int> (x)) { cout << "D(" << x << ")" << endl; }
};

int main()
{
	B b;
	D d;
	D d1(3.1);
}