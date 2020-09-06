#include<iostream>
#include"StackOfInt.h"
using namespace std;
int main()
{
	StackOfInt s1{};
	for (int i = 0; i < 5; i++)
	{
		s1.push(i + 1);
	}
	cout <<"栈内元素个数"<< s1.getsize() << endl;
	cout <<"栈顶元素"<< s1.peek() << endl;

	int len = s1.getsize();
	for (int i = 0; i < len; i++)	//i在增加,size在减小,会出问题
	{
		cout << s1.pop() << " ";
	}
}