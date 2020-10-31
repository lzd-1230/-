#include<stdio.h>

int main()
{
	char ch = 'A';
	char *p;

	p = &ch;
	printf("%c,%c\n",ch,*p);
	
}
