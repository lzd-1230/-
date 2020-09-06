//郝斌链表代码
#include<stdio.h>
#include<malloc.h>		//包含了malloc函数 
#include<stdlib.h>    	//包含exit函数 
struct Arr{
	int *pBase;
	int cnt;			//当前有效元素个数 
	int maxsize;		//最大个数 
}; 
void init_arr(struct Arr* pArr,int length);		//需要数组的长度 
bool append(struct Arr* pArr,int val);			//需要追加的值 
bool insert(struct Arr* pArr,int position,int val);
bool delet(struct Arr* pArr,int position);
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort(struct Arr* pArr);
void inverse(struct Arr* pArr);
void show_arr(struct Arr* pArr); 
//main 函数     
int main(){
	struct Arr arr;
	init_arr(&arr,6);
	append(&arr,1);
	append(&arr,2);
	append(&arr,3);
	append(&arr,4);
	append(&arr,5);
	insert(&arr,6,6);
	inverse(&arr);
	show_arr(&arr);
	sort(&arr);
	show_arr(&arr); 
	return 0;
}
//数组的创建 
void init_arr(struct Arr* pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int)*length); 
	if(pArr->pBase==NULL)
	{
		printf("动态内存分配失败");
		exit(-1);											//终止整个程序 
	}
	else
	{
		pArr->maxsize=length;								//最大长度按给定的length 
		pArr->cnt=0;
	}
	return; 
}
//判断数组是否为空 
bool is_empty(struct Arr* pArr)
{
	if(pArr->cnt==0)	return true;
	else return false;	
}
//输出数组 
void show_arr(struct Arr* pArr)
{
	int i; 
	if(is_empty(pArr))
	{
		printf("数组为空!"); 
	}
	else
	{
		for(i=0;i<pArr->cnt;i++)
		{
			printf("第%d个元素是%d\n",i+1,pArr->pBase[i]); 
		}
	} 
}
//判断数组是否满了
bool is_full(struct Arr* pArr)
{
	if(pArr->cnt==pArr->maxsize)	return true;
	else return false;
}
//追加元素
bool append(struct Arr* pArr,int val)
{
	int i;
//满了 
	if(is_full(pArr))
	{
		printf("数组已满,无法追加\n");
		return false; 
	}	
//没满 
	else
	{
		pArr->pBase[pArr->cnt]=val;
		pArr->cnt++;	 
	}
} 
//插入元素
bool insert(struct Arr* pArr,int position,int val)
{
	int i;
	if(is_full(pArr))
	{
		printf("数组已满,无法插入\n");
		exit(-1); 
	}		
	 
	if(position<1||position>pArr->cnt+1)
	{
		printf("无效位置");
		exit(-1); 
	}
	for(i=pArr->cnt-1;i>=position-1;i--)
	{
		pArr->pBase[i+1]=pArr->pBase[i];
	}
	pArr->pBase[position-1]=val; 
	pArr->cnt++;
	return true;
} 
//删除元素
bool delet(struct Arr* pArr,int position)
{
	int val,i;
	if(is_empty(pArr))
	{
		printf("数组为空,无法进行删除操作\n");
		return false;
	}
	if(position<1||position>pArr->cnt)
	{
		printf("删除的位置出错,删除失败\n");
		return false; 
	}
	val=pArr->pBase[position-1];
	for(i=position;i<pArr->cnt;i++)
	{
		pArr->pBase[i-1]=pArr->pBase[i];
	}
	pArr->cnt--;
	printf("删除成功,删除的是第%d个元素:%d\n",position,val);
	return true;
} 
//数组倒置 
void inverse(struct Arr* pArr)
{
	int t,i,j;
	for(i=0,j=pArr->cnt-1;i<j;i++,j--)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
	}
	return;
}
//排序
void sort(struct Arr* pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt-1;i++)
	{
		for(j=i+1;j<pArr->cnt;j++)
		{
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				t=pArr->pBase[i];
				pArr->pBase[i]=pArr->pBase[j];
				pArr->pBase[j]=t;	
			}
		}
	}
} 
 

