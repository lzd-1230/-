#pragma once
#include"Shape.h"
class Circle :public Shape
{
	double r1;
public:				
	Circle();	
	Circle(double, Color, bool);	
	double getArea() override;	//�ض��崿�麯��
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
	string toString();
};