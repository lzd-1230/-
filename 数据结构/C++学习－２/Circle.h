#pragma once
class Circle
{
	double r1;
public:				//开放访问属性 
	Circle();		//无参
	Circle(double);	//有参构造
	double getarea();
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
};