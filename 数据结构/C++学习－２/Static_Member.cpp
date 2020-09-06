#include<iostream>
#include"Square.h"
int Square::numOfObjects;	//静态成员必须在类外面初始化
int main()
{
	Square s1;
	std::cout << s1.getnumOfObjects() << std::endl;
	Square s2{ 2.0 };
	std::cout << Square::getnumOfObjects() << std::endl;
	std::cout << s2.getnumOfObjectsNonStatic() << std::endl;	//
	return 0;
}