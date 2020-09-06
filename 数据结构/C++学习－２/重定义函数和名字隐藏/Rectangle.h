#pragma once
#include"Shape.h"
class Rectangle :public Shape
{
private:
	double wide{ 1.0 };
	double len{ 1.0 };
public:
	Rectangle() = default;
	Rectangle(double wide_, double len_, Color color_, bool filled_) :Shape(color_, filled_)
	{
		wide = wide_;
		len = len_;
	}
	double getWide() const { return wide; };
	void setWide(double wide_) { wide = wide_; }
	double getLen() const { return len; }
	void setLen(double len_) { len = len_; }
	double getArea() const { return wide * len; }
	string toString()
	{
		return ("Rectangle width:"+std::to_string(wide)+","+"len:"+std::to_string(len)+ colorToString() + filledToString());
	}
};

