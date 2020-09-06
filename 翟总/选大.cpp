#include<stdio.h> 
int main()
{
	int max(int x,int y);
	int a,b,c;                   //int后加括号 
	scanf("%d,%d,&a,&b");
	c=max(a,b);
	printf("max=%d\n",c);
	return 0;
}
int max(int x,int y)
{ 
int z ;
if(x>y) z=x;
else z=y;
return (z);               //没打括号 
}

