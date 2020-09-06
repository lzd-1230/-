#pragma once
#include<iostream>
#include<string>
#include "Date.h"		//自己的头文件用双引号
#include"Employee.h"
//增加静态成员,计算对象数量
//将生日改为Date* 类型的指针
//修改构造函数和析构函数
enum class Gender		//枚举类
{
	male,	//0	对应male
	female	//1	对应female
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
	Gender getGender() { return gender; }	//枚举类型->转化成字符串
	Date* getBirthday() { return birthday; }	//返回的是指针

	std::string toString()
	{
		return(name + " " + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday->toString());
	}
	//构造函数
	Employee(std::string name, Gender gender, Date birthday) :name{name},
		gender{ gender }{
		numberOfObjects++;
		this->birthday = new Date{ birthday };
		cout << "现在有" << numberOfObjects << "个对象" << endl;
	}						//为啥不能this指针?列表初始化的时候不能用!
	Employee() :Employee("Anna", Gender::female, Date(2000,4,1)) {};
	~Employee()
	{
		numberOfObjects--;
		delete this->birthday;
		cout << "现在有" << numberOfObjects << "个对象" << endl;
	}
};