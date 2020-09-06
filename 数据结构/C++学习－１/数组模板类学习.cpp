#include<iostream>
#include<array>
using namespace std;
void print(array<int,3>& a)
{
	for (auto x : a)
	{
		cout << x << " ";
	}
}
int search(array<int, 3>& a, int goal)
{
	bool exit{ false };
	int i = 0;
	for (; i < a.size(); i++)
	{
		if (a[i] == goal)
		{
			exit = true;
			break;
		}
	}
	if (exit)
		return i;
	else
		return (-1);
	
}
int main()
{
	//创建数组
	array<int,3> a1{ 1,2,4 };
	print(a1);
	cout << endl;
	//为数组赋值
	a1 = { 7,8,9 };
	print(a1);
	cout << endl;
	//交换数组
	array<int, 3>a2{ 3,4,5 };
	a1.swap(a2);
	print(a1);
	//求数组大小
	cout << a1.size() << endl;
	cout << a1.max_size() << endl;
	//在数组中查找一个值
	cout << search(a1, 4) << endl;
	cout << search(a1, 1) << endl;
	//sort
	sort(a1.rbegin(), a1.rend());
	print(a1);
	//二维数组
	array<array<int, 4>, 3>a1;
}