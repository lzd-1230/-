//�±��������
#include<stdio.h>
#include<malloc.h>		//������malloc���� 
#include<stdlib.h>    	//����exit���� 
struct Arr{
	int *pBase;
	int cnt;			//��ǰ��ЧԪ�ظ��� 
	int maxsize;		//������ 
}; 
void init_arr(struct Arr* pArr,int length);		//��Ҫ����ĳ��� 
bool append(struct Arr* pArr,int val);			//��Ҫ׷�ӵ�ֵ 
bool insert(struct Arr* pArr,int position,int val);
bool delet(struct Arr* pArr,int position);
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort(struct Arr* pArr);
void inverse(struct Arr* pArr);
void show_arr(struct Arr* pArr); 
//main ����     
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
//����Ĵ��� 
void init_arr(struct Arr* pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int)*length); 
	if(pArr->pBase==NULL)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1);											//��ֹ�������� 
	}
	else
	{
		pArr->maxsize=length;								//��󳤶Ȱ�������length 
		pArr->cnt=0;
	}
	return; 
}
//�ж������Ƿ�Ϊ�� 
bool is_empty(struct Arr* pArr)
{
	if(pArr->cnt==0)	return true;
	else return false;	
}
//������� 
void show_arr(struct Arr* pArr)
{
	int i; 
	if(is_empty(pArr))
	{
		printf("����Ϊ��!"); 
	}
	else
	{
		for(i=0;i<pArr->cnt;i++)
		{
			printf("��%d��Ԫ����%d\n",i+1,pArr->pBase[i]); 
		}
	} 
}
//�ж������Ƿ�����
bool is_full(struct Arr* pArr)
{
	if(pArr->cnt==pArr->maxsize)	return true;
	else return false;
}
//׷��Ԫ��
bool append(struct Arr* pArr,int val)
{
	int i;
//���� 
	if(is_full(pArr))
	{
		printf("��������,�޷�׷��\n");
		return false; 
	}	
//û�� 
	else
	{
		pArr->pBase[pArr->cnt]=val;
		pArr->cnt++;	 
	}
} 
//����Ԫ��
bool insert(struct Arr* pArr,int position,int val)
{
	int i;
	if(is_full(pArr))
	{
		printf("��������,�޷�����\n");
		exit(-1); 
	}		
	 
	if(position<1||position>pArr->cnt+1)
	{
		printf("��Чλ��");
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
//ɾ��Ԫ��
bool delet(struct Arr* pArr,int position)
{
	int val,i;
	if(is_empty(pArr))
	{
		printf("����Ϊ��,�޷�����ɾ������\n");
		return false;
	}
	if(position<1||position>pArr->cnt)
	{
		printf("ɾ����λ�ó���,ɾ��ʧ��\n");
		return false; 
	}
	val=pArr->pBase[position-1];
	for(i=position;i<pArr->cnt;i++)
	{
		pArr->pBase[i-1]=pArr->pBase[i];
	}
	pArr->cnt--;
	printf("ɾ���ɹ�,ɾ�����ǵ�%d��Ԫ��:%d\n",position,val);
	return true;
} 
//���鵹�� 
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
//����
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
 

