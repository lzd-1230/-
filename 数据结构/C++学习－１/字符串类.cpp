#include<iostream>
#include<string>
using namespace std;
int main()
{
	//�����ַ���
	string s{ "Hello" };
	//clear
	s.clear();
	//��������ַ�����ֵ
	char arr[]{ 'w','o','r','l','d' };
	//assign()
	s += arr;		//���������
	s.assign("HELLO WORLD");
	//append
	s.append(5, ' ');		//append ���������ָ�������
	s.append("!");			//û�ظ��ĸ�˫����???
	//insert�հ�
	s.insert(0, " ");
	//�Ƴ��ַ���ǰ��Ŀհ�
	s.erase(0, s.find_first_not_of("\t\n\r"));
	//�Ƴ��ַ�������Ŀհ�
	s.erase(s.find_last_not_of("\t\n\r"));
	//���ַ���ת��Ϊ�����򸡵���
	s.assign("1024");
	int x = std::stoi(s);
	cout <<"x��ֵΪ"<< x << endl;
	string s2 = to_string(x);
	cout << x << endl;
}