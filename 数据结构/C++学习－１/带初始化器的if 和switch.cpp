//�򵥵ĵ��Բ�����Ϸ�Ϳγ̳ɼ�
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	/*std::cout << "����������:" << endl;
	auto x{ 0 };
	std::cin >> x;
	if (int z = rand() % 100; x > z)
	{
		std::cout << "�´���,�ҵ�����:" <<z<< endl;
	}
	else if (x < z)
	{
		std::cout << "��С��,�ҵ�����:" << z << endl;
	}
	else
	{
		std::cout << "�¶���" << endl;
	}*/

	//�γ̳ɼ�
	cout << "������γ̳ɼ�:";
	auto score{ 0 };
	cin >> score;
	switch (auto x = score / 10; x)
	{
		case 10:
			cout << "����!";
		case 9:
			cout << "A";
		case8:
			cout << "B";
		default:
			cout << "D";
	}
	
	
}