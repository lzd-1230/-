#pragma once
class StackOfInt
{
private:
	int elements[100];
	int size{ 0 };
public:
	StackOfInt();
	bool is_empty(StackOfInt);
	int getsize();
	int peek();
	int pop();
	int push(int);
};