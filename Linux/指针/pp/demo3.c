#include<stdio.h>

int main()
{
	char* str[] = {"apple","orange","pear"};
	
	char** p = str;
	int i,n;

	n = sizeof(str)/sizeof(char*);
	i = 0;

	while(i < n)
	{
		printf("%s %s\n",str[i],*(p+i));
		i++;
	}	
	return 0;	
}
