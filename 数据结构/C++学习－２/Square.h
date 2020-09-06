#pragma once
class Square
{
private:
	double side;
	static int numOfObjects;	//�����������ͨ����һ������
public:
	double getSide() { return side; }
	void setSide(double side) { this->side = side; }
	Square(double side)
	{
		this->side = side;
		numOfObjects++;
	}
	Square() :Square(1.0) {};
	//����ֵ�Ǿ�̬��������(������������Ƶ���)
	static int getnumOfObjects() { return numOfObjects; }
	double getArea() { return side * side; }
	//����ֵ���Ǿ�̬��������(����ͨ��������Ƶ���)
	int getnumOfObjectsNonStatic() { return numOfObjects; }	
};