#include<iostream>
#include"Date.h"
#include"Employee.h"
int Employee::numberOfObjects = 0;
//�ڶѺ�ջ�зֱ������Employ����
int main()
{
	Employee e1;
	Employee* e2 = new Employee{ "John",Gender::male,Date{1990,3,2} };
	{
		Employee e3{ "Alice",Gender::female,Date{2001,11,22} };
	}
}