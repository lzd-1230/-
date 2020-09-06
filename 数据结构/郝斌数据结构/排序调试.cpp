//����������(������)
//Debug:ע��Ҫ�޸ĵı����ͽ������ķ�ʽһ��Ҫ�����û�ָ��
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int R[MAXSIZE];
	int len;
}SqList;

void swap(SqList *L,int i,int j)
{
	int temp;
	temp=L->R[i];
	L->R[i]=L->R[j];
	L->R[j]=temp;
}
void BubbleSort3(SqList *L)
{
	int i,j;
	bool flag=true;
	for(i=1;i<L->len;i++)
	{
		bool flag=false;
		for(j=4;j>=i;j--)
		{
			if(L->R[j]>L->R[j+1])
				swap(L,j,	j+1);
				flag=true;
		}
	}
}
void Select_sort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->len;i++)
	{
		min=i;
		for(j=i+1;j<=L->len;j++)
		{
			if(L->R[min] > L->R[j])
				min=j;
		}
		if(i!=min)
			swap(L,i,min);
	}
}
//�ൺ��ֱ�Ӳ��� 
void insert_sort2(SqList &L)
{
	int i,j;				//iΪ������Ԫ�ص��±�,jΪ�Ƚϵ��±�
	for(i=2;i<=L.len;i++)
	{ 
		if(L.R[i]<L.R[i-1])	//�����źò������Ļ���,ֱ��ԭλ���뼴��
			L.R[0]=L.R[i];
		else
			continue;
		for(j=i-1;L.R[0]<L.R[j];j--)
		{
			L.R[j+1]=L.R[j];
		}
		L.R[j+1]=L.R[0];	//���ղ����λ��Ӧ��Ϊj+1,˼���Ƶ�����ߵ����� 
	}
}
//ϣ������ 
void Shell_insert(SqList& L,int dk)
{
	int i,j;
	//�Դ�����Ԫ�صĴ�С�����ж�
	for(i=dk+1;i<=L.len;i++)	
	{
		if(L.R[i]<L.R[i-dk])
			L.R[0]=L.R[i];
		else					//ͬ����������Ԫ�ر��Ѿ��źõ����Ļ�Ҫ���Ǿ�ԭλ����
			continue;
		//�ȴ�С+�ƶ�
		for(j=i-dk;j>0 && L.R[0]<L.R[j];j=j-dk)	//��ֱ�Ӳ����е�-1�ĳ�-dk,���һ�Ҫȷ��j>0 
		{
			L.R[j+dk]=L.R[j]; 	//������
		}
		L.R[j+dk]=L.R[0];			
	}
}
//ϣ��������ѡ�� 
void Shell_sort(SqList& L)//�������������е�[0..t-1]��˳���L��ϣ������
{
	int delta[20],k=0; 
	int i,temp;
	for(int temp=L.len/3+1;temp>1;k++)
	{
		delta[k]=temp;
		temp=temp/3+1;				//������1��Ҳ���������ж� 
	} 
	delta[k]=1;
//	printf("delta����\n");
//	for(i=0;i<L.len;i++)
//	{
//		printf("%2d\n",delta[i]);
//	}
	for(i=0;i<=k;i++)
		Shell_insert(L,delta[i]);
}
//��
void Heapify(SqList *L,int Heapify_pos)
{
//	if(Heapify_pos>L->len)	 
//		return;
	int i; 
	int c1=2*Heapify_pos;
	int c2=2*Heapify_pos+1;
	int max=Heapify_pos;
	
	if(c1<=L->len && L->R[c1]>L->R[max])
		max=c1;
	if(c2<=L->len && L->R[c2]>L->R[max])
		max=c2;					
	//����������������±긳ֵ��max
	if(max!=Heapify_pos)
	{
		swap(L,max,Heapify_pos);		//swap���ܻ��ƻ��ѽṹ 
		Heapify(L,max);					//��Ϊ��build�е���ʱ���¶��ϵ�,���ÿswapyһ����Ҫ��֤swap������maxλ�����Ƕѽṹ	 
	}	
}
//������ 
void build(SqList *L)
{
	int last=L->len;
	int paren_last=last/2;
	int i;
	for(i=paren_last;i>=1;i--)
	{
		Heapify(L,i);
	}	
} 
//���ж�����
void Heap_sort(SqList *L)
{
	int i;
	build(L);
	for(i=L->len;i>=1;i--)
	{
		swap(L,i,1);
		L->len--;
		Heapify(L,1);
	}
}  
//�鲢 
void merge(SqList *L,int left,int mid,int right)
{
	int LeftSize=mid-left;
	int RightSize=right-mid+1;
	int left_a[LeftSize];
	int right_a[RightSize];
	int i,j,k;
	//����������
	for(i=left;i<mid;i++)
	{
		left_a[i-left]=L->R[i];			//���������
	}
	//�ұ��������
	for(i=mid;i<=right;i++)
	{
		right_a[i-mid]=L->R[i];
	}
	//�ϲ���ԭ����������
	i=0;j=0;k=left;
	while(i<LeftSize && j<RightSize)	//û�ж����߽�
	{
		if(left_a[i]<right_a[j])		//���С�����
		{
			L->R[k]=left_a[i];
			i++;k++;
		}
		else							//�ұ�С���ұ�
		{
			L->R[k]=right_a[j];
			j++;k++;
		}
	}
	while(i<LeftSize)
	{
		L->R[k]=left_a[i];
		i++;k++;
	}
	while(j<RightSize)
	{
		L->R[k]=right_a[j];
		j++;k++;
	}
}

void merge_sort(SqList *L,int left,int right)
{
	if(left==right)
		return;
	else
	{
		int mid=(left+right)/2;
		merge_sort(L,left,mid);
		merge_sort(L,mid+1,right);
		merge(L,left,mid+1,right);
	}
}
//�������� 
int findpos(SqList* L,int l,int h)
{
	int val=L->R[l];				//������ע������ط�����д��0��Ϊÿһ��ѭ�� 
	while(l<h)						//low��highС��һֱ���� 
	{
		while(l<h && L->R[h]>=val)		//�������ֱ����λ����,������Ҫ����
		{
			h--;
		}
		L->R[l]=L->R[h];					//����˵��a[h]��valС��,ִ�н���
		while(l<h && L->R[l]<=val)		//ͬ��
		{
			l++;
		}
		L->R[h]=L->R[l];	
	}							//ѭ��������low==high 
	L->R[l]=val;
	return l;
} 
void QuickSort(SqList* L,int l,int h)
{
	int pos;
	if(l<h)
	{ 
		pos=findpos(L,l,h);					//��a�������pos �ֳ�����
		QuickSort(L,l,pos-1);				//���һ�� 
		QuickSort(L,pos+1,h);				//�ұ�һ�� 
	}
}

int main()
{
	int i;
	SqList L={{2,8,9,10,4,5,6,7}}; 
	QuickSort(&L,0,7); 
	printf("�����:\n"); 
	for(i=0;i<=7;i++)
		printf("%d\n",L.R[i]);
	return 0;
}


