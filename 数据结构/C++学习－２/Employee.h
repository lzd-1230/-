#pragma once
#include<iostream>
#include<string>
#include "Date.h"		//�Լ���ͷ�ļ���˫����
#include"Employee.h"
//���Ӿ�̬��Ա,�����������
//�����ո�ΪDate* ���͵�ָ��
//�޸Ĺ��캯������������
enum class Gender		//ö����
{
	male,	//0	��Ӧmale
	female	//1	��Ӧfemale
};
class Employee
{
private:
	std::string name;
	Gender gender;
	Date* birthday;
	static int numberOfObjects;
public:
	void setGender(Gender gender) { this->gender = gender; }
	void setName(std::string name) { this->name = name; }
	void setBirthday(Date birthday) { *(this->birthday) = birthday; }

	std::string getName() { return name; }
	Gender getGender() { return gender; }	//ö������->ת�����ַ���
	Date* getBirthday() { return birthday; }	//���ص���ָ��

	std::string toString()
	{
		return(name + " " + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday->toString());
	}
	//���캯��
	Employee(std::string name, Gender gender, Date birthday) :name{name},
		gender{ gender }{
		numberOfObjects++;
		this->birthday = new Date{ birthday };
		cout << "������" << numberOfObjects << "������" << endl;
	}						//Ϊɶ����thisָ��?�б��ʼ����ʱ������!
	Employee() :Employee("Anna", Gender::female, Date(2000,4,1)) {};
	~Employee()
	{
		numberOfObjects--;
		delete this->birthday;
		cout << "������" << numberOfObjects << "������" << endl;
	}
};