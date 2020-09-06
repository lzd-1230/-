/*******************************************************************
*项目名称：拳皇
*项目描述：实现人物动作
*环境：vs&easyx
********************************************************************/


/*
贴图三部曲：
	1.定义		存储img
	2.显示
	3.加载
	4.人物移动，靠putimg前坐标的变化
*/




#pragma warning(disable:4996)
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//原图和掩码图分别23张,背景图一张
IMAGE img_x[23],img_y[23],bg;					//存放原图和掩码图一起加载，就可以使背景透明
int x = 0, y = 200;
int Move = 0;
//加载图片
void Initimg() 
{	//加载23张图片								
	int i;
	char buff[128], buff_y[128];			//用来转换图片的路径
		//用sprintf转换格式					//将路径存入字符数组
	for (i = 0; i < 23; i++) {
		sprintf(buff, "images\\%d.bmp", i + 1);//将图片路径存储到buff中
		sprintf(buff_y, "images\\%dy.bmp", i + 1);
		loadimage(&img_x[i], buff);			//将图片加载到img数组中
		loadimage(&img_y[i], buff_y);
	}
	//加载背景图
	loadimage(&bg, "images\\background.jpg", 1000, 500);
}

//绘制人物(反复的贴图)
void Draw()
{	//掩码图
	putimage(x, y, &img_y[Move], SRCAND);
	//原图
	putimage(x, y, &img_x[Move], SRCPAINT);
	Move++;
	Sleep(50);
	//还原图片
	if (Move == 6)
		Move = 0;
}

//技能释放
void key() {
	Move = 6;
	while (Move < 23) {
		//贴图
		BeginBatchDraw();
		putimage(0, 0, &bg);		//背景图
		Draw();						//画人物
		Move++;
		Sleep(5);
		EndBatchDraw();		
	}
	Move = 0;						//技能释放完毕人物还原
}
int main() {
#if 0


	//1.创建窗口
	initgraph(1000, 500);

	//定义
	IMAGE img;							//定义变量
	//加载
	loadimage(&img,"images\\background.jpg", 1000, 500);		

	//显示
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
		{//从键盘获取一个字符
			switch (getch())
			{
			case'w':
			case'W':			
				y = y - 30;		//向上移动10个像素
				break;
					
			case's':
			case'S':	
				y = y + 30;		//下
				break;

			case'a':			
			case'A':			
				x = x - 30;		//左
				break;

			case'd':
			case'D':			
				x = x + 30;		//右
				break;

			case'j':
			case'J':
				key();
			}

		}			

		EndBatchDraw();
		
	}
	
	system("pause");			//悬停窗口
	return 0;

}