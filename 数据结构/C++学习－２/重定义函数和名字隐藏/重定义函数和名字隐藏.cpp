#include <iostream>
#include"Circle.h"
#include"Rectangle.h"
#include"Shape.h"
#include<string>
int main()
{
	Shape s1{ Color::blue,false };
	Circle c1{ 3.9 ,Color::red,true };
	Rectangle r1{ 4.0,1.0,Color::green,true };

	cout << s1.toString() << endl;
	cout << c1.toString() << endl;
	cout << r1.toString() << endl;
}
