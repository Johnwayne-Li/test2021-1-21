//������Ϸ
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
	char ret = 0;//������Ϣ
	char board[ROW][COL] = { 0 };//���������Ϣ
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board,ROW,COL);//��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//�������
		//����Ƿ�Ӯ
		ret = IsWin();
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//��������
		//�����Ƿ�Ӯ
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
		printf("��ѡ��:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
} 