#pragma once
#include<iostream>
#include<string>
#include <iostream>
using namespace std;
using std::to_string;
class Date
{
private:
	int year = 2019, month = 1, day = 1;	//默认值,不调用含参构造函数
public:
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void setYear(int y) { year = y; }
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }
	Date() = default;	
	Date(int y, int m, int d) :year{ y }, month{ m },day{ d }{
		cout << Date::toString() << endl;
	}
	std::string toString()
	{
		return(to_string(year) + "-" + to_string(month) + "-" + to_string(day));
	}
};

