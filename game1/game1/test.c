//测试游戏
#define _CRT_SECURE_NO_WARNINGS 1

#include "game1.h"

void menu()
{
	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}
void game()
{
	char ret = 0;//棋盘信息
	char board[ROW][COL] = { 0 };//存放棋盘信息
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//玩家下棋
		//玩家是否赢
		ret = IsWin();
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//电脑下棋
		//电脑是否赢
		ret = IsWin();
		if (ret != 'C')
		{
			break;
		}
	}

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
} 