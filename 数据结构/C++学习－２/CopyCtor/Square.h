#pragma once
#include <iostream>
//����:��ӿ������캯��,��������,�����Ϣ
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
	Square(const Square& s):Square(s.side)		//�������캯��Ҳ����ί�й���,������һ������һ��
	{
		//this->side = s.side;
		//numOfObjects++;
		std::cout << "�������캯��is invoked" << std::endl;
	}

	~Square()
	{
		numOfObjects--;
	}
	//����ֵ�Ǿ�̬��������(������������Ƶ���)
	static int getnumOfObjects() { return numOfObjects; }
	double getArea() { return side * side; }
	//����ֵ���Ǿ�̬��������(����ͨ��������Ƶ���)
	int getnumOfObjectsNonStatic() { return numOfObjects; }
};



