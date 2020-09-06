#include<iostream>
#include"Date.h"
#include"Employee.h"
//创建Employee对象,然后修改生日
int main()
{
	Employee e;		//创建对象(默认构造函数初始化)
	//1.Setter
	//e.setBirthday(Date());
	std::cout << e.toString()<< std::endl;
	//2.getter
	e.getBirthday()->setYear(2001);
	std::cout << e.toString() << std::endl;
}