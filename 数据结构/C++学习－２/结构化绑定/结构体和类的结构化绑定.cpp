#include<iostream>
using namespace std;

struct S
{
	double d1{ 1.0 };
	int i1{ 32 };
};
class C
{
public:
	int i2{ 1 };
	char c[3]{ 'a','b','\0' };	//������û���ÿ��ָ����ȷ�Ĵ�С,��Ϊ���г�ʼ��Ҫָ��,C�ж�����!
};
int main()
{
	S s;
	C c;
	auto [s1, s2] {s};
	auto [c1, c2] {c};
	auto& [s3, s4] {s};
	auto& [c3, c4] {c};
	cout << "s.d1=" << s1 << " s.i1=" << s2 << endl;
	cout << "c.i2=" << c1 << " c.c=" << c2 << endl;
}