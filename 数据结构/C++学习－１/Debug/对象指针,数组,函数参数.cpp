class Circle
{
public:			//开放访问属性 
	//数据
	double r1;
	//函数
	Circle()			//默认构造函数
	{
		r1 = 1.0;
	}
	Circle(double r2)	//需要参数
	{
		r1 = r2;
	}
	double getarea()
	{
		return 3.14 * r1 * r1;
	}
};
#include<iostream>
using namespace std;
//用指针访问对象成员
//法一:指针->成员
//法二:*(指针).成员	注意:点运算符优先级是比解引用的优先级高!

//对象数组的声明方法
//法一:Circle c1[10];	10个Circle都是通过默认构造函数完成的
//法二(匿名对象初始化数组):
//auto c2[3] =	//后面又Circle,可以auto
//{
//	Circle{3},
//	Circle{5},
//	Circle{}	//默认构造函数
//};
//法三:列表初始化
//Circle c3{ 3.1,4.2,{} };
//Circle c4 = Circle{ 3.1,4.2,{} };
//法四:动态分配内存生成法!!
//auto c5 = new Circle[3]{ 3.1,4.2,{} };
//delete [] c5;
//c5 = nullptr;