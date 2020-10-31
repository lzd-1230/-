#include<stdio.h>
#include<string.h>

char* MyString()
{
	char str[20];
	strcpy(str,"Hello");
	return str;
}

int main()
{
	printf("%s\n",MyString());
}

