/*有问题 
//KMP算法
//有公共前后缀说明字串公共部分不用再比较了,固从子串的公共长度+1的位置比较 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>
//!首先主串中i要一直+,because无论模式串中到底对没对应,主串都是用下一位去比
//!而模式串不同,模式串出的下一位是要根据公共前后缀长度来决定

//短串第0个位置匹配失败,长串加一,短串还是0
//其他位置匹配失败,长串不变,短串回溯 

//用代码实现next表相当于自己和自己匹配(另一种计分机制) 
int* getNext(char * duan)
{
	int* next=(int* )malloc(strlen(duan)*sizeof(int));
	next[0] = -1;
	int c=0,d=-1;								//为什么next中自己和自己比d从-1开始?因为next[0]已经储存了-1,并且next[c]相当于用d存进next[d+1] 
	int len= strlen(duan);
	while (c< len-1)
	{
		if (d == -1 || duan[c] == duan[d])		//在比较j位置的时候其实在填写next[j+1]			 
		{
			++c;			//这里+1下面的c就相当于c+1了
			++d;			//这里+1下面的d就相当于d+1了 
			next[c] = d;				
		}							
		else
			d = next[d];			//和KMP匹配是一样的,回溯到最大长度后一位进行比较 
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
		//匹配的位置和蛮力算法是一样的 
		//!!j==-1	是防止进入死循环因为next[0]也是0,else后面赋值语句没有更新循环变量 
		if (j == -1 || t[i] == p[j]) 		//没有公共前后缀的时候用模式串时,放弃该值,指针后移,再重新用模式串第一个去比 
		{
			i++;							
       		j++;
		}
	 	else 
           		j = next[j];				//不匹配则要根据j挑出模式串中下一位登场嘉宾 
    	}

    if (j ==strlen(p))						//假设模式串能够走到结尾,说明都匹配上了 
       return i - strlen(p) ;						//返回i-j作为目标索引 
    else 									//j如果大于i的话那么就没找到匹配的 
       return -1;
}

 
int main()
{
	char a[20]="望江楼望江";
	char b[20]="望";
	int pos=KMP(a,b);
	printf("字符位置为%d",pos); 
}

 */ 
//自己写 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstring>
void print(char* duan,int len) 
{
	int i;
	for(i=0;i<len;i++)					//只要i<长串的最大长度,就还有希望匹配成功 
	{
		printf(" ");	
	}
	printf("%s\n",duan);
}

//得到短串的PMT数组(仅需要短串的信息) 
int *d(char* duan)						
{
	int len=strlen(duan);
	int *D=(int *)malloc(sizeof(int)*len);
	memset(D, 0,sizeof(int)*len);				//初始化为全为0,后面体现在D[0]==0; 
	int i=1,j=0;								//前后错位匹配 
	while(i<len)
	{
		if(duan[i]==duan[j])
		{
			D[i]=j+1;							//从下标0->i长度的短串拥有的最大公共前后缀长度 
			i++,j++;
		}
		//匹配失败则跟KMP的机制一样,i不懂j回溯 
		else
		{
			if(j>0)	j=D[j-1];					//否则我们让(模式串)回溯到应该回溯的位置 
			else 	i++;						//如果是在模式串第一位(下标为0)就失配,则i++ 
		}		
	}
	return D;
} 
void KMP(char* chang,char* duan)
{
	int *D=d(duan);								//获得PMT数组 
	int len_duan=strlen(duan);					 
	int len_chang=strlen(chang);
	int i=0;									//同一位置开始匹配 
	int j=0;
	while(i<len_chang)							//只要i<长串的最大长度,就还有希望匹配成功							
	{
		if(chang[i]==duan[j])					//如果匹配成功上下都移位 
		{
			i++;
			j++;
		}
		else if(j>0)							//失败且j>0,则模式串按照PMT表移位 
		{
			j=D[j-1];							//公共前后缀长度算的是j前面一个 
		}
		else if(j==0)	i++;					//如果第一位就失配,则长串++ 
		if(j==len_duan)							//如果在i还没到最长的时候j就走完了,则说明已经成功一次了 
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
