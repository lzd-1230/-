#include <iostream>
using namespace std;

int main()
{
	//拿到cin的缓冲区指针
	auto p = cin.rdbuf();

	//从键盘读入字符到缓冲区,保留所有字符在缓冲区
	auto x = cin.peek();
	cout << "x=" << x << endl;
	//显示缓冲区的字符量
	cout << "缓冲区中有" << p->in_avail() <<"个字符"<< endl;
	int n = p->in_avail();
	//把缓冲区的字符都取出来并显示
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ":" << cin.get() << endl;
	}

}

