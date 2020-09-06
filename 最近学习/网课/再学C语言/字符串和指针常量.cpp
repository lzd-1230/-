#include <iostream>
#include<string.h> 
#include<stdbool.h>
//********小题目:满足条件的字串查找
#if 0
bool Is_OK(char* buff)
{
	if (buff[0] != buff[1] && buff[0] == buff[2] && buff[1] == buff[3])	
		return true;
	else
		return false;
}
int main()
{
	//字符串的输入
	//char* str1;	//野指针
	char str2[20] = { 0 };		//不初始化里面是垃圾数据 
	scanf("%s", &str2);
	printf("%s\n", str2);

//作业:输出字符串中符合"abab"格式的子串
	char buff[5] = {0};	//多一位给'\0'
//①有一个函数来获取字符串长度可以用库函数strlen(char* str)
	int len = strlen(str2);
	//②找到字串
	for (int i = 0; i < len - 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			buff[j] = str2[i + j];
			//③如果满足条件就输出
			if (Is_OK(buff))
				printf("满足条件的字串:%s\n", &buff);
		}
	}
}
#endif
//**********字符串库函数的实现
#if 0
int My_StrLen(const char* p)
{
	int n = 0;
	while (*p++)	//*p++表示
	{
		n++;
	}
	return n;
}
//由于字符串不能直接相互赋值因此需要复制函数
//不安全,左边的指针所带的内存一定要够大
void My_StrCpy(char* target,const char* str)
{
	int i = 0;
	/*
		自己的丑陋版本
		while (*str++)
		{
			target[i] = str[i];
			i++;
		}
	*/
	while (*target++ = *str++);	//while判断的是整个表达式的返回值(如果是\0就退出循环)
	return;
}
//字符串拼接函数
char* My_StrCat(char* target, const char* str)
{
	char* result = target;	//指向最终字符串的首地址
	//追加字符串走到'\0'的位置好让str的东西顶掉它后接着赋值
	while (*++target);	//但后++会走到'\0'后面一位,因此要用前++	
	while (*target++ = *str++);
	/*
	或者可以直接使用上面写好的COPY函数(但前提是你指针必须要到'\0'的位置)
	while (*++target);
	My_StrCpy(target, str);
	*/
	return result;
}
//字符串比较
int My_StrCmp(const char* str1, const char* str2)
{
	while (*str1 && *str2)//两个都不能为'\0'
	{
		if (*str1 > *str2)	 return 1;	//str1大就返回1
		if (*str1 < *str2)	return -1;	//str2大就返回1
		str1++; str2++;
	}

	if (*str1 != *str2)
	{
		if (*str1 != '\0')	return 1;	//str1还没有到'\0'
		else	return -1;		//str2还没有到'\0'
	}
	else
		return 0;	//0表示字符串相等
}

void Print_CMP(int r)
{
	if (r == 0)
		printf("两字符串相等");
	else if (r == 1)
		printf("str1大");
	else
		printf("str2大");
}
int main()
{
	//strlen strcopy strcmp
	char p[6];	//长度一定要比赋值过来的字符串多一位,\0占一位
	char p1[100]="hello ";

	printf("字符串长度为:%d\n",My_StrLen("nihao"));

	My_StrCpy(p, "nihao");	//会越界
	printf("%s\n", p);	

	//CPY就相当于字符串的赋值
	My_StrCpy(p1, My_StrCat(p1, "World"));
	printf("%s\n",p1);

	Print_CMP(My_StrCmp("iihao", "niha"));
	return 0;
}
#endif
//**********指针常量与常量指针
#if 1
int main()
{
	char buff[] = "hello";
	const char* p1 = &buff[1];

	//*p1 = buff[2];		error:p1所指向的变量的值是不能够再修改了!

	char* const p2 = &buff[1];
	//p2 = &buff[0];		error:p2这个指针变量本身不能变
}
#endif