#include"game.h"

void menu()	//��ӡ�˵�
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
		printf("����������:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			Game();		//��Ϸ����
			input = 0;	//һ����Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}