//二叉排序树(待运行)
//Debug:注意要修改的变量送进函数的方式一定要是引用或指针
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
//青岛版直接插入 
void insert_sort2(SqList &L)
{
	int i,j;				//i为待插入元素的下标,j为比较的下标
	for(i=2;i<=L.len;i++)
	{ 
		if(L.R[i]<L.R[i-1])	//若比排好部分最大的还大,直接原位插入即可
			L.R[0]=L.R[i];
		else
			continue;
		for(j=i-1;L.R[0]<L.R[j];j--)
		{
			L.R[j+1]=L.R[j];
		}
		L.R[j+1]=L.R[0];	//最终插入的位置应该为j+1,思考移到最左边的特例 
	}
}
//希尔排序 
void Shell_insert(SqList& L,int dk)
{
	int i,j;
	//对待插入元素的大小进行判断
	for(i=dk+1;i<=L.len;i++)	
	{
		if(L.R[i]<L.R[i-dk])
			L.R[0]=L.R[i];
		else					//同理若待插入元素比已经排好的最大的还要大那就原位不动
			continue;
		//比大小+移动
		for(j=i-dk;j>0 && L.R[0]<L.R[j];j=j-dk)	//把直接插入中的-1改成-dk,并且还要确保j>0 
		{
			L.R[j+dk]=L.R[j]; 	//往后移
		}
		L.R[j+dk]=L.R[0];			
	}
}
//希尔增量的选择 
void Shell_sort(SqList& L)//按照增量序列中的[0..t-1]对顺序表L做希尔排序
{
	int delta[20],k=0; 
	int i,temp;
	for(int temp=L.len/3+1;temp>1;k++)
	{
		delta[k]=temp;
		temp=temp/3+1;				//就算变成1了也不会马上判断 
	} 
	delta[k]=1;
//	printf("delta数组\n");
//	for(i=0;i<L.len;i++)
//	{
//		printf("%2d\n",delta[i]);
//	}
	for(i=0;i<=k;i++)
		Shell_insert(L,delta[i]);
}
//堆
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
	//把三个结点中最大的下标赋值给max
	if(max!=Heapify_pos)
	{
		swap(L,max,Heapify_pos);		//swap可能会破坏堆结构 
		Heapify(L,max);					//因为在build中调用时自下而上的,因此每swapy一次需要保证swap后子树max位置仍是堆结构	 
	}	
}
//建立堆 
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
//进行堆排序
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
//归并 
void merge(SqList *L,int left,int mid,int right)
{
	int LeftSize=mid-left;
	int RightSize=right-mid+1;
	int left_a[LeftSize];
	int right_a[RightSize];
	int i,j,k;
	//左边数组填充
	for(i=left;i<mid;i++)
	{
		left_a[i-left]=L->R[i];			//填左边数组
	}
	//右边数组填充
	for(i=mid;i<=right;i++)
	{
		right_a[i-mid]=L->R[i];
	}
	//合并到原来的数组中
	i=0;j=0;k=left;
	while(i<LeftSize && j<RightSize)	//没有顶到边界
	{
		if(left_a[i]<right_a[j])		//左边小放左边
		{
			L->R[k]=left_a[i];
			i++;k++;
		}
		else							//右边小放右边
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
//快速排序 
int findpos(SqList* L,int l,int h)
{
	int val=L->R[l];				//！！！注意这个地方不能写成0因为每一次循环 
	while(l<h)						//low比high小就一直操作 
	{
		while(l<h && L->R[h]>=val)		//正常情况直接移位即可,不许需要交换
		{
			h--;
		}
		L->R[l]=L->R[h];					//出来说明a[h]比val小了,执行交换
		while(l<h && L->R[l]<=val)		//同上
		{
			l++;
		}
		L->R[h]=L->R[l];	
	}							//循环结束后low==high 
	L->R[l]=val;
	return l;
} 
void QuickSort(SqList* L,int l,int h)
{
	int pos;
	if(l<h)
	{ 
		pos=findpos(L,l,h);					//把a数组根据pos 分成两段
		QuickSort(L,l,pos-1);				//左边一半 
		QuickSort(L,pos+1,h);				//右边一半 
	}
}

int main()
{
	int i;
	SqList L={{2,8,9,10,4,5,6,7}}; 
	QuickSort(&L,0,7); 
	printf("排序后:\n"); 
	for(i=0;i<=7;i++)
		printf("%d\n",L.R[i]);
	return 0;
}


