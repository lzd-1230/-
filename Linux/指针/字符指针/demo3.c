#include<stdio.h>
#include<string.h>
int main()
{
	char ch1[100] = "hello";
	char ch2[100] = " world";
	int i;

	char* p1 = ch1;
	char* p2 = ch2;

	/*
	while(*++p1);
	while(*p1++ = *p2++);
	*/


	/*while(*(p1+i)!='\0')
		i++;
	while(*(p2) != '\0')
	{
		*(p1+i) = *p2++;
		i++;
	}
	*/
	puts(ch1);
}
