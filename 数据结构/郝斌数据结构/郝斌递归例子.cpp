#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
//阶乘的递归实现
/* 
long f(int );
int main()
{
	printf("%ld",f()) ;
	return 0;
} 
/*求val!只需要求(val-1)!再*val 
 	规模为n的问题的解决可以又规模n-1的问题的解决而解决!!! 
	规模在不停的递减 
long f(int val)
{
	if(val==1)
		return 1;
	else
		return f(val-1)*val;	//an=a(n-1)*n	左边求不了就用右边递推式 
}

*/ 
/* 
//1+2+3+4...+100的递归实现
long sum(int );
int main()
{
	printf("%d",sum(100));
	return 0;
}
long sum(int n)
{
	if(n==1)	return 1;
	else	return sum(n-1)+n;
}
*/
//哈哈的例子:自己调用自己必须有一个终止条件,不然就死递归 
/* 
int f(int n)
{
	if(n<3)
		printf("哈哈\n");		//只要输出了一次后就不再递归了 
	else
		n=f(n-1);				//n的值每一次调用就减小					
	return n;
} 
int main()
{
	int val;
	val=f(5);
	printf("%d",val);
	return 0;
}
*/ 

//汉诺塔
void hannuota(int ,char ,char,char);
int main()
{
	char ch1='a';
	char ch2='b';
	char ch3='c';
	int n;
	printf("请输入要移动盘子的个数:");
	scanf("%d",&n);
	hannuota(n,'a','b','c'); 
	return 0; 
} 
void hannuota(int n,char a,char b,char c)//位置1代表的是有盘子代移的柱子,位置2代表工具柱,位置3代表目标柱 
{
	/*
	如果是1个盘子
		直接将A柱子上的移到C即可
	如果盘子数大于1
		先将A上n-1个借助C移到B工具柱(此时A上仅剩一个用条件一)
		直接将A柱子上的移到C(此时C上的是最大的那个盘子,因此等效于空柱子,不受限制) 
		B上的n-2个盘子借助C移到A,然后A又很多了,递归调用自己 
	*/		 
	
	if(n==1)
	{
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n",n,a,c);
	}
	else
	{
		hannuota(n-1,a,c,b);			//把n-1块借助C放到B 
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n",n,a,c);	//直接把a上剩的那个给c造成规模的减小 
		hannuota(n-1,b,a,c);			//再考虑把b上那n-1个盘子借助A移到C
	} 
}
 
