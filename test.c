#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void mune()
{
	printf("************************\n");
	printf("****1.play, 0.exit******\n");
	printf("************************\n");
}
//游戏的整个算法实现
void game()
{
	int ret = 0;
	//数组-存放走出的玩家信息
	char board[ROW][COL] = {0};//全部空格
	//初始化棋盘
	Initboard(board,ROW,COL);
	//打印棋盘
	Displayboard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		mune();
		printf("请输入：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}