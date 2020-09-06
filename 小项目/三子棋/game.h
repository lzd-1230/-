#pragma once
#define ROW 3
#define COLUMN 3
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Game();
void Init_Broad(char board[ROW][COLUMN], int r, int c);//初始化为空格
void Print_broad(char board[][COLUMN],int,int);	//打印棋盘
void Player_Move(char board[][COLUMN], int, int);
void Computer_Move(char board[][COLUMN], int, int);
char Is_Win(char board[][COLUMN], int, int);
int Is_Full(char board[][COLUMN], int, int);