#pragma once
#include"Shape.h"
class Circle:public Shape 
{
	double r1;
public:				//开放访问属性 
	Circle();		//无参
	Circle(double,Color,bool);	//有参构造
	double getarea();
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
};