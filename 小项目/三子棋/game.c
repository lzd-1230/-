#include"game.h"
void Game()
{
	char ret; 
	//存放棋盘信息
	char board[ROW][COLUMN] = {0};	
	//初始化棋盘位空格
	Init_Broad(board, ROW, COLUMN);//希望数组里面全是空格
	//打印棋盘
	Print_broad(board,ROW,COLUMN);
	//下棋
	while (1)
	{
		//玩家下棋
		Player_Move(board, ROW, COLUMN);
		Print_broad(board, ROW, COLUMN);
		//判断输赢
		ret = Is_Win(board, ROW, COLUMN);
		if (ret != 'C')
			break;
		//电脑下棋1
		Computer_Move(board, ROW, COLUMN);
		Print_broad(board, ROW, COLUMN);
		//判断输赢
		ret = Is_Win(board, ROW, COLUMN);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢");
	else
		printf("平局");
}

void Init_Broad(char board[ROW][COLUMN], int r, int c)	//初始化二维数组为空格
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < c; j++)
		{
			board[i][j] = ' ';
		}
}

void Print_broad(char board[][COLUMN], int r, int c)//打印棋盘
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			//1.打印行的内容
			printf(" %c ", board[i][j]);
			if (j < COLUMN - 1)	//最后一行不打印|
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				printf("---");
				if (j < COLUMN - 1)	//最后一行不打印|
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player_Move(char board[][COLUMN], int r, int c)
{
	int x, y;
	printf("玩家走>\n");
	while (1)
	{
		printf("请输入坐标:>");
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
				printf("该坐标已经被占用了\n");
			}
		} 
		else
		{
			printf("坐标非法,请重新输入\n");
		}
	}
}

void Computer_Move(char board[][COLUMN], int r, int c)
{
	int x, y;
	x = rand() % ROW;	//取模使随机数合法
	y = rand() % COLUMN;
	printf("电脑走:>\n");
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		else
		{
			x = rand() % ROW;	//取模使随机数合法
			y = rand() % COLUMN;
		}
	}
	
}
/*该函数要告诉我们4个状态
1.玩家赢了	-'*'
2.电脑赢了	-'#'
3.都没赢平局	-'P'
4.都没赢继续	-'C'
*/
char Is_Win(char board[][COLUMN], int r, int c)
{
	//横3
	for (int i = 0; i < r; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列的判断
	for (int i = 0; i < c; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
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