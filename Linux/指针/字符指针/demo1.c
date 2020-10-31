#include<stdio.h>
#include<ctype.h>
int main()
{

	char ch1[] = "hello world";
	char ch2[] = "hello world";
	char *p;
	
	p = ch1;
	if(isalpha(*p))
	{
		if(islower(*p))
		{
			*p = toupper(*p);
		}
	}

	printf("%s\n",p);

	p = ch2;
	printf("%s\n",p);
}
