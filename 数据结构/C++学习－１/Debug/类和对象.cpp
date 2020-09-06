#include<iostream>
using namespace std;
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
		return 3.14 * r1*r1;
	}
};
class Squre
{
	double side{1.0};
public:

	Squre() = default;
	Squre(double side)
	{
		this->side = side;	//表示把形式参数赋值给私有成员
	}
	double getside()
	{
		return (side * side);
	}
};
class Account
{
	double balance;
public:
	Account()
	{
		balance = 0.0;
	}
	Account(double balance_)
	{
		balance = balance_;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	double withdraw(double amount)
	{
		auto temp{ 0.0 };
		if (balance < amount)
		{
			temp = balance;
			balance = 0;
			return (temp);
		}
		else
		{
			balance -= amount;
			return(amount);
		}
	}
};

/*
类的初始化方式:
Circle c1;
Circle c2(5.5);
Circle c3{3.3};
auto c5=Circle{2.0};
decltype(c1) c6;
*/
//类中数据域的就地初始化(记住初始化数组时候的约束即可)
//class MyClass
//{
//private:
//	int a1{ 3 };
//	int a2[2]{ 1,3 };
//};


//int main()
//{
//	Circle c1;				//它的默认构造函数
//	Circle c2{2.0};			//有参构造函数,尽量使用大括号,看出来是新建立的
//
//	cout <<	c1.getarea() << endl;
//	cout << c2.getarea() << endl;
//	cout << Circle{ 2.2 }.getarea() << endl;//列表初始化明显多了 
//	return 0;
//}


//对象拷贝
//int main()
//{
//	Squre s1, s2{4.0};
//	cout << s1.getside() << endl;
//	cout << s2.getside() << endl;
//	s2 = s1;
//	cout << s1.getside() << endl;
//	cout << s2.getside() << endl;
//}

//匿名对象的使用方法
//int main()
//{
//	Account a1;
//	Account a2 = Account(100.0);
//
//	a1.deposit(9.0);
//
//	cout << a1.withdraw(10.0) << endl;
//	cout << a2.withdraw(52.0) << endl;
//	cout << Account(1000.0).withdraw(1001.0) << endl;
//	return 0;
//}

////内联函数的声明方法与等效
//class A
//{
//public:
//	A() = default;	//无参默认构造函数
//	double f1();
//};
//inline double A::f1()
//{
//	//doing
//}
////等效于
//class A
//{
//public:
//	A() = default;
//	double f1()
//	{
//		//doing
//	}
//};
//创建动态对象
//int main()
//{
//	auto pc1 = new Circle{};		//用无参构造函数创建对象
//	auto pc2 = new Circle{ 5.0 } ; //有参构造函数
//	auto pc3 = new Circle[3]{ 1,2,3 };	//必须指定数组长度
//
//	cout << (*pc1).getarea() << endl;
//	cout << pc2->getarea() << endl;
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << pc3[i].getarea()<< endl;
//	}
//	
//	//for (auto x : pc3)	//error:pc3不是集合类元素,不能使用基于范围的for循环
//	//{
//	//	cout << x.getarea() << endl;
//	//}
//
//}
