#define _CRT_SECURE_NO_WARNINGS

#include<graphics.h>
#include<stdio.h>
void outtext_int(int x,int y,const char* format,int num);


int main()
{
	initgraph(640, 480);
	//线
	setlinecolor(RED);	//对下面画的所有图形生效
	line(0, 0, 40, 240);
	//矩形
	rectangle(0, 240, 0 + 50, 240 + 60);	//对角线确定矩形
	for (int i = 0; i < 10; i++)
	{
		setfillcolor(LIGHTBLUE);
		fillrectangle(0 + i * 50, 240 , 50 + i * 50, 240 +60);	//纵坐标不变,横坐标和i有关
	}
	//文字
	settextcolor(GREEN);
	for (int i = 0;i<100;i+=20)
	{
		cleardevice;
		settextstyle(i, 0, "Consolas");
		outtextxy(30, 30, "I love you");
		Sleep(100);
	}
	setbkmode(TRANSPARENT);		//去背景
	//数字加入字符串的输出
	outtext_int(300, 30, "我爱你!%d", 1314);
	getchar();
}

void outtext_int(int x, int y, const char* format, int num)
{
	char str[20] = "";
	sprintf(str, format, num);	//把num写入str中
	outtextxy(x, y, str);
}