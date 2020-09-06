#include<stdio.h>
#include<malloc.h>
//指针函数
/*
原理:
	定义:函数的参数或返回值中有指针(主体是函数)
	在函数中:
		要修改普通变量的值,要传一级指针
		要修改指针变量的值,要传二级指针
*/

//二维数组的传参问题
#if 0
void Print2D(int(*parr)[2]/*等效于int parr[][2]*/, int r, int c)	//传参的时候直接传二维数组名即可
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d\t", parr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int arry[3][2]={ 1,2,3,4,5,6 };
	Print2D(arry, 3, 2);
}

#endif 

//不能返回局部变量地址
#if 0
//正确版本
int* Return_Array(int* arry)
{
	return array;	//是正确的,这只是返回了局部变量!只不过它的内容是地址
}
//错误版本1
int* Return_Num()
{
	int a = 0;
	return &a;
}
//错误版本2
int* Return_Num(int num)
{
	int num = 0;
	return &num;
}
#endif 

//堆内存是允许返回的
#if 0
int* Retrun_Malloc()
{
	int* pn = (int*)malloc(sizeof(int));
	*pn = 123;
	return pn;
}
int main()
{
	int* p = Retrun_Malloc();
	printf("%d", p[0]);
}
#endif 

//函数指针基础
#if 0
/*
原理:
	定义:指向函数的指针
		!函数名其实就是函数指针,代表函数的首地址
	1.学会函数指针的定义
		1.1普通方式
			1.1.1用(*指针名)替换函数名
			1.1.2
		1.2typedef
	2.学会函数指针的使用
		2.1赋值操作
			直接用函数名去赋值(参数和返回值都一致的函数才可以)

		2.2学会通过函数指针去调用函数
			2.2.1不带*调用

			2.2.2带*调用
		3.函数指针充当返回值
			不能原始定义方法,得用typedef
*/
int Max(int a, int b)
{
	return a > b ? a : b;
}
void Print(int num)
{
	printf("%d", num);
}
int main()
{
	//定义语法1
	int(*p)(int, int) = NULL;
	void(*Print)(int) = NULL;

	//定义语法2typedef
	typedef int(*函数指针)(int, int);	//声明类型名叫"函数指针"
	函数指针 ph = NULL;					//和定义1中的p是一模一样的
	
	//赋值
	ph = Max;

	//调用
	printf("%d\n", ph(1, 2));		//直接把函数指针当函数使用
	printf("%d", (*ph)(1, 2));
}
#endif // 0

//函数指针充当函数参数
#if 1
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Sum(int a, int b)
{
	return a + b;
}

//以函数指针为参数(具体要做什么用一个函数指针表示,只要类型一致)
//函数指针定义方法:(返回值+(*指针名)(形参),形参)
void Print(int(*pFunction)(int, int), int a, int b)//调用的时候只用把函数名替换(*+指针名)即可
{
	printf("%d\n", pFunction(a, b));
}

int main()
{
	Print(Max, 1, 3);
	Print(Sum, 6, 6);
	//定义参数中带有函数指针的函数指针!方法很重要
	void (*p)(int(*)(int, int), int, int) =	Print;
	p(Max, 1, 3);
	p(Sum, 6, 6);
}

/*
面试题:
	以下指针是什么?
		void (*p)(int(*)(int,int),int ,int)
		1.用函数名替换(*p)-------->void Print(int(*)(int,int),int,int)
		2.补上名字void Print(int(*pFunction)(int,int),int a,int b)
*/

#endif // 1
/*
可能遇见函数指针的地方
	1.面试题,让你把复杂的函数指针还原成正常的函数
	2.函数指针当作函数参数
*/
