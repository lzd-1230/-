class Circle
{
public:			//���ŷ������� 
	//����
	double r1;
	//����
	Circle()			//Ĭ�Ϲ��캯��
	{
		r1 = 1.0;
	}
	Circle(double r2)	//��Ҫ����
	{
		r1 = r2;
	}
	double getarea()
	{
		return 3.14 * r1 * r1;
	}
};
#include<iostream>
using namespace std;
//��ָ����ʶ����Ա
//��һ:ָ��->��Ա
//����:*(ָ��).��Ա	ע��:����������ȼ��ǱȽ����õ����ȼ���!

//�����������������
//��һ:Circle c1[10];	10��Circle����ͨ��Ĭ�Ϲ��캯����ɵ�
//����(���������ʼ������):
//auto c2[3] =	//������Circle,����auto
//{
//	Circle{3},
//	Circle{5},
//	Circle{}	//Ĭ�Ϲ��캯��
//};
//����:�б��ʼ��
//Circle c3{ 3.1,4.2,{} };
//Circle c4 = Circle{ 3.1,4.2,{} };
//����:��̬�����ڴ����ɷ�!!
//auto c5 = new Circle[3]{ 3.1,4.2,{} };
//delete [] c5;
//c5 = nullptr;