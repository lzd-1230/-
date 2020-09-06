#include"game.h"
void Game()
{
	char ret; 
	//���������Ϣ
	char board[ROW][COLUMN] = {0};	
	//��ʼ������λ�ո�
	Init_Broad(board, ROW, COLUMN);//ϣ����������ȫ�ǿո�
	//��ӡ����
	Print_broad(board,ROW,COLUMN);
	//����
	while (1)
	{
		//�������
		Player_Move(board, ROW, COLUMN);
		Print_broad(board, ROW, COLUMN);
		//�ж���Ӯ
		ret = Is_Win(board, ROW, COLUMN);
		if (ret != 'C')
			break;
		//��������1
		Computer_Move(board, ROW, COLUMN);
		Print_broad(board, ROW, COLUMN);
		//�ж���Ӯ
		ret = Is_Win(board, ROW, COLUMN);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ");
	else
		printf("ƽ��");
}

void Init_Broad(char board[ROW][COLUMN], int r, int c)	//��ʼ����ά����Ϊ�ո�
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < c; j++)
		{
			board[i][j] = ' ';
		}
}

void Print_broad(char board[][COLUMN], int r, int c)//��ӡ����
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			//1.��ӡ�е�����
			printf(" %c ", board[i][j]);
			if (j < COLUMN - 1)	//���һ�в���ӡ|
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				printf("---");
				if (j < COLUMN - 1)	//���һ�в���ӡ|
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player_Move(char board[][COLUMN], int r, int c)
{
	int x, y;
	printf("�����>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COLUMN)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������Ѿ���ռ����\n");
			}
		} 
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}
}

void Computer_Move(char board[][COLUMN], int r, int c)
{
	int x, y;
	x = rand() % ROW;	//ȡģʹ������Ϸ�
	y = rand() % COLUMN;
	printf("������:>\n");
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		else
		{
			x = rand() % ROW;	//ȡģʹ������Ϸ�
			y = rand() % COLUMN;
		}
	}
	
}
/*�ú���Ҫ��������4��״̬
1.���Ӯ��	-'*'
2.����Ӯ��	-'#'
3.��ûӮƽ��	-'P'
4.��ûӮ����	-'C'
*/
char Is_Win(char board[][COLUMN], int r, int c)
{
	//��3
	for (int i = 0; i < r; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�����е��ж�
	for (int i = 0; i < c; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//�ж��Ƿ�ƽ��
	if (1 == Is_Full(board, ROW, COLUMN))
		return 'P';
	else
		return 'C';
}

int Is_Full(char board[][COLUMN], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}