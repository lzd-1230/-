#pragma once
#include<iostream>
#include<string>
#include <array>
using namespace std;
using  std::string;
using namespace std::string_literals;
enum class Color		//��Ҫ�������������ʱ����Color::!
{
	white, black, red, green, blue, yellow,
};
class Shape
{
private:
	Color color{ Color::black };
	bool filled{ false };
	array<string, 6> colorNames{ "white"s, "black"s, "red"s, "green"s, "blue"s, "yellow", };
public:
	Shape() = default;
	Shape(Color color_, bool filled_);
	Color getColor();
	void setColor(Color color_);
	bool is_filled();
	void setFilled(bool filled_);
	string toString();
	string colorToString();
	string filledToString();
	virtual double getArea() = 0;	//���麯��������.cpp��д����ʵ��
};
