#pragma once
#include <iostream>
//任务:添加拷贝构造函数,析构函数,输出信息
class Square
{
private:
	double side;
	static int numOfObjects;	//在类里面跟普通变量一样声明
public:
	double getSide() { return side; }
	void setSide(double side) { this->side = side; }
	Square(double side)
	{
		this->side = side;
		numOfObjects++;
	}
	Square() :Square(1.0) {};
	Square(const Square& s):Square(s.side)		//拷贝构造函数也可以委托构造,但参数一定得有一个
	{
		//this->side = s.side;
		//numOfObjects++;
		std::cout << "拷贝构造函数is invoked" << std::endl;
	}

	~Square()
	{
		numOfObjects--;
	}
	//返回值是静态变量类型(可以用类的名称调用)
	static int getnumOfObjects() { return numOfObjects; }
	double getArea() { return side * side; }
	//返回值不是静态变量类型(不能通过类的名称调用)
	int getnumOfObjectsNonStatic() { return numOfObjects; }
};



