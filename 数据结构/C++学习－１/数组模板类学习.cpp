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
	//��������
	array<int,3> a1{ 1,2,4 };
	print(a1);
	cout << endl;
	//Ϊ���鸳ֵ
	a1 = { 7,8,9 };
	print(a1);
	cout << endl;
	//��������
	array<int, 3>a2{ 3,4,5 };
	a1.swap(a2);
	print(a1);
	//�������С
	cout << a1.size() << endl;
	cout << a1.max_size() << endl;
	//�������в���һ��ֵ
	cout << search(a1, 4) << endl;
	cout << search(a1, 1) << endl;
	//sort
	sort(a1.rbegin(), a1.rend());
	print(a1);
	//��ά����
	array<array<int, 4>, 3>a1;
}