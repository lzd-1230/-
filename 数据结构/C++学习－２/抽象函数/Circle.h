#pragma once
#include"Shape.h"
class Circle :public Shape
{
	double r1;
public:				
	Circle();	
	Circle(double, Color, bool);	
	double getArea() override;	//重定义纯虚函数
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
	string toString();
};