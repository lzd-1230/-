

#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
#include<stdlib.h> //itoa所需要的库函数
#include<stdio.h>
#include<stdio.h>
#include"fun.h"
#include<string.h>
struct MM {
	int i;
};


//冒泡排序测试
#if 0

	int a[10] = { 3,4,6,2,3,1,5,8,9,10 };
	int len = 10;
	int tmp;
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (a[i] <= a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
	}
#endif // 0
//字符串输入测试
#if 1
int main()
{
	char *str = "A man, a plan, a canal: Panama";
	//scanf("%s", str);
	printf("字符串长度为%d\n", strlen(str));
	printf("字符串所占内存为%d\n", sizeof(str));
	
}
#endif 
//itoa int 转 字符串
#if 0
int main()
{
	int num;
	char s[1100];
	cin >> num;
	_itoa(num, s, 10); // itoa(int,char,要转换的进制数)
	int q = strcmp(s, "hello");
	cout << q;
	return 0;

}
#endif // 1
//小学妹的素数问题
#if 0
int main()
{
	int m,n;
	for (m = 2; m < 51; m++)
	{
		for (n = 2; n < m; n++)
		{
			if (m % n == 0)
				break;
		}
		if (m == n)
			printf("%3d", m);
	}
}
#endif // 1

//红岩\b的问题
#if 0
int main()
{
	char* str[] = {"Well","\\\bcome","into","\5\2\0","the redrock"};
	/*for (int i = 0; i < 5; i++)
		printf("%s", str[i] + i);
		*/
	printf("\5\2\0");
}
#endif // 1

//字符串函数问题
#if 0
#include<stdio.h>
#include<string.h>
char* My_StrCat(char* des, const char* str);

int main()
{
	char str[] = "how are you";
	char des[50] = {0};
	puts(My_StrCat(des, str));
}

char* My_StrCat(char* des, const char* str)
{
	char* p = des;
	const char* q = str;

	while (*p)
	{
		p++;
	}

	while (*q)
	{
		*p = *q;
		q++;
		p++;
	}

	*p = '\0';
	return des;
}
#endif




