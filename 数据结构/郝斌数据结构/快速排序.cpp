//快速排序：先确定第一个元素的位置，然后将序列分成两半
//关键在于，如何找到第一个元素的确切位置
#include<stdio.h>
void QuickSort(int *,int ,int );
int findpos(int *a,int l,int h);
int main()
{
	int i;
	int a[6]={2,1,0,5,4,3};
	QuickSort(a,0,5);
	for(i=0;i<6;i++)
	{
		printf("%3d",a[i]);
	}
	return 0;
} 
void QuickSort(int *a,int l,int h)
{
	int pos;
	if(l<h)
	{ 
		pos=findpos(a,l,h);					//把a数组根据pos 分成两段
		QuickSort(a,l,pos-1);				//左边一半 
		QuickSort(a,pos+1,h);				//右边一半 
	}
}

int findpos(int *a,int l,int h)
{
	int val=a[0];					//！！！注意这个地方不能写成0因为每一次循环 
	while(l<h)						//low比high小就一直操作 
	{
		while(l<h && a[h]>=val)
		{
			h--;
		}
		a[l]=a[h];
		while(l<h && a[l]<=val)
		{
			l++;
		}
		a[h]=a[l];	
	}							//循环结束后low==high 
	a[l]=val;
	return l;
} 
