#include"game.h"

void menu()	//打印菜单
{
	printf("**************************\n");
	printf("******** 1.play  0.exit****\n");
	printf("**************************\n");
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入数字:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			Game();		//游戏函数
			input = 0;	//一局游戏结束
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}