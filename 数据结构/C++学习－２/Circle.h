#pragma once
class Circle
{
	double r1;
public:				//���ŷ������� 
	Circle();		//�޲�
	Circle(double);	//�вι���
	double getarea();
	double getr() const;
	void setr(double r);
	Circle& setradius(double r);
};