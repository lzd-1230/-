#include<iostream>
using namespace std;
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
		return 3.14 * r1*r1;
	}
};
class Squre
{
	double side{1.0};
public:

	Squre() = default;
	Squre(double side)
	{
		this->side = side;	//��ʾ����ʽ������ֵ��˽�г�Ա
	}
	double getside()
	{
		return (side * side);
	}
};
class Account
{
	double balance;
public:
	Account()
	{
		balance = 0.0;
	}
	Account(double balance_)
	{
		balance = balance_;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	double withdraw(double amount)
	{
		auto temp{ 0.0 };
		if (balance < amount)
		{
			temp = balance;
			balance = 0;
			return (temp);
		}
		else
		{
			balance -= amount;
			return(amount);
		}
	}
};

/*
��ĳ�ʼ����ʽ:
Circle c1;
Circle c2(5.5);
Circle c3{3.3};
auto c5=Circle{2.0};
decltype(c1) c6;
*/
//����������ľ͵س�ʼ��(��ס��ʼ������ʱ���Լ������)
//class MyClass
//{
//private:
//	int a1{ 3 };
//	int a2[2]{ 1,3 };
//};


//int main()
//{
//	Circle c1;				//����Ĭ�Ϲ��캯��
//	Circle c2{2.0};			//�вι��캯��,����ʹ�ô�����,���������½�����
//
//	cout <<	c1.getarea() << endl;
//	cout << c2.getarea() << endl;
//	cout << Circle{ 2.2 }.getarea() << endl;//�б��ʼ�����Զ��� 
//	return 0;
//}


//���󿽱�
//int main()
//{
//	Squre s1, s2{4.0};
//	cout << s1.getside() << endl;
//	cout << s2.getside() << endl;
//	s2 = s1;
//	cout << s1.getside() << endl;
//	cout << s2.getside() << endl;
//}

//���������ʹ�÷���
//int main()
//{
//	Account a1;
//	Account a2 = Account(100.0);
//
//	a1.deposit(9.0);
//
//	cout << a1.withdraw(10.0) << endl;
//	cout << a2.withdraw(52.0) << endl;
//	cout << Account(1000.0).withdraw(1001.0) << endl;
//	return 0;
//}

////���������������������Ч
//class A
//{
//public:
//	A() = default;	//�޲�Ĭ�Ϲ��캯��
//	double f1();
//};
//inline double A::f1()
//{
//	//doing
//}
////��Ч��
//class A
//{
//public:
//	A() = default;
//	double f1()
//	{
//		//doing
//	}
//};
//������̬����
//int main()
//{
//	auto pc1 = new Circle{};		//���޲ι��캯����������
//	auto pc2 = new Circle{ 5.0 } ; //�вι��캯��
//	auto pc3 = new Circle[3]{ 1,2,3 };	//����ָ�����鳤��
//
//	cout << (*pc1).getarea() << endl;
//	cout << pc2->getarea() << endl;
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << pc3[i].getarea()<< endl;
//	}
//	
//	//for (auto x : pc3)	//error:pc3���Ǽ�����Ԫ��,����ʹ�û��ڷ�Χ��forѭ��
//	//{
//	//	cout << x.getarea() << endl;
//	//}
//
//}
