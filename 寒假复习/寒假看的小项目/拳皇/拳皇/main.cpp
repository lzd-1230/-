/*******************************************************************
*��Ŀ���ƣ�ȭ��
*��Ŀ������ʵ�����ﶯ��
*������vs&easyx
********************************************************************/


/*
��ͼ��������
	1.����		�洢img
	2.��ʾ
	3.����
	4.�����ƶ�����putimgǰ����ı仯
*/




#pragma warning(disable:4996)
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//ԭͼ������ͼ�ֱ�23��,����ͼһ��
IMAGE img_x[23],img_y[23],bg;					//���ԭͼ������ͼһ����أ��Ϳ���ʹ����͸��
int x = 0, y = 200;
int Move = 0;
//����ͼƬ
void Initimg() 
{	//����23��ͼƬ								
	int i;
	char buff[128], buff_y[128];			//����ת��ͼƬ��·��
		//��sprintfת����ʽ					//��·�������ַ�����
	for (i = 0; i < 23; i++) {
		sprintf(buff, "images\\%d.bmp", i + 1);//��ͼƬ·���洢��buff��
		sprintf(buff_y, "images\\%dy.bmp", i + 1);
		loadimage(&img_x[i], buff);			//��ͼƬ���ص�img������
		loadimage(&img_y[i], buff_y);
	}
	//���ر���ͼ
	loadimage(&bg, "images\\background.jpg", 1000, 500);
}

//��������(��������ͼ)
void Draw()
{	//����ͼ
	putimage(x, y, &img_y[Move], SRCAND);
	//ԭͼ
	putimage(x, y, &img_x[Move], SRCPAINT);
	Move++;
	Sleep(50);
	//��ԭͼƬ
	if (Move == 6)
		Move = 0;
}

//�����ͷ�
void key() {
	Move = 6;
	while (Move < 23) {
		//��ͼ
		BeginBatchDraw();
		putimage(0, 0, &bg);		//����ͼ
		Draw();						//������
		Move++;
		Sleep(5);
		EndBatchDraw();		
	}
	Move = 0;						//�����ͷ�������ﻹԭ
}
int main() {
#if 0


	//1.��������
	initgraph(1000, 500);

	//����
	IMAGE img;							//�������
	//����
	loadimage(&img,"images\\background.jpg", 1000, 500);		

	//��ʾ
	putimage(0, 0, &img);
#endif 
	initgraph(1000, 500);		
	Initimg();
	while (true)
	{	
		BeginBatchDraw();
		putimage(0, 0, &bg);
		Draw();
		
		if(kbhit())
		{//�Ӽ��̻�ȡһ���ַ�
			switch (getch())
			{
			case'w':
			case'W':			
				y = y - 30;		//�����ƶ�10������
				break;
					
			case's':
			case'S':	
				y = y + 30;		//��
				break;

			case'a':			
			case'A':			
				x = x - 30;		//��
				break;

			case'd':
			case'D':			
				x = x + 30;		//��
				break;

			case'j':
			case'J':
				key();
			}

		}			

		EndBatchDraw();
		
	}
	
	system("pause");			//��ͣ����
	return 0;

}