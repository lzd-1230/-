#include<iostream>
using namespace std;
class Circle
{
private:
	double radius;
public:
	Circle(double r)
	{
		radius = r;
	}
	double getarea()
	{
		return 3.14 * radius *radius;
	}
};
class Squre
{
private:
	double side;
public:
	double getArea()
	{
		return side * side;
	}
};
class Com
{
public:
	Circle c;
	Squre s;
};
int main()
{
	Com o{};
	cout << o.c.getarea() << endl;
}