#include"StackOfInt.h"
StackOfInt::StackOfInt()
{
	size = 0;
	for (int& i : StackOfInt::elements)
	{
		i = -1;
	}
}

bool StackOfInt:: is_empty(StackOfInt s)
{
	return(size == 0 ? true : false);
}

int StackOfInt::getsize()
{
	return size;
}

int StackOfInt::peek()
{
	return elements[size - 1];
}

int StackOfInt::pop()
{
	int t{ elements[size - 1] };
	elements[size - 1] = -1;
	size--;
	return t;
}

int StackOfInt::push(int a)
{
	elements[size] = a;
	size++;
	return a;
}