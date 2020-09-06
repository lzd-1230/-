#include<iostream>
#include"Date.h"
#include"Employee.h"
//任务1:构造e1,浅拷贝e2
//任务2:深拷贝出e2
int Employee::numberOfObjects = 0;
int main()
{
	Employee e1{ "lzd1",Gender::male,{2001,11,22} };
	Employee e2{ e1 };
	cout << e1.toString() << endl;
	cout << e2.toString() << endl;
} 