#include<iostream>
#include"Date.h"
#include"Employee.h"
//����Employee����,Ȼ���޸�����
int main()
{
	Employee e;		//��������(Ĭ�Ϲ��캯����ʼ��)
	//1.Setter
	//e.setBirthday(Date());
	std::cout << e.toString()<< std::endl;
	//2.getter
	e.getBirthday()->setYear(2001);
	std::cout << e.toString() << std::endl;
}