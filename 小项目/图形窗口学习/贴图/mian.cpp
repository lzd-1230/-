/*
֪ʶ��:
	3.������ͼ
		3.1 ����һ���洢ͼƬ�ı���
			eg:IMAGE img;
		3.2	��ͼƬ�ͱ���
			loadimage(&img,char* lujing);
		3.3ͼƬ�����
			putimage(int x,int y,&img);3
		3.4ͼƬ�ʹ��ڴ�С��һ��
			1.���ڸĳ�ͼƬ��С
			2.��ͼƬ��Ӧ����(����)	��loadimage��ʱ��������ߴ�
		3.5ͼƬ����
			3.5.1����ȡ��Ƭ(ֻȡͼƬ�Ĳ���)
			3.5.2͸����ͼ
				ͨ������ͼ�ͱ���ͼ�Ļ��,�ﵽ͸����ͼ
				putimage(x,y,&IMAGE,SRCAND)
				putimage(x,y,&IMAGE,SRCPAINT)
	4.������
		4.1	����������
		4.2	��ȡ���
		4.3	����������Ϣ��Ϣ
		
				
*/
#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
	initgraph(640, 480);

	IMAGE p;
	loadimage(&p, "P.png",640,480);		//ͼƬ̫��,������ʾ����
	//320,240��ʾȡͼƬ��һ��------0,240,��ʾ�Ӹõ㿪ʼ�����½�ȡһ��
	//putimage(0, 0,320,240, &p,0,240);

	//��ͼƬ������������!
	for (int y = 0; y < 240; y++)
	{
		cleardevice;
		putimage(0, 0, 640, y, &p, 0, 0);		//640��ʾ����ɨ��Ĳ��
		Sleep(1);
	}
	//������
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