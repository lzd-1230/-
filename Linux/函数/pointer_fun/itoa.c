#include<stdio.h>
char* Int_to_A(int n);

int main()
{
	int n;
	printf("input:");
	scanf("%d",&n);

	char* s = Int_to_A(n);
	puts(s);
}
char* Int_to_A(int n)
{
	char p[50];
	static char q[50] = {0};
	int i = 0,j = 0;
	
	while(n != 0)
	{
		p[i] = n%10 + '0';
		n/=10;
		i++;
	}
	//------转换顺序--------
	p[i] = '\0';
	int len = i;
	i--;

	for(j=0;j<len;j++,i--)
	{
		q[j] = p[i];
	}
	q[j] = '\0';
	return q;
}
