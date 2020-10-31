#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

//指针和数组
#if 0
int main()
{
	int n = 0x01020304;			//将每一个字节赋给一个char变量
	char c1, c2, c3, c4;
	char c[4] = { 1,2,3,4 };	//从低位->高位存储	
	
	//解引用的实质,根据首地址+类型读取数据
	int* p = (int*)&c;	//p存放了c的首地址,但类型被转化成了int型,也就是说一次可以拿出4个字节
	int m = *p;			//把p所指向的内存,以int的方式拿出(解引用)
/*
	//数组是从低位到高位存储的
	printf("数组中各位的地址\n");
	printf("&c[0]:%d\n", &c[0]);	
	printf("&c[1]:%d\n", &c[1]);
	printf("&c[2]:%d\n", &c[2]);
	printf("&c[3]:%d\n", &c[3]);

	//验证从低位到高位存储
	printf("0x的m:%x\n", m);	//04030201
	printf("m:%d\n", m);	//04030201对应的十进制数
*/
	//将int型的四个字节分配给4个char
	
	c1 = (n & 0xff000000) >> 24;		//n的最高位赋给c1
	c2 = (n & 0x00ff0000) >> 16;		
	c3 = (n & 0x0000ff00) >> 8;
	c4 = (n & 0x000000ff) >> 0;

	//把整数的四个字节分别存到char里面
	printf("%d %d %d %d\n", c1, c2, c3, c4);

	//地址就是整数
	//printf("&c1:%p\n", &c1);
	//四个char型变量之间相隔12个字节(编译器决定的)
	printf("&c1:%d\n", &c1);
	printf("&c2:%d\n", &c2);
	printf("&c3:%d\n", &c3);
	printf("&c4:%d\n", &c4);

}
#endif
//二级指针初级(解引用的分析)
#if 0
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;	//二级指针就是存放一级指针的首地址

	printf("pp经过一次解引用%d\n", *pp); //一次解引用拿到了p的内容也就是n的地址
	printf("%d\n", &n);
	printf("pp经过两次解引用%d\n", **pp);
}
#endif

//万能指针 void* 的指针
#if 0
int main()
{
/**************
原理
	1.可以指向任何类型的变量
	2.使用的时候(值)必须强制类型转换
用处(malloc的返回值)
	1.可以传任意类型的参数
	2.返回值可以赋值给任意类型
***************/
	int a = 1;
	void* p = &a;
	printf("%d\n", *(int*)p);
	printf("%d\n", *(char*)p);
}
#endif 

//一维动态内存申请
#if 0
int main()
{
//基础知识
/*
三个动态申请的函数
#define size_t unsigned int

	void* malloc(size_t size):返回首地址
		在计算机上申请一段内存把首地址给它!
	void* calloc(num,sizeof(size_t) )
		就是会自动初始化的malloc(默认初始化为0)
	void* realloc(void *p,size_t size)
		注意申请的内存数代表的是总内存!
内存释放
	1.释放后习惯置空
	2.程序关闭后自动释放
	3.不能重复释放!(可以通过断点调试出来)
	4.!一定要在原位置释放,如果需要进行指针++操作,则需要用另一个指针保存初始位置
*/
//malloc把指针转换成数组去用
/*
让用户输入char数组长度
	int n;
	scanf("%d", &n);
	char* p = (char*)malloc(sizeof(char) * (n + 1));	//用户眼中没有'\0'

	getchar();	//清楚缓冲区

	gets(p);
	puts(p);

	free(p);
	p = NULL;
	return 0;
*/
//calloc用法

int *p = (int*)calloc(3,sizeof(int));//默认初始化为0
for (int i = 0; i < 3; i++)
	p[i] = i;
for (int i = 0; i < 3; i++)
	printf("%d\t", p[i]);


//realloc的用法
/*
	int* p = (int*)malloc(sizeof(int) * 1);
	p[0] = 3;
	printf("%d\n", p);
	p = (int*)realloc(p, sizeof(int) * 3);	//这个三表示追加后总的长度是3!
	p[1] = 1;
	p[2] = 2;
	for (int i = 0; i < 3; i++) 
	{
		printf("%d\n", p[i]);
	}
	printf("%d\n", p);		//realloc是在原本的p指针后面的内存扩容to你设定的值
	//因此realloc中的参数大小一定要大于之前malloc中的!
*/
}
#endif
//二级指针和二维数组的关系 
#if 0
int main()
{
//二级指针的形成
	//pp存放若3个一级指针地址,即三个一维数组的首地址
	int** pp = (int**)malloc(sizeof(int*) * 3);//形成pp[3][?]
	//确定一维数组的大小
	for (int i = 0; i < 3; i++)
	{
 		pp[i] = (int*)malloc(sizeof(int) * 2);	//每一个一维数组是2个
	}
	//注意点:各个一维数组之间的内存不是连续的!

//二维数组的指针表示形式
/*
	令pp[i]=X[i],则pp[i][j] = X[j],则等于*(X+j)
	又因为X[i] == *(X+i)
	因此pp[i][j] == *(*(pp+i)+j) == *(pp[i] + j)
*/



}
#endif 
//二维数组的数组名(懵)
#if 0
int main()
{
	//正常指针的二维数组
	int arr[3][2] = { 7,2,3,4,5,6 };
	//int* *pt = arr;//error:二维数组名是特殊的指针!是一个数组指针,而int** pp是一维的指针数组
	int(*parr)[2] = arr;//数组指针:指向数组的指针 int(*)[2] 指向一个长度为2的数组

	//for(int i=0;i<3;i++)
	//	for (int j = 0; j < 2; j++)
	//	{
	//		printf("%d\n", arr[i][j]);
	//	}
	printf("sizeof(数组指针)is %d\n", sizeof(parr));	//一个指针当然是4

	printf("parr指向的数组名的结果是:%d\n", *parr);	//相当于输出某个数组名,应该地址
	//*parr == parr[0] == 第一行的地址

	printf("parr指向的数组的第一个元素是%d\n", *(parr[0]));	//第0行第二列
	//parr++ 表示移动一行
	parr++;
	printf("parr指向的数组的第一个元素是%d\n", *(parr[0]));	//第0行第二列
}
#endif 
//指针数组和数组指针
#if 1
/*
数组指针:int (*p)[2]	用来表示二维数组的
指针数组:int *p[2]	多用于操作多个字符串
*/
int main()
{
//指针数组:多个一级指针拼起来而已
	//表示二维数组
	int a=1;
	int b=2;
	int c=3;
	int* p[3] = { &a,&b,&c };	//存放多个一级指针

	//操作多个字符串
	//char* pc[3] = { "I do","love","you" };	
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%s ", pc[i]);
	//}
/*
数组指针
	1.操作二维数组
	2.动态内存产生二维数组
理解:
	指针的类型:int(*)[2] 
	指针所指向的类型 int[2]
*/
//  int (*q)[2] = (int*)malloc(sizeof(int));	error
	int(*q)[2] = (int(*)[2])malloc(sizeof(int[2])*2);
	int cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			q[i][j] = cnt++;
			printf("%3d\n", q[i][j]);
		}
	}
}
#endif 




