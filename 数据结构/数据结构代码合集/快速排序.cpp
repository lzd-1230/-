//����������ȷ����һ��Ԫ�ص�λ�ã�Ȼ�����зֳ�����
//�ؼ����ڣ�����ҵ���һ��Ԫ�ص�ȷ��λ��
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
		pos=findpos(a,l,h);					//��a�������pos �ֳ�����
		QuickSort(a,l,pos-1);				//���һ�� 
		QuickSort(a,pos+1,h);				//�ұ�һ�� 
	}
}

int findpos(int *a,int l,int h)
{
	int val=a[0];					//������ע������ط�����д��0��Ϊÿһ��ѭ�� 
	while(l<h)						//low��highС��һֱ���� 
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
	}							//ѭ��������low==high 
	a[l]=val;
	return l;
} 
