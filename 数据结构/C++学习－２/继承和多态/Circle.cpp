#include<iostream>
#include"Circle.h"
Circle::Circle()			//Ĭ�Ϲ��캯��
{
	r1 = 1.0;
}
Circle::Circle (double r2,Color color_,bool filled_): Shape(color_,filled_)	//��Ҫ����
{
	r1 = r2;
}
double Circle::getarea()
{
	return 3.14 * r1 * r1;
}
double Circle::getr() const	//const���ں��������ʾ����������޸ĳ�Ա��ֵ
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
	//return Circle{ r };	//����һ����������
	return (*this);		//thisָ��ǰ����
}