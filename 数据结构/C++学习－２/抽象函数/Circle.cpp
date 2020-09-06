#include<iostream>
#include"Circle.h"
#include"Shape.h"
Circle::Circle()			//默认构造函数
{
	r1 = 1.0;
}
Circle::Circle(double r2, Color color_, bool filled_) : Shape(color_, filled_)	//需要参数
{
	r1 = r2;
}
double Circle::getArea() 
{
	return 3.14 * r1 * r1;
}
double Circle::getr() const	//const放在函数后面表示这个函数不修改成员的值
{
	//this->r1 = 2.0;
	return r1;
}
void Circle::setr(double r)
{
	this->r1 = r;
}
Circle& Circle::setradius(double r)
{
	this->r1 = r;
	//return Circle{ r };	//返回一个匿名对象
	return (*this);		//this指向当前对象
}
string Circle::toString()
{
	return ("Circle:radius" + std::to_string(r1) + "," + colorToString() + filledToString());
}