#include<stdio.h>

int Str_Count( char*);
void Delete_Space(char *);

int main()
{
	char str[] = {"hello wjb"};
	Delete_Space(str);

	printf("%s\n",str);
	
}
void Delete_Space(char *p)
{
	char *q = p;
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
}

int Str_Count( char* p)
{
	int i = 0;
	
	while(*p != '\0')
	{
		if(*p<='z' && *p>='a' )
		{
			i++;
			*p = *p - ' ';
		}
		p++;
	}

	return i;
}

