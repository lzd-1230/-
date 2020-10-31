#include<stdio.h>
#include<string.h>
int main()
{

	char ch1[] = "hello world";
	char *p = "hello";
	strcpy(p,ch1);

	puts(ch1);
	puts(p);
}
