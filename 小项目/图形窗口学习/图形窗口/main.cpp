#define _CRT_SECURE_NO_WARNINGS

#include<graphics.h>
#include<stdio.h>
void outtext_int(int x,int y,const char* format,int num);


int main()
{
	initgraph(640, 480);
	//��
	setlinecolor(RED);	//�����滭������ͼ����Ч
	line(0, 0, 40, 240);
	//����
	rectangle(0, 240, 0 + 50, 240 + 60);	//�Խ���ȷ������
	for (int i = 0; i < 10; i++)
	{
		setfillcolor(LIGHTBLUE);
		fillrectangle(0 + i * 50, 240 , 50 + i * 50, 240 +60);	//�����겻��,�������i�й�
	}
	//����
	settextcolor(GREEN);
	for (int i = 0;i<100;i+=20)
	{
		cleardevice;
		settextstyle(i, 0, "Consolas");
		outtextxy(30, 30, "I love you");
		Sleep(100);
	}
	setbkmode(TRANSPARENT);		//ȥ����
	//���ּ����ַ��������
	outtext_int(300, 30, "�Ұ���!%d", 1314);
	getchar();
}

void outtext_int(int x, int y, const char* format, int num)
{
	char str[20] = "";
	sprintf(str, format, num);	//��numд��str��
	outtextxy(x, y, str);
}