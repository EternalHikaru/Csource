#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int bd[5][13][13] = { 0 };
int di;
//上面的都是在定义新变量；

/**
* 你可以在这里初始化你的AI
*/
BOOL placex(int x, int y, OPTION option, int cur_flag, int step)
{
	// 移动之前的位置没有我方棋子
	if (bd[step][x][y] != cur_flag) {
		return FALSE;
	}

	int new_x = x + DIR[option][0];
	int new_y = y + DIR[option][1];
	// 移动之后的位置超出边界, 或者不是空地
	if (!isInBound(new_x, new_y) || bd[step][new_x][new_y] != EMPTY) {
		return FALSE;
	}

	bd[step][x][y] = EMPTY;
	bd[step][new_x][new_y] = cur_flag;

	int cur_other_flag = 3 - cur_flag;

	// 挑
	int intervention_dir[4][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, -1 } };
	for (int i = 0; i < 4; i++) {
		int x1 = new_x + intervention_dir[i][0];
		int y1 = new_y + intervention_dir[i][1];
		int x2 = new_x - intervention_dir[i][0];
		int y2 = new_y - intervention_dir[i][1];
		if (isInBound(x1, y1) && isInBound(x2, y2) && bd[step][x1][y1] == cur_other_flag && bd[step][x2][y2] == cur_other_flag) {
			bd[step][x1][y1] = cur_flag;
			bd[step][x2][y2] = cur_flag;
		}
	}

	// 夹
	int custodian_dir[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } };
	for (int i = 0; i < 8; i++) {
		int x1 = new_x + custodian_dir[i][0];
		int y1 = new_y + custodian_dir[i][1];
		int x2 = new_x + custodian_dir[i][0] * 2;
		int y2 = new_y + custodian_dir[i][1] * 2;
		if (isInBound(x1, y1) && isInBound(x2, y2) && bd[step][x2][y2] == cur_flag && bd[step][x1][y1] == cur_other_flag) {
			bd[step][x1][y1] = cur_flag;
		}
	}

	return TRUE;
}

void chu()//初始化变量 
{
	for (int i = 0; i <= 3; i++)
	{
		for (int x = 0; x<12; x++)
		{
			for (int y = 0; y<12; y++)
				bd[i][x][y] = board[x][y];
		}
	}
}

int scp()//数棋子 
{

	int tji = 0;
	for (int i = 0; i<12; i++)
	{
		for (int j = 0; j<12; j++)
		{
			if (bd[3][i][j] == me_flag) tji++;
		}
	}
	return tji;
}

void initAI(int me)
{

}
struct Command wdai()
{
	int ces;
	struct Command command = { 0, 0, 0 };
	int nx, ny, nk;
	int score = 999;
	int h[4] = { 0 };
	for (int x = 0; x<12; x++)
	{

		for (int y = 0; y<12; y++)
		{
			if (board[x][y] != me_flag) continue;

			for (int k = 0; k<8; k++)
			{
				if (board[x + DIR[k][0]][y + DIR[k][1]] != 0) continue;
				if (x + DIR[k][0]>11 || x + DIR[k][0]<0 || y + DIR[k][1]>11 || y + DIR[k][1]<0) continue;

				placex(x, y, k, me_flag, 0);
				placex(x, y, k, me_flag, 1);
				placex(x, y, k, me_flag, 2);
				placex(x, y, k, me_flag, 3);
			

				int i[4] = { 0 };
				i[0] = 999;
				int bomb1 = 0;
				for (int x1 = 0; x1<12; x1++)
				{
					for (int y1 = 0; y1<12; y1++)
					{
						if (bd[0][x1][y1] != other_flag) continue;
						for (int k1 = 0; k1<8; k1++)
						{
							if (bd[0][x1 + DIR[k1][0]][y1 + DIR[k1][1]] != 0) continue;
							if (x1 + DIR[k1][0]>11 || x1 + DIR[k1][0]<0 || y1 + DIR[k1][1]>11 || y1 + DIR[k1][1]<0) continue;
							placex(x1, y1, k1, other_flag, 1);
							placex(x1, y1, k1, other_flag, 2);
							placex(x1, y1, k1, other_flag, 3);
							//第三重开始了 
							int j[4] = { 0 };
							int bomb2 = 0;
							for (int x2 = 0; x2<12; x2++)
							{
								for (int y2 = 0; y2<12; y2++)
								{
									if (bd[1][x2][y2] != me_flag) continue;
									for (int k2 = 0; k2<8; k2++)
									{
										if (bd[1][x2 + DIR[k2][0]][y2 + DIR[k2][1]] != 0) continue;
										if (x2 + DIR[k2][0]>11 || x2 + DIR[k2][0]<0 || y2 + DIR[k2][1]>11 || y2 + DIR[k2][1]<0) continue;
										placex(x2, y2, k2, me_flag, 2);
										placex(x2, y2, k2, me_flag, 3);
										//第四重开始了
										int di1 = 999;
										int bomb3 = 0;			//这里声明了变量； 
										for (int x3 = 0; x3<12; x3++)
										{
											for (int y3 = 0; y3<12; y3++)
											{
												if (bd[2][x3][y3] != other_flag) continue;
												for (int k3 = 0; k3<8; k3++)
												{
													if (bd[2][x3 + DIR[k3][0]][y3 + DIR[k3][1]] != 0) continue;
													if (x3 + DIR[k3][0]>11 || x3 + DIR[k3][0]<0 || y3 + DIR[k3][1]>11 || y3 + DIR[k3][1]<0) continue;
													placex(x3, y3, k3, other_flag, 3);
													
													di = scp();//这里进行了非常无脑的数棋子
													

													for (int x4 = x3 - 2; x4<x3 + 2; x4++)//还原棋盘 
													{
														for (int y4 = y3 - 2; y4<y3 + 2; y4++)
														{
															bd[3][x4][y4] = bd[2][x4][y4];
														}
													}
													if (di<di1) di1 = di;//对手会取最小值 
													if (j[0]>di)//炸弹用来剪枝 
													{
														bomb3 = 1;
														break;
													}


												}
												if (bomb3 == 1) break;
											}
											if (bomb3 == 1) break;
										} //第四重结束了
										bomb3 = 0;
										for (int x4 = 0; x4<12; x4++)//还原棋盘 
										{
											for (int y4 = 0; y4<12; y4++)
											{
												bd[2][x4][y4] = bd[1][x4][y4];
											}
										}

										if (j[0]<di1) //我会更新最大值 
										{

											j[0] = di1;
											j[1] = x;
											j[2] = y;
											j[3] = k;
										}
										//	 printf("%d %d %d \n",j[1],j[2],j[3]

										if (i[0]<di1) //炸弹用来剪枝 
										{
											bomb2 = 1;
											break;
										}
									}
									if (bomb2 == 1) break;
								}
								if (bomb2 == 1) break;
							}//第三重结束了
							bomb2 = 0;
							for (int x4 = 0; x4<12; x4++)//还原棋盘 
							{
								for (int y4 = 0; y4<12; y4++)
								{
									bd[1][x4][y4] = bd[0][x4][y4];
								}
							}
							if (i[0]>j[0])
							{
								i[0] = j[0];
								i[1] = j[1];
								i[2] = j[2];
								i[3] = j[3];

							}
							if (h[0]>j[0]) //炸弹用来剪枝 
							{
								bomb1 = 1;
								break;
							}
						}
						if (bomb1 == 1) break;
					}
					if (bomb1 == 1) break;
				}//第二重结束了 
				bomb1 = 0;
				for (int x4 = 0; x4<12; x4++)//还原棋盘 
				{
					for (int y4 = 0; y4<12; y4++)
					{
						bd[0][x4][y4] = board[x4][y4];
					}
				}
				if (h[0]<i[0])
				{
					h[0] = i[0];
					h[1] = i[1];
					h[2] = i[2];
					h[3] = i[3];
					ces = i[0];
					//	printf("%d*",i[1]);

				}
			}
		}
	}//大循环在这结束 

	score = h[0];
	nx = h[1];
	ny = h[2];
	nk = h[3];

	command.x = nx;
	command.y = ny;
	command.option = nk;
	return command;
}

/*struct Command findValidPos(const char board[BOARD_SIZE][BOARD_SIZE], int flag) {
struct Command command = {0, 0, 0};
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
}*/

/**
* 轮到你落子。
* 棋盘上0表示空白，1表示黑棋，2表示白旗
* me表示你所代表的棋子(1或2)
* 你需要返回一个结构体Command，在x属性和y属性填上你想要移动的棋子的位置，option填上你想要移动的方向。
*/
struct Command aiTurn(const char board[BOARD_SIZE][BOARD_SIZE], int me) {
	/*
	* TODO：在这里写下你的AI。
	* 这里有一个示例AI，它只会寻找第一个可下的位置进行落子。
	*/
	struct Command preferedPos = wdai();

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



//........
//........
//..XXXX..
//XXXX....
//....OOOO
//..OOOO..
//........
//........
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
	chu();
	struct Command command = aiTurn((const char(*)[BOARD_SIZE])board, me_flag);
	place(command.x, command.y, command.option, me_flag);
	printf("%d %d %d\n", command.x, command.y, command.option);
	fflush(stdout);
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
		printBoard();
	}
}


int main(int argc, char *argv[]) {
	loop();
	return 0;
}