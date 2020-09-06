//for(元素名:广义集合)
//广义集合的例子
/*
auto a1[]{1,3,4,6};		auto不使用C数组
std::array<int,4>a2{2,4,5,6};
*/
//例子:让a数组的每一个元素*2
#include<iostream>
using namespace std;
int main() 
{
	int a[]={ 1,2,3,4 };
	for (auto i : a)
	{
		i *= 2;
	}
	for (auto i : a)
	{
		cout << i << endl;
	}
}