//简单的电脑猜数游戏和课程成绩
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	/*std::cout << "请输入整数:" << endl;
	auto x{ 0 };
	std::cin >> x;
	if (int z = rand() % 100; x > z)
	{
		std::cout << "猜大了,我的数是:" <<z<< endl;
	}
	else if (x < z)
	{
		std::cout << "猜小了,我的数是:" << z << endl;
	}
	else
	{
		std::cout << "猜对了" << endl;
	}*/

	//课程成绩
	cout << "请输入课程成绩:";
	auto score{ 0 };
	cin >> score;
	switch (auto x = score / 10; x)
	{
		case 10:
			cout << "满分!";
		case 9:
			cout << "A";
		case8:
			cout << "B";
		default:
			cout << "D";
	}
	
	
}