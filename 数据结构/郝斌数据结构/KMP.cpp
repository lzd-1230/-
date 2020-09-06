/*������ 
//KMP�㷨
//�й���ǰ��׺˵���ִ��������ֲ����ٱȽ���,�̴��Ӵ��Ĺ�������+1��λ�ñȽ� 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>
//!����������iҪһֱ+,because����ģʽ���е��׶�û��Ӧ,������������һλȥ��
//!��ģʽ����ͬ,ģʽ��������һλ��Ҫ���ݹ���ǰ��׺����������

//�̴���0��λ��ƥ��ʧ��,������һ,�̴�����0
//����λ��ƥ��ʧ��,��������,�̴����� 

//�ô���ʵ��next���൱���Լ����Լ�ƥ��(��һ�ּƷֻ���) 
int* getNext(char * duan)
{
	int* next=(int* )malloc(strlen(duan)*sizeof(int));
	next[0] = -1;
	int c=0,d=-1;								//Ϊʲônext���Լ����Լ���d��-1��ʼ?��Ϊnext[0]�Ѿ�������-1,����next[c]�൱����d���next[d+1] 
	int len= strlen(duan);
	while (c< len-1)
	{
		if (d == -1 || duan[c] == duan[d])		//�ڱȽ�jλ�õ�ʱ����ʵ����дnext[j+1]			 
		{
			++c;			//����+1�����c���൱��c+1��
			++d;			//����+1�����d���൱��d+1�� 
			next[c] = d;				
		}							
		else
			d = next[d];			//��KMPƥ����һ����,���ݵ���󳤶Ⱥ�һλ���бȽ� 
	}
	return next;
}

int KMP(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
	int * next=getNext(p);
	while (i < strlen(t) && j < strlen(p))
	{
		//ƥ���λ�ú������㷨��һ���� 
		//!!j==-1	�Ƿ�ֹ������ѭ����Ϊnext[0]Ҳ��0,else���渳ֵ���û�и���ѭ������ 
		if (j == -1 || t[i] == p[j]) 		//û�й���ǰ��׺��ʱ����ģʽ��ʱ,������ֵ,ָ�����,��������ģʽ����һ��ȥ�� 
		{
			i++;							
       		j++;
		}
	 	else 
           		j = next[j];				//��ƥ����Ҫ����j����ģʽ������һλ�ǳ��α� 
    	}

    if (j ==strlen(p))						//����ģʽ���ܹ��ߵ���β,˵����ƥ������ 
       return i - strlen(p) ;						//����i-j��ΪĿ������ 
    else 									//j�������i�Ļ���ô��û�ҵ�ƥ��� 
       return -1;
}

 
int main()
{
	char a[20]="����¥����";
	char b[20]="��";
	int pos=KMP(a,b);
	printf("�ַ�λ��Ϊ%d",pos); 
}

 */ 
//�Լ�д 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>
void print(char* duan,int len) 
{
	int i;
	for(i=0;i<len;i++)					//ֻҪi<��������󳤶�,�ͻ���ϣ��ƥ��ɹ� 
	{
		printf(" ");	
	}
	printf("%s\n",duan);
}

//�õ��̴���PMT����(����Ҫ�̴�����Ϣ) 
int *d(char* duan)						
{
	int len=strlen(duan);
	int *D=(int *)malloc(sizeof(int)*len);
	memset(D, 0,sizeof(int)*len);				//��ʼ��ΪȫΪ0,����������D[0]==0; 
	int i=1,j=0;								//ǰ���λƥ�� 
	while(i<len)
	{
		if(duan[i]==duan[j])
		{
			D[i]=j+1;							//���±�0->i���ȵĶ̴�ӵ�е���󹫹�ǰ��׺���� 
			i++,j++;
		}
		//ƥ��ʧ�����KMP�Ļ���һ��,i����j���� 
		else
		{
			if(j>0)	j=D[j-1];					//����������(ģʽ��)���ݵ�Ӧ�û��ݵ�λ�� 
			else 	i++;						//�������ģʽ����һλ(�±�Ϊ0)��ʧ��,��i++ 
		}		
	}
	return D;
} 
void KMP(char* chang,char* duan)
{
	int *D=d(duan);								//���PMT���� 
	int len_duan=strlen(duan);					 
	int len_chang=strlen(chang);
	int i=0;									//ͬһλ�ÿ�ʼƥ�� 
	int j=0;
	while(i<len_chang)							//ֻҪi<��������󳤶�,�ͻ���ϣ��ƥ��ɹ�							
	{
		if(chang[i]==duan[j])					//���ƥ��ɹ����¶���λ 
		{
			i++;
			j++;
		}
		else if(j>0)							//ʧ����j>0,��ģʽ������PMT����λ 
		{
			j=D[j-1];							//����ǰ��׺���������jǰ��һ�� 
		}
		else if(j==0)	i++;					//�����һλ��ʧ��,�򳤴�++ 
		if(j==len_duan)							//�����i��û�����ʱ��j��������,��˵���Ѿ��ɹ�һ���� 
		{
			print(duan,i-j);
		}
	}
}
int main()
{
	char a[24]={'a','a','a','a','b','a','b','a','b'};
	char b[20]={'a','b','a','b'};
	printf("%s\n",a); 
	KMP(a,b);
}
