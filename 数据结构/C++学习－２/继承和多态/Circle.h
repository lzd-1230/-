#pragma once
#include"Shape.h"
class Circle:public Shape 
{
	double r1;
public:				//���ŷ������� 
	Circle();		//�޲�
	Circle(double,Color,bool);	//�вι���
	double getarea();
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
};