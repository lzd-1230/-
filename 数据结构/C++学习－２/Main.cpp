#include"Circle.h"
#include<iostream>
using namespace std;

const void print( Circle& c)
{
	std::cout << c.getarea() << std::endl;
}

const void print(Circle* c)
{
	std::cout << c->getarea() << endl;
}

int main()
{
	//Circle c1;				//����Ĭ�Ϲ��캯��
	//Circle c2{2.0};			//�вι��캯��,����ʹ�ô�����,���������½�����

	//cout <<	c1.getarea() << endl;
	//cout << c2.getarea() << endl;
	//cout << Circle{ 4 }.getarea() << endl;//�б��ʼ�����Զ���

	//��������
	//Circle c1[]{ Circle(1.0),Circle{2.0},Circle{3.0} };	//����������ʽ������
	//Circle c2[]{ 10.0,11.0,12.0 };

	//c1[2].setr(4.0);
	//c2[1].setr(100.0);

	//auto area1{ 0.0 };
	//auto area2{ 0.0 };

	//for (int i = 0; i < sizeof(c1) / sizeof(c1[0]); i++)
	//{
	//	cout << c1[i].getarea() << endl;
	//	area1 += c1[i].getarea();
	//}

	//for (auto x : c2)		//x�ȼ���c2��ÿһ����Ա
	//{
	//	cout << x.getarea() << endl;
	//	area2 += x.getarea();
	//}

	//cout << "numbers arear1:" << area1 << "\nnumbers arear2:" << area2;

	//�ظ�delete
	//auto c1 = new Circle[3];
	//delete[] c1;
	//delete[] c1;	//delete�ڷ���c1ָ����ǿ�洢�����ʱ��������

	//����������Ϊ��������
	//Circle c[]{ 1.0,2.0,3.0 };
	//print(c[1]);
	//print(c[2]);
	//print(c + 2);

	//������Ϊ��������ֵ
	Circle c { 1.0 };
	cout << c.setradius(2.0)	//��Ϊͨ��C.���õ�setr����,���thisָ��C
		.setradius(3.0)
		.getarea() << endl;

	//
	return 0;
}