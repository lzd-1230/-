#include"f.h"
/*
了解结构体数组的基本操作:增删查改+排序
求和
*/

int main()
{
	my_struct list[SIZE];
	int len = 0;
	while (1)
	{
		Menu();
		Key_Down(list,&len);
		system("pause");//会在每一次循环的时候提示是下一轮
		system("cls");	//清屏
	}
}


/*
lzd 18 99 深圳
lzr 18 90 重庆
wy  18 90 重庆
*/