
#include <iostream>

class A
{
public:
	int i{ 0 };
private:	//儿子都不能看
	int k{ 0 };
protected:	//外人不能看
	int j{ 0 };
};

class Pub:public A
{
public:
	void foo() { i++; j++;  }//私有数据成员k无法被子类访问
};

class Pro:protected A
{
public:
	void foo() { i++; j++; }//私有数据成员k无法被子类访问
};

class Pri :private A
{
public:
	void foo() { i++; j++;  }//私有数据成员k无法被子类访问
};

int main()
{
	Pub pub;
	Pri pri;
	Pro pro;
	pub.i++; pub.j++; pub.k++;
	pro.i++; pro.j++; pro.k++;
	pri.i++; pri.j++; pri.k++;
}

