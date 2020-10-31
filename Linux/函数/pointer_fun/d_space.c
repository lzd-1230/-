#include<stdio.h>
#include<string.h>
char* D_Space(char* p)
{
	char* r = p;
	char* q = p;
	while(*q)
	{
		if(*q == ' ')
		{
			q++;
		}
		else
		{
			*p = *q;
			q++;
			p++;
		}
	}
	*p = '\0';
	return r;
}
int main()
{
	char str[] = "how are you";
	strcpy(str,D_Space(str));
	puts(str);
}

