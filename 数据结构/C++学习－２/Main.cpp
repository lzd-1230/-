#include"Circle.h"
#include<iostream>
using namespace std;

const void print( Circle& c)
{
	std::cout << c.getarea() << std::endl;
}

const void print(Circle* c)
{
	std::cout << c->getarea() << endl;
}

int main()
{
	//Circle c1;				//它的默认构造函数
	//Circle c2{2.0};			//有参构造函数,尽量使用大括号,看出来是新建立的

	//cout <<	c1.getarea() << endl;
	//cout << c2.getarea() << endl;
	//cout << Circle{ 4 }.getarea() << endl;//列表初始化明显多了

	//对象数组
	//Circle c1[]{ Circle(1.0),Circle{2.0},Circle{3.0} };	//两种括号形式都可以
	//Circle c2[]{ 10.0,11.0,12.0 };

	//c1[2].setr(4.0);
	//c2[1].setr(100.0);

	//auto area1{ 0.0 };
	//auto area2{ 0.0 };

	//for (int i = 0; i < sizeof(c1) / sizeof(c1[0]); i++)
	//{
	//	cout << c1[i].getarea() << endl;
	//	area1 += c1[i].getarea();
	//}

	//for (auto x : c2)		//x等价于c2的每一个成员
	//{
	//	cout << x.getarea() << endl;
	//	area2 += x.getarea();
	//}

	//cout << "numbers arear1:" << area1 << "\nnumbers arear2:" << area2;

	//重复delete
	//auto c1 = new Circle[3];
	//delete[] c1;
	//delete[] c1;	//delete在访问c1指向的那块存储区域的时候发生错误

	//对象数组作为函数参数
	//Circle c[]{ 1.0,2.0,3.0 };
	//print(c[1]);
	//print(c[2]);
	//print(c + 2);

	//对象作为函数返回值
	Circle c { 1.0 };
	cout << c.setradius(2.0)	//因为通过C.调用的setr函数,因此this指向C
		.setradius(3.0)
		.getarea() << endl;

	//
	return 0;
}