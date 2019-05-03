#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<memory.h>

// board information
#define BOARD_SIZE 12
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// bool
typedef int BOOL;
#define TRUE 1
#define FALSE 0

// option
typedef int OPTION;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7

#define MAX_BYTE 10000

#define START "START"
#define PLACE "PLACE"
#define TURN  "TURN"
#define END   "END"
#define now 4


struct Command
{
	int x;
	int y;
	OPTION option;
};

char buffer[MAX_BYTE] = { 0 };
char board[BOARD_SIZE][BOARD_SIZE] = { 0 };

int me_flag;
int other_flag;

const int DIR[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

void debug(const char *str) {
	printf("DEBUG %s\n", str);
	fflush(stdout);
}

void printBoard() {
	char visual_board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == EMPTY) {
				visual_board[i][j] = '.';
			}
			else if (board[i][j] == BLACK) {
				visual_board[i][j] = 'O';
			}
			else if (board[i][j] == WHITE) {
				visual_board[i][j] = 'X';
			}
		}
		printf("%s\n", visual_board[i]);
	}
}

BOOL isInBound(int x, int y) {
	return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

/**
* YOUR CODE BEGIN
* 你的代码开始
*/

/**
* You can define your own struct and variable here
* 你可以在这里定义你自己的结构体和变量
*/
char myboard[now + 2][BOARD_SIZE + 1][BOARD_SIZE + 1] = { '\0' };

/**
* 你可以在这里初始化你的AI
*/

void initAI(int me) {

}

int evaluate()
{
	int value = 0;
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (myboard[now - 1][x][y] == me_flag) value += 10000;
			//夹（对方夹我方）

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 1][y - 1] == other_flag &&myboard[now - 1][x + 1][y + 1] == EMPTY && (myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y + 2] == other_flag || myboard[now - 1][x + 1][y + 2] == other_flag || myboard[now - 1][x + 2][y + 2] == other_flag || myboard[now - 1][x + 2][y + 1] == other_flag || myboard[now - 1][x + 2][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag)) value -= 1000;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 1][y + 1] == other_flag &&myboard[now - 1][x + 1][y - 1] == EMPTY && (myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x + 2][y] == other_flag || myboard[now - 1][x + 2][y - 1] == other_flag || myboard[now - 1][x + 2][y - 2] == other_flag || myboard[now - 1][x + 1][y - 2] == other_flag || myboard[now - 1][x][y - 2] == other_flag)) value -= 1000;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 1][y + 1] == other_flag &&myboard[now - 1][x - 1][y - 1] == EMPTY && (myboard[now - 1][x - 2][y - 1] == other_flag || myboard[now - 1][x - 2][y] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x][y - 2] == other_flag || myboard[now - 1][x - 1][y - 2] == other_flag || myboard[now - 1][x - 2][y - 2] == other_flag)) value -= 1000;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 1][y - 1] == other_flag &&myboard[now - 1][x - 1][y + 1] == EMPTY && (myboard[now - 1][x - 2][y + 1] == other_flag || myboard[now - 1][x - 2][y + 2] == other_flag || myboard[now - 1][x - 1][y + 2] == other_flag || myboard[now - 1][x][y + 2] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x - 2][y] == other_flag)) value -= 1000;//敌子与我一子成斜线

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 1][y] == other_flag && myboard[now - 1][x + 1][y] == EMPTY && (myboard[now - 1][x + 1][y + 1] == other_flag || myboard[now - 1][x + 2][y + 1] == other_flag || myboard[now - 1][x + 2][y] == other_flag || myboard[now - 1][x + 2][y - 1] == other_flag || myboard[now - 1][x + 1][y - 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x][y + 1] == other_flag)) value -= 800;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x][y + 1] == other_flag && myboard[now - 1][x][y - 1] == EMPTY && (myboard[now - 1][x - 1][y - 1] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x + 1][y - 1] == other_flag || myboard[now - 1][x + 1][y - 2] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag)) value -= 800;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 1][y] == other_flag && myboard[now - 1][x - 1][y] == EMPTY && (myboard[now - 1][x - 2][y] == other_flag || myboard[now - 1][x - 2][y + 1] == other_flag || myboard[now - 1][x - 1][y + 1] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x - 1][y - 1] == other_flag || myboard[now - 1][x - 2][y - 1] == other_flag)) value -= 800;//
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x][y - 1] == other_flag && myboard[now - 1][x][y + 1] == EMPTY && (myboard[now - 1][x - 1][y + 1] == other_flag || myboard[now - 1][x - 1][y + 2] == other_flag || myboard[now - 1][x][y + 2] == other_flag || myboard[now - 1][x + 1][y + 2] == other_flag || myboard[now - 1][x + 1][y + 1] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x - 1][y] == other_flag)) value -= 800;//敌子与我一子成直线


			//挑（对方挑我方）

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 2][y + 2] == me_flag&&myboard[now - 1][x + 1][y + 1] == EMPTY && (myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y + 2] == other_flag || myboard[now - 1][x + 1][y + 2] == other_flag || myboard[now - 1][x + 2][y + 1] == other_flag || myboard[now - 1][x + 2][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag)) value -= 2000;
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 2][y - 2] == me_flag&&myboard[now - 1][x - 1][y - 1] == EMPTY && (myboard[now - 1][x - 2][y - 1] == other_flag || myboard[now - 1][x - 2][y] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x][y - 2] == other_flag || myboard[now - 1][x - 1][y - 2] == other_flag)) value -= 2000;

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 2][y] == me_flag&&myboard[now - 1][x + 1][y] == EMPTY && (myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x + 1][y + 1] == other_flag || myboard[now - 1][x + 2][y + 1] == other_flag || myboard[now - 1][x + 2][y - 1] == other_flag || myboard[now - 1][x + 1][y - 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag)) value -= 1500;
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 2][y] == me_flag&&myboard[now - 1][x - 1][y] == EMPTY && (myboard[now - 1][x - 2][y + 1] == other_flag || myboard[now - 1][x - 1][y + 1] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x - 1][y - 1] == other_flag || myboard[now - 1][x - 2][y - 1] == other_flag)) value -= 1500;

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x + 2][y - 2] == me_flag&&myboard[now - 1][x + 1][y - 1] == EMPTY && (myboard[now - 1][x][y - 1] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x + 2][y] == other_flag || myboard[now - 1][x + 2][y - 1] == other_flag || myboard[now - 1][x + 1][y - 2] == other_flag || myboard[now - 1][x][y - 2] == other_flag)) value -= 2000;
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x - 2][y + 2] == me_flag&&myboard[now - 1][x - 1][y + 1] == EMPTY && (myboard[now - 1][x - 2][y + 1] == other_flag || myboard[now - 1][x - 1][y + 2] == other_flag || myboard[now - 1][x][y + 2] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x - 2][y] == other_flag)) value -= 2000;

			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x][y + 2] == me_flag&&myboard[now - 1][x][y + 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x - 1][y + 1] == other_flag || myboard[now - 1][x - 1][y + 2] == other_flag || myboard[now - 1][x + 1][y + 2] == other_flag || myboard[now - 1][x + 1][y + 1] == other_flag || myboard[now - 1][x + 1][y] == other_flag)) value -= 1500;
			if (myboard[now - 1][x][y] == me_flag&&myboard[now - 1][x][y - 2] == me_flag&&myboard[now - 1][x][y - 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x - 1][y - 1] == other_flag || myboard[now - 1][x - 1][y - 2] == other_flag || myboard[now - 1][x + 1][y - 2] == other_flag || myboard[now - 1][x + 1][y - 1] == other_flag || myboard[now - 1][x + 1][y] == other_flag)) value -= 1500;


			//夹（我方夹敌方）

			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 1][y - 1] == me_flag &&myboard[now - 1][x + 1][y + 1] == EMPTY && (myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x][y + 2] == me_flag || myboard[now - 1][x + 1][y + 2] == me_flag || myboard[now - 1][x + 2][y + 2] == me_flag || myboard[now - 1][x + 2][y + 1] == me_flag || myboard[now - 1][x + 2][y] == me_flag || myboard[now - 1][x + 1][y] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 1][y + 1] == me_flag &&myboard[now - 1][x + 1][y - 1] == EMPTY && (myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x + 1][y] == me_flag || myboard[now - 1][x + 2][y] == me_flag || myboard[now - 1][x + 2][y - 1] == me_flag || myboard[now - 1][x + 2][y - 2] == me_flag || myboard[now - 1][x + 1][y - 2] == me_flag || myboard[now - 1][x][y - 2] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 1][y + 1] == me_flag &&myboard[now - 1][x - 1][y - 1] == EMPTY && (myboard[now - 1][x - 2][y - 1] == me_flag || myboard[now - 1][x - 2][y] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x][y - 2] == me_flag || myboard[now - 1][x - 1][y - 2] == me_flag || myboard[now - 1][x - 2][y - 2] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 1][y - 1] == me_flag &&myboard[now - 1][x - 1][y + 1] == EMPTY && (myboard[now - 1][x - 2][y + 1] == me_flag || myboard[now - 1][x - 2][y + 2] == me_flag || myboard[now - 1][x - 1][y + 2] == me_flag || myboard[now - 1][x][y + 2] == me_flag || myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x - 2][y] == me_flag)) value += 800;//敌子与我一子成斜线

			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 1][y] == me_flag && myboard[now - 1][x + 1][y] == EMPTY && (myboard[now - 1][x + 1][y + 1] == me_flag || myboard[now - 1][x + 2][y + 1] == me_flag || myboard[now - 1][x + 2][y] == me_flag || myboard[now - 1][x + 2][y - 1] == me_flag || myboard[now - 1][x + 1][y - 1] == me_flag || myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x][y + 1] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x][y + 1] == me_flag && myboard[now - 1][x][y - 1] == EMPTY && (myboard[now - 1][x - 1][y - 1] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x + 1][y] == me_flag || myboard[now - 1][x + 1][y - 1] == me_flag || myboard[now - 1][x + 1][y - 2] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x + 1][y] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 1][y] == me_flag && myboard[now - 1][x - 1][y] == EMPTY && (myboard[now - 1][x - 2][y] == me_flag || myboard[now - 1][x - 2][y + 1] == me_flag || myboard[now - 1][x - 1][y + 1] == me_flag || myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x - 1][y - 1] == me_flag || myboard[now - 1][x - 2][y - 1] == me_flag)) value += 800;//
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x][y - 1] == me_flag && myboard[now - 1][x][y + 1] == EMPTY && (myboard[now - 1][x - 1][y + 1] == me_flag || myboard[now - 1][x - 1][y + 2] == me_flag || myboard[now - 1][x][y + 2] == me_flag || myboard[now - 1][x + 1][y + 2] == me_flag || myboard[now - 1][x + 1][y + 1] == me_flag || myboard[now - 1][x + 1][y] == me_flag || myboard[now - 1][x - 1][y] == me_flag)) value += 800;//敌子与我一子成直线


			//挑（我方挑对方）
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 2][y + 2] == other_flag&&myboard[now - 1][x + 1][y + 1] == EMPTY && (myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x][y + 2] == me_flag || myboard[now - 1][x + 1][y + 2] == me_flag || myboard[now - 1][x + 2][y + 1] == me_flag || myboard[now - 1][x + 2][y] == me_flag || myboard[now - 1][x + 1][y] == me_flag)) value += 1500;
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 2][y - 2] == other_flag&&myboard[now - 1][x - 1][y - 1] == EMPTY && (myboard[now - 1][x - 2][y - 1] == me_flag || myboard[now - 1][x - 2][y] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x][y - 2] == me_flag || myboard[now - 1][x - 1][y - 2] == me_flag)) value += 1500;

			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 2][y] == other_flag&&myboard[now - 1][x + 1][y] == EMPTY && (myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x + 1][y + 1] == me_flag || myboard[now - 1][x + 2][y + 1] == me_flag || myboard[now - 1][x + 2][y - 1] == me_flag || myboard[now - 1][x + 1][y - 1] == me_flag || myboard[now - 1][x][y - 1] == me_flag)) value += 1500;
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 2][y] == other_flag&&myboard[now - 1][x - 1][y] == EMPTY && (myboard[now - 1][x - 2][y + 1] == me_flag || myboard[now - 1][x - 1][y + 1] == me_flag || myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x - 1][y - 1] == me_flag || myboard[now - 1][x - 2][y - 1] == me_flag)) value += 1500;

			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x + 2][y - 2] == other_flag&&myboard[now - 1][x + 1][y - 1] == EMPTY && (myboard[now - 1][x][y - 1] == me_flag || myboard[now - 1][x + 1][y] == me_flag || myboard[now - 1][x + 2][y] == me_flag || myboard[now - 1][x + 2][y - 1] == me_flag || myboard[now - 1][x + 1][y - 2] == me_flag || myboard[now - 1][x][y - 2] == me_flag)) value += 1500;
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x - 2][y + 2] == other_flag&&myboard[now - 1][x - 1][y + 1] == EMPTY && (myboard[now - 1][x - 2][y + 1] == me_flag || myboard[now - 1][x - 1][y + 2] == me_flag || myboard[now - 1][x][y + 2] == me_flag || myboard[now - 1][x][y + 1] == me_flag || myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x - 2][y] == me_flag)) value += 1500;

			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x][y + 2] == other_flag&&myboard[now - 1][x][y + 1] == EMPTY && (myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x - 1][y + 1] == me_flag || myboard[now - 1][x - 1][y + 2] == me_flag || myboard[now - 1][x + 1][y + 2] == me_flag || myboard[now - 1][x + 1][y + 1] == me_flag || myboard[now - 1][x + 1][y] == me_flag)) value += 1500;
			if (myboard[now - 1][x][y] == other_flag&&myboard[now - 1][x][y - 2] == other_flag&&myboard[now - 1][x][y - 1] == EMPTY && (myboard[now - 1][x - 1][y] == me_flag || myboard[now - 1][x - 1][y - 1] == me_flag || myboard[now - 1][x - 1][y - 2] == me_flag || myboard[now - 1][x + 1][y - 2] == me_flag || myboard[now - 1][x + 1][y - 1] == me_flag || myboard[now - 1][x + 1][y] == me_flag)) value += 1500;


			if (myboard[now - 1][4][4] == me_flag) value += 100;
			if (myboard[now - 1][4][6] == me_flag) value += 100;
			if (myboard[now - 1][4][5] == me_flag) value += 100;
			if (myboard[now - 1][5][4] == me_flag) value += 100;
			if (myboard[now - 1][5][5] == me_flag) value += 300;
			if (myboard[now - 1][5][6] == me_flag) value += 100;
			if (myboard[now - 1][6][4] == me_flag) value += 100;
			if (myboard[now - 1][6][3] == me_flag) value += 30;
			if (myboard[now - 1][6][5] == me_flag) value += 100;
			if (myboard[now - 1][6][6] == me_flag) value += 100;
			if (myboard[now - 1][7][4] == me_flag) value += 30;
			if (myboard[now - 1][7][5] == me_flag) value += 30;
			if (myboard[now - 1][7][6] == me_flag) value += 30;
			if (myboard[now - 1][5][3] == me_flag) value += 30;
			if (myboard[now - 1][5][7] == me_flag) value += 30;




			//特殊情况
			if (myboard[now - 1][x][y] == me_flag)
			{

				if (myboard[now - 1][x - 3][y + 3] == me_flag&&myboard[now - 1][x - 2][y + 2] == other_flag&&myboard[now - 1][x - 1][y + 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag) && myboard[now - 1][x + 1][y - 1] == me_flag) value -= 1100;
				if (myboard[now - 1][x + 3][y + 3] == me_flag&&myboard[now - 1][x + 2][y + 2] == other_flag&&myboard[now - 1][x + 1][y + 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag) && myboard[now - 1][x - 1][y - 1] == me_flag) value -= 1100;
				if (myboard[now - 1][x - 3][y - 3] == me_flag&&myboard[now - 1][x - 2][y - 2] == other_flag&&myboard[now - 1][x - 1][y - 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y-1] == other_flag) && myboard[now - 1][x + 1][y + 1] == me_flag) value -= 1100;
				if (myboard[now - 1][x + 3][y - 3] == me_flag&&myboard[now - 1][x + 2][y - 2] == other_flag&&myboard[now - 1][x + 1][y - 1] == EMPTY && (myboard[now - 1][x - 1][y] == other_flag || myboard[now - 1][x + 1][y] == other_flag || myboard[now - 1][x][y + 1] == other_flag || myboard[now - 1][x][y - 1] == other_flag) && myboard[now - 1][x - 1][y + 1] == me_flag) value -= 1100;
				
				
				if (myboard[now - 1][x + 1][y] == me_flag) value += 50;
				if (myboard[now - 1][x][y + 1] == me_flag) value += 50;
				if (myboard[now - 1][x + 1][y + 1] == me_flag) value += 50;
				if (myboard[now - 1][x - 1][y] == me_flag) value += 50;
				if (myboard[now - 1][x - 1][y - 1] == me_flag) value += 50;
				if (myboard[now - 1][x + 1][y - 1] == me_flag) value += 50;
				if (myboard[now - 1][x - 1][y + 1] == me_flag) value += 50;
				if (myboard[now - 1][x][y + 1] == me_flag) value += 50;

				if (myboard[now - 1][x + 1][y + 1]==me_flag && myboard[now-1][x - 1][y - 1] == me_flag) value -= 400;

				if (myboard[now - 1][x - 1][y + 1] == me_flag && myboard[now - 1][x + 1][y - 1] == me_flag) value -= 400;
				

				if (myboard[now - 1][x + 1][y] == EMPTY&&myboard[now - 1][x - 1][y] == EMPTY&&myboard[now - 1][x - 1][y + 1] == EMPTY&&myboard[now - 1][x - 1][y - 1] == EMPTY&&myboard[now - 1][x + 1][y - 1] == EMPTY&&myboard[now - 1][x + 1][y + 1] == EMPTY&&myboard[now - 1][x][y - 1] == EMPTY&&myboard[now - 1][x][y + 1] == EMPTY) value -= 400;


				if (myboard[now - 1][x + 1][y + 1] == other_flag&&myboard[now - 1][x - 2][y - 2] == other_flag&&myboard[now - 1][x + 1][y - 1] == me_flag&&myboard[now - 1][x + 3][y - 3] == other_flag) value -= 1400;


			}


		}
	}


	return value;
}


void myplace(int x, int y, OPTION option, int cur_flag, int NOW) {

	if (myboard[NOW][x][y] != cur_flag) {
		return;
	}
	int new_x = x + DIR[option][0];
	int new_y = y + DIR[option][1];
	// 移动之后的位置超出边界, 或者不是空地
	if (!isInBound(new_x, new_y) || myboard[NOW][new_x][new_y] != EMPTY) {
		return;
	}
	myboard[NOW][x][y] = EMPTY;
	myboard[NOW][new_x][new_y] = cur_flag;

	int cur_other_flag = 3 - cur_flag;

	// 挑
	int intervention_dir[4][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, -1 } };
	for (int i = 0; i < 4; i++) {
		int x1 = new_x + intervention_dir[i][0];
		int y1 = new_y + intervention_dir[i][1];
		int x2 = new_x - intervention_dir[i][0];
		int y2 = new_y - intervention_dir[i][1];
		if (isInBound(x1, y1) && isInBound(x2, y2) && myboard[NOW][x1][y1] == cur_other_flag &&myboard[NOW][x2][y2] == cur_other_flag)
		{
			myboard[NOW][x1][y1] = cur_flag;
			myboard[NOW][x2][y2] = cur_flag;
		}
	}

	// 夹
	int custodian_dir[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
	for (int i = 0; i < 8; i++) {
		int x1 = new_x + custodian_dir[i][0];
		int y1 = new_y + custodian_dir[i][1];
		int x2 = new_x + custodian_dir[i][0] * 2;
		int y2 = new_y + custodian_dir[i][1] * 2;
		if (isInBound(x1, y1) && isInBound(x2, y2) && myboard[NOW][x2][y2] == cur_flag && myboard[NOW][x1][y1] == cur_other_flag)
		{
			myboard[NOW][x1][y1] = cur_flag;
		}
	}
}



void initBoard()
{
	int NOW;
	for (NOW = 0; NOW < now; NOW++)
	{
		memset(myboard[NOW], 0, sizeof(myboard[NOW]));
		for (int i = 0; i < 3; i++)
		{
			myboard[NOW][2][2 + i] = WHITE;
			myboard[NOW][6][6 + i] = WHITE;
			myboard[NOW][5][3 + i] = BLACK;
			myboard[NOW][9][7 + i] = BLACK;
		}
		for (int j = 0; j < 2; j++)
		{
			myboard[NOW][8 + j][2] = WHITE;
			myboard[NOW][2 + j][9] = BLACK;
		}
	}
}


//后手较强
//先手智障，应该分类再写一个
struct Command MYAI()
{
	struct Command command = { 0, 0, 0 };
	int tmp4 = -10000000, X3 = 0, Y3 = 0, K3 = 0;
	int X, Y, K;
	for (int x1 = 0; x1 < BOARD_SIZE; x1++)
	{
		for (int y1 = 0; y1 < BOARD_SIZE; y1++)
		{
			if (board[x1][y1] != me_flag)  continue;
			for (int k1 = 0; k1<8; k1++)
			{
				if (board[x1 + DIR[k1][0]][y1 + DIR[k1][1]] != EMPTY) continue;
				if (x1 + DIR[k1][0]>11 || x1 + DIR[k1][0]<0 || y1 + DIR[k1][1]>11 || y1 + DIR[k1][1] < 0) continue;
				myplace(x1, y1, k1, me_flag, 0);//
				myplace(x1, y1, k1, me_flag, 1);//
				myplace(x1, y1, k1, me_flag, 2);//
				myplace(x1, y1, k1, me_flag, 3);
				//第一步
				int tmp3 = 10000000, X2 = 0, Y2 = 0, K2 = 0, bool3 = 0;
				for (int x2 = 0; x2 < BOARD_SIZE; x2++)
				{
					for (int y2 = 0; y2 < BOARD_SIZE; y2++)
					{
						if (myboard[0][x2][y2] != other_flag)  continue;
						for (int k2 = 0; k2 < 8; k2++)
						{
							if (myboard[0][x2 + DIR[k2][0]][y2 + DIR[k2][1]] != EMPTY) continue;
							if (x2 + DIR[k2][0]>11 || x2 + DIR[k2][0]<0 || y2 + DIR[k2][1]>11 || y2 + DIR[k2][1] < 0) continue;
							myplace(x2, y2, k2, other_flag, 1);
							myplace(x2, y2, k2, other_flag, 2);//
							myplace(x2, y2, k2, other_flag, 3);//第二步

							int  tmp2 = -10000000, X1 = 0, Y1 = 0, K1 = 0, bool2 = 0;
							int tmp0;

							for (int x3 = 0; x3 < BOARD_SIZE; x3++)
							{
								for (int y3 = 0; y3 < BOARD_SIZE; y3++)
								{
									if (myboard[1][x3][y3] != me_flag)  continue;
									for (int k3 = 0; k3 < 8; k3++)
									{
										if (myboard[1][x3 + DIR[k3][0]][y3 + DIR[k3][1]] != EMPTY) continue;
										if (x3 + DIR[k3][0]>11 || x3 + DIR[k3][0]<0 || y3 + DIR[k3][1]>11 || y3 + DIR[k3][1] < 0) continue;
										myplace(x3, y3, k3, me_flag, 2);//
										myplace(x3, y3, k3, me_flag, 3);//第三步

										int tmp1 = 10000000, bool1 = 0;

										for (int x4 = 0; x4 < BOARD_SIZE; x4++)
										{
											for (int y4 = 0; y4 < BOARD_SIZE; y4++)
											{
												if (myboard[2][x4][y4] != other_flag)  continue;
												for (int k4 = 0; k4 < 8; k4++)
												{
													if (myboard[2][x4 + DIR[k4][0]][y4 + DIR[k4][1]] != EMPTY) continue;
													if (x4 + DIR[k4][0]>11 || x4 + DIR[k4][0]<0 || y4 + DIR[k4][1]>11 || y4 + DIR[k4][1] < 0) continue;
													myplace(x4, y4, k4, other_flag, 3); // 第四步
													tmp0 = evaluate();
													if (tmp0 < tmp1)
													{
														tmp1 = tmp0;
													}

													for (int p = x4 - 3; p < x4 + 3; p++)
													{
														for (int q = y4 - 3; q < y4 + 3; q++)
														{
															myboard[3][p][q] = myboard[2][p][q];
														}
													}
													//恢复棋盘
													if (tmp0 <= tmp2) bool1 = 1;
													if (bool1) break;
												}
												if (bool1) break;
											}
											if (bool1) break;
										}

										for (int p = 0; p <12; p++)
										{
											for (int q = 0; q < 12; q++)
											{
												myboard[2][p][q] = myboard[1][p][q];

											}
										}

										if (tmp1 > tmp2)//传该层得分
										{
											tmp2 = tmp1;
											X1 = x1;
											Y1 = y1;
											K1 = k1;
										}
										if (tmp1 >= tmp3) bool2 = 1;
										if (bool2) break;
									}
									if (bool2) break;
								}
								if (bool2) break;
							}

							for (int p = 0; p <12; p++)
							{
								for (int q = 0; q < 12; q++)
								{
									myboard[1][p][q] = myboard[0][p][q];
								}
							}

							if (tmp2 < tmp3)
							{
								tmp3 = tmp2;
								X2 = X1;
								Y2 = Y1;
								K2 = K1;

							}
							if (tmp2 <= tmp4) bool3 = 1;

							if (bool3) break;
						}
						if (bool3) break;
					}
					if (bool3) break;
				}
				for (int p = 0; p <12; p++)
				{
					for (int q = 0; q < 12; q++)
					{
						myboard[0][p][q] = board[p][q];

					}
				}

				if (tmp3 > tmp4)
				{
					tmp4 = tmp3;
					X3 = X2;
					Y3 = Y2;
					K3 = K2;
				}
			}
		}
	}

	X = X3;
	Y = Y3;
	K = K3;
	command.x = X;
	command.y = Y;
	command.option = K;
	int NOW;
	for (NOW = 0; NOW < now; NOW++)
	{
		memset(myboard[NOW], 0, sizeof(myboard[NOW]));
		for (int i = 0; i < 3; i++)
		{
			myboard[NOW][2][2 + i] = WHITE;
			myboard[NOW][6][6 + i] = WHITE;
			myboard[NOW][5][3 + i] = BLACK;
			myboard[NOW][9][7 + i] = BLACK;
		}
		for (int j = 0; j < 2; j++)
		{
			myboard[NOW][8 + j][2] = WHITE;
			myboard[NOW][2 + j][9] = BLACK;
		}
	}
	return command;

}


/*struct Command findValidPos(const char board[BOARD_SIZE][BOARD_SIZE], int flag)
{
struct Command command = { 0, 0, 0 };
for (int k = 0; k < 8; k++) {
const int* delta = DIR[k];
for (int x = 0; x < BOARD_SIZE; x++) {
for (int y = 0; y < BOARD_SIZE; y++) {
if (board[x][y] != flag) {
continue;
}
int new_x = x + delta[0];
int new_y = y + delta[1];
if (isInBound(new_x, new_y) && board[new_x][new_y] == EMPTY) {
command.x = x;
command.y = y;
command.option = k;
return command;
}
}
}
}
return command;
}



/**
* 轮到你落子。
* 棋盘上0表示空白，1表示黑棋，2表示白棋
* me表示你所代表的棋子(1或2)
* 你需要返回一个结构体Command，在x属性和y属性填上你想要移动的棋子的位置，option填上你想要移动的方向。
*/
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me) {
	/*
	* TODO：在这里写下你的AI。
	* 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。
	*/
	struct Command preferedPos = MYAI();

	return preferedPos;
}

/**
* 你的代码结束
*/



BOOL place(int x, int y, OPTION option, int cur_flag) {
	// 移动之前的位置没有我方棋子
	if (board[x][y] != cur_flag) {
		return FALSE;
	}

	int new_x = x + DIR[option][0];
	int new_y = y + DIR[option][1];
	// 移动之后的位置超出边界, 或者不是空地
	if (!isInBound(new_x, new_y) || board[new_x][new_y] != EMPTY) {
		return FALSE;
	}

	board[x][y] = EMPTY;
	board[new_x][new_y] = cur_flag;

	int cur_other_flag = 3 - cur_flag;

	// 挑
	int intervention_dir[4][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, -1 } };
	for (int i = 0; i < 4; i++) {
		int x1 = new_x + intervention_dir[i][0];
		int y1 = new_y + intervention_dir[i][1];
		int x2 = new_x - intervention_dir[i][0];
		int y2 = new_y - intervention_dir[i][1];
		if (isInBound(x1, y1) && isInBound(x2, y2) && board[x1][y1] == cur_other_flag && board[x2][y2] == cur_other_flag) {
			board[x1][y1] = cur_flag;
			board[x2][y2] = cur_flag;
		}
	}

	// 夹
	int custodian_dir[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
	for (int i = 0; i < 8; i++) {
		int x1 = new_x + custodian_dir[i][0];
		int y1 = new_y + custodian_dir[i][1];
		int x2 = new_x + custodian_dir[i][0] * 2;
		int y2 = new_y + custodian_dir[i][1] * 2;
		if (isInBound(x1, y1) && isInBound(x2, y2) && board[x2][y2] == cur_flag && board[x1][y1] == cur_other_flag) {
			board[x1][y1] = cur_flag;
		}
	}
	return TRUE;
}

void start(int flag) {
	memset(board, 0, sizeof(board));

	for (int i = 0; i < 3; i++) {
		board[2][2 + i] = WHITE;
		board[6][6 + i] = WHITE;
		board[5][3 + i] = BLACK;
		board[9][7 + i] = BLACK;
	}

	for (int i = 0; i < 2; i++) {
		board[8 + i][2] = WHITE;
		board[2 + i][9] = BLACK;
	}

	initAI(flag);
}

void turn() {
	// AI
	initBoard();

	if (board[6][6] == other_flag &&board[6][7] == other_flag&&board[9][8] == me_flag  && board[9][9] == me_flag&&board[5][5] == me_flag&&board[8][8] == EMPTY)
	{
		place(9, 8, 0, me_flag);
		printf("9 8 0\n");
		fflush(stdout);
	}
	else if (board[6][6] == other_flag &&board[6][7] == other_flag&&board[8][8] == me_flag  && board[5][5] == me_flag&&board[7][7] == EMPTY&&board[7][9] != other_flag)
	{
		place(8, 8, 4, me_flag);
		printf("8 8 4\n");
		fflush(stdout);
	}
	else if (board[6][7] == other_flag&&board[6][8] == other_flag&&board[7][7] == me_flag  && board[6][6] == me_flag&&board[5][7] == EMPTY)
	{
		place(6, 6, 5, me_flag);
		printf("6 6 5\n");
		fflush(stdout);
	}
	else if (board[6][7] == me_flag&&board[6][8] == other_flag&&board[7][7] == me_flag  && board[5][7] == me_flag&&board[3][9] == me_flag&&board[4][8] == EMPTY)
	{
		place(3, 9, 6, me_flag);
		printf("3 9 6\n");
		fflush(stdout);
	}
	else if (board[6][7] == me_flag&&board[6][8] == other_flag&&board[7][7] == me_flag  && board[5][7] == me_flag&&board[4][8] == me_flag&&board[5][9] == EMPTY)
	{
		place(4, 8, 7, me_flag);
		printf("4 8 7\n");
		fflush(stdout);
	}


	else if (board[2][3] == me_flag && board[5][3] == other_flag && board[5][4] == other_flag && board[5][5] == other_flag&&board[6][6] == me_flag&&board[3][3] == EMPTY)
	{
		place(2, 3, 1, me_flag);
		printf("2 3 1\n");
		fflush(stdout);
	}
	else if (board[3][3] == me_flag && board[5][3] == other_flag && board[5][4] == other_flag && board[5][5] == other_flag&&board[6][6] == me_flag&&board[4][4] == EMPTY&&board[4][2]!=other_flag)
	{
		place(3, 3, 7, me_flag);
		printf("3 3 7\n");
		fflush(stdout);
	}
	else if (board[4][4] == me_flag && board[5][3] == other_flag && board[5][4] == other_flag && board[5][5] == me_flag&&board[6][4] == EMPTY)
	{
		place(5, 5, 6, me_flag);
		printf("5 5 6\n");
		fflush(stdout);
	}
	else if (board[5][4] == me_flag && board[5][3] == other_flag && board[4][4] == me_flag && board[6][5] == me_flag&&board[8][2] == me_flag&&board[7][3] == EMPTY)
	{
		place(8, 2, 5, me_flag);
		printf("8 2 5\n");
		fflush(stdout);
	}
	else if (board[5][4] == me_flag && board[5][3] == other_flag && board[4][4] == me_flag && board[6][5] == me_flag&&board[7][3] == me_flag&&board[6][2] == EMPTY)
	{
		place(7, 3, 4, me_flag);
		printf("7 3 4\n");
		fflush(stdout);
	}
	//else if (board[])
	else if (board[3][3] == other_flag&&board[6][6] == other_flag&&board[5][5] == me_flag&&board[6][4] == EMPTY)
	{
		place(5, 5, 6, me_flag);
		printf("5 5 6\n");
		fflush(stdout);
	}
	else if (board[4][4] == other_flag&&board[5][5] == other_flag&&board[5][4] == me_flag&&board[4][3] == EMPTY)
	{
		place(5, 4, 4, me_flag);
		printf("5 4 4\n");
		fflush(stdout);
	}
	else 

	{
		struct Command command = aiTurn((const char(*)[BOARD_SIZE])board, me_flag);
		place(command.x, command.y, command.option, me_flag);
		printf("%d %d %d\n", command.x, command.y, command.option);
		fflush(stdout);
	}
}

void end(int x) {

}

void loop() {
	//  freopen("../input", "r", stdin);
	while (TRUE)
	{
		memset(buffer, 0, sizeof(buffer));
		gets(buffer);

		if (strstr(buffer, START))
		{
			char tmp[MAX_BYTE] = { 0 };
			sscanf(buffer, "%s %d", tmp, &me_flag);
			other_flag = 3 - me_flag;
			start(me_flag);
			printf("OK\n");
			fflush(stdout);

		}
		else if (strstr(buffer, PLACE))
		{
			char tmp[MAX_BYTE] = { 0 };
			int x, y;
			OPTION option;

			sscanf(buffer, "%s %d %d %d", tmp, &x, &y, &option);
			place(x, y, option, other_flag);
		}
		else if (strstr(buffer, TURN))
		{
			turn();
		}
		else if (strstr(buffer, END))
		{
			char tmp[MAX_BYTE] = { 0 };
			int x;
			sscanf(buffer, "%s %d", tmp, &x);
			end(x);
		}
		//printBoard();
	}
}


int main(int argc, char *argv[]) {
	loop();
	return 0;
}