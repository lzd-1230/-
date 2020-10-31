#include<stdio.h>
#include<string.h>
char* My_StrCat(char* des,const char* str);

int main()
{
	char str[] = "how are you";
	char des[50] = {0};
	printf("%s\n",My_StrCat(des,str));
}

char* My_StrCat(char* des,const char* str)
{
	char* p = des;
	const char* q = str;

	while(*p)
	{
		p++;
	}
	
	while(*q)
	{
		*p = *q;
		q++;
		p++;
	}
	*p = '\0';
	
	return des;

}

