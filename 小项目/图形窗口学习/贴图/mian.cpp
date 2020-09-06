/*
知识点:
	3.基本贴图
		3.1 声明一个存储图片的变量
			eg:IMAGE img;
		3.2	绑定图片和变量
			loadimage(&img,char* lujing);
		3.3图片的输出
			putimage(int x,int y,&img);3
		3.4图片和窗口大小不一致
			1.窗口改成图片大小
			2.让图片适应窗口(缩放)	在loadimage的时候加两个尺寸
		3.5图片坐标
			3.5.1定点取照片(只取图片的部分)
			3.5.2透明贴图
				通过掩码图和背景图的混合,达到透明贴图
				putimage(x,y,&IMAGE,SRCAND)
				putimage(x,y,&IMAGE,SRCPAINT)
	4.鼠标操作
		4.1	声明鼠标变量
		4.2	获取鼠标
		4.3	分类讨论消息信息
		
				
*/
#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
	initgraph(640, 480);

	IMAGE p;
	loadimage(&p, "P.png",640,480);		//图片太大,窗口显示不了
	//320,240表示取图片的一半------0,240,表示从该点开始往右下角取一半
	//putimage(0, 0,320,240, &p,0,240);

	//让图片满满地往下走!
	for (int y = 0; y < 240; y++)
	{
		cleardevice;
		putimage(0, 0, 640, y, &p, 0, 0);		//640表示横排扫描的测度
		Sleep(1);
	}
	//鼠标操作
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		setlinecolor(RED);
		switch (m.uMsg)
		{
			case WM_MOUSEMOVE:

				break;
			case WM_LBUTTONDOWN:
				if(sqrt((m.x - 100)* (m.x - 100)+(m.y-100)* (m.y - 100))<40)
					circle(m.x, m.y, 50);
				break;
			case WM_RBUTTONDOWN:
				rectangle(m.x - 5, m.y - 5, m.x + 10, m.y + 10);
				break;
			default:
					break;
		}
	}

	
	getchar();
	closegraph();
}