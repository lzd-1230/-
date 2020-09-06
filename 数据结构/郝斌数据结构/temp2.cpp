#include<stdio.h>
void insert_sort(int* arry,int len)
{
	int i;				
	int temp;
	for(i=1;i<len;i++)
	{
		temp=arry[i];
		int j=i-1;
		while(temp<arry[j])
		{
			arry[j+1]=arry[j];
			j--;
		}
		arry[j+1]=temp;						
	}	
}
int main()
{
	int a[5]={3,1,2,5,4};
	insert_sort(a,5);
	for(int i=0;i<5;i++)
	{
		printf("%3d",a[i]);
	}
	return 0;
} 
