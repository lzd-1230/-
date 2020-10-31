#include<stdio.h>


int Str_Count( char*);

int main()
{
	char str[] = {"hellowjb"};
	printf("%d %s\n",Str_Count(str),str);
	
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

