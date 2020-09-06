#include<iostream>
#include<string>
using namespace std;
int main()
{
	//创建字符串
	string s{ "Hello" };
	//clear
	s.clear();
	//用数组给字符串赋值
	char arr[]{ 'w','o','r','l','d' };
	//assign()
	s += arr;		//运算符重载
	s.assign("HELLO WORLD");
	//append
	s.append(5, ' ');		//append 后面有数字跟单引号
	s.append("!");			//没重复的跟双引号???
	//insert空白
	s.insert(0, " ");
	//移除字符串前面的空白
	s.erase(0, s.find_first_not_of("\t\n\r"));
	//移除字符串后面的空白
	s.erase(s.find_last_not_of("\t\n\r"));
	//将字符串转化为整数或浮点数
	s.assign("1024");
	int x = std::stoi(s);
	cout <<"x的值为"<< x << endl;
	string s2 = to_string(x);
	cout << x << endl;
}