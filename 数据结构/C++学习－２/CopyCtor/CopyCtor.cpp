//任务:分别在堆和栈中用拷贝构造函数创建对象
#include<iostream>
#include"Square.h"
using namespace std;
int Square::numOfObjects = 0;
int main()
{
	Square s1(10.0);
	cout << "Square: " << Square::getnumOfObjects() << endl;
	Square s2{ s1 };
	cout << "Square: " << Square::getnumOfObjects() << endl;
	Square* s3 = new Square{ s1 };
	cout << "Square: " << Square::getnumOfObjects() << endl;
	cout << "S3 area is: " <<   s3->getArea() << endl;
	delete s3;
	cout << "Square: " << Square::getnumOfObjects() << endl;
	return 0;
}