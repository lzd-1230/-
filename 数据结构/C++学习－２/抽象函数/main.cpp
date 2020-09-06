#include <iostream>
#include"Circle.h"
#include"Rectangle.h"
#include"Shape.h"
#include<string>
#include <iostream>

int main()
{
	//Shape s{ Color::black,true };		纯虚函数不能创建对象
	Circle c{ 1.2,Color::green,false };
	Shape* p = &c;	//可以用基类指针调用虚函数
	cout << p->getArea() << endl;
}

