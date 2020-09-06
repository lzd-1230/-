#include<iostream>
using namespace std;
class A {
public:
	A() { cout << "A()" << endl; }
	A(int i) { cout << "A(" << i << ")" << endl; }
};

class B:A {
public:
	B() { cout << "B()" << endl; }
	B(int i) { cout << "B(" << i << ")" << endl; }
};
int main()
{
	A a1{};
	A a2{ 2 };
	B b1{};
	B b2{ 2 };

}
