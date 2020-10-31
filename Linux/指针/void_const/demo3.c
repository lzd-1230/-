#include<stdio.h>

int main()
{
	const int n = 10;
	int m = 9;
	const * int p = &n;
	
	int* const q = &m;
	q = &n;
}
