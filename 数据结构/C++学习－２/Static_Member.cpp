#include<iostream>
#include"Square.h"
int Square::numOfObjects;	//��̬��Ա�������������ʼ��
int main()
{
	Square s1;
	std::cout << s1.getnumOfObjects() << std::endl;
	Square s2{ 2.0 };
	std::cout << Square::getnumOfObjects() << std::endl;
	std::cout << s2.getnumOfObjectsNonStatic() << std::endl;	//
	return 0;
}