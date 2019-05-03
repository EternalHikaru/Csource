#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void printpic();
void printchess(int x, int y, int type, int self[][SIZE], int opp[][SIZE]);
int judgevalid(char *cmd, int self[][SIZE], int opp[][SIZE], int type, int opptype);
int judgeposit(int self[][SIZE], int opp[][SIZE], int type, int opptype);
int judge(int x, int y, int self[][SIZE], int opp[][SIZE], int type, int opptype);
int invalid(int self[][SIZE], int opp[][SIZE], int type, int opptype);

int coordinate[1000][5];
int picture[2 * SIZE + 2][4 * SIZE + 2];
int row = 0;
int origin[2];
int quan[SIZE][SIZE] = { 90,-60,10,10,10,10,-60,90,
						-60,-80, 5, 5, 5, 5,-80,60,
						 10,  5, 1, 1, 1, 1,  5,10,
						 10,  5, 1, 1, 1, 1,  5,10,
	                     10,  5, 1, 1, 1, 1,  5,10,
						 10,  5, 1, 1, 1, 1,  5,10,
						-60,-80, 5, 5, 5, 5,-80,60,
						 90,-60,10,10,10,10,-60,90 };

int main()
{
	int i, j, k, x, y, valid = 1;
	int w = 0, b = 0;
	char cmd[100];
	int white[SIZE][SIZE];
	int black[SIZE][SIZE];
	int quanmax, posit[2];
	int whitelast[SIZE][SIZE];
	int blacklast[SIZE][SIZE];
	int v, s , maxs = -10000, maxv = -10000, maxi = 0;
	printf("\n");
	printf("REVERSI\n\n");
	printf("You can go first on the first game, then we will take turns.\n");
	printf("You will be white - <O>\n");
	printf("I will be black - <X>.\n");
	printf("Select a square for your move by typing a digit for the row\n");
	printf("and a letter for the column with no spaces between.\n\n");
	printf("Good luck! Press Enter to start.\n");
	if (getchar() != '\0')
	{
		for (i = 0; i <= 4 * SIZE + 1; i++) { picture[0][i] = 32; }
		for (i = 1; i <= SIZE; i++) { picture[0][4 * i - 1] = (96 + i); }
		for (i = 1; i <= SIZE; i++)
		{
			picture[2 * i - 1][0] = 32;
			picture[2 * i - 1][4 * SIZE + 1] = 43;
			picture[2 * i][0] = 48 + i;
			picture[2 * i][4 * SIZE + 1] = 124;
			for (j = 1; j <= SIZE; j++) 
			{ 
				picture[2 * i - 1][4 * j - 3] = 43;
				picture[2 * i - 1][4 * j - 2] = 45;
				picture[2 * i - 1][4 * j - 1] = 45;
				picture[2 * i - 1][4 * j] = 45;
				picture[2 * i][4 * j - 3] = 124;
				picture[2 * i][4 * j - 2] = 32;
				picture[2 * i][4 * j - 1] = 32;
				picture[2 * i][4 * j] = 32;
			}
		}
		picture[2 * SIZE + 1][0] = 32;
		picture[2 * SIZE + 1][4 * SIZE + 1] = 43;
		for (j = 1; j <= SIZE; j++)
		{
			picture[2 * SIZE + 1][4 * j - 3] = 43;
			picture[2 * SIZE + 1][4 * j - 2] = 45;
			picture[2 * SIZE + 1][4 * j - 1] = 45;
			picture[2 * SIZE + 1][4 * j] = 45;
		}
		picture[8][15] = 'O';
		picture[8][19] = 'X';
		picture[10][15] = 'X';
		picture[10][19] = 'O';
		for (i = 0; i <= SIZE - 1; i++)
		{
			for (j = 0; j <= SIZE - 1; j++)
			{
				white[i][j] = 0;
				black[i][j] = 0;
			}
		}
		white[3][3] = 1;
		white[4][4] = 1;
		black[3][4] = 10;
		black[4][3] = 10;
		printpic();
		while(1)
		{
			w = 0; b = 0;
			printf("Please enter your move <row column- no space>: ");
			gets(cmd);
			while (judgevalid(cmd, white, black, 1, 10) != 1)
			{
				if (invalid(white, black, 1, 10) == 1)
				{
					printf("You can't move.\n");
					valid = 0;
					break;
				}
				else
				{
					printf("Not a valid move, try again.\n");
					for (i = 0; i <= 99; i++) { cmd[i] = '\0'; }
					printf("Please enter your move <row column- no space>: ");
					gets(cmd);
				}
			}
			if (valid == 1)
			{
				x = cmd[0] - 48;
				y = cmd[1] - 96;
				picture[2 * x][4 * y - 1] = 79;
				for (i = 0; i <= 999; i++)
				{
					if (cmd[0] - 49 == coordinate[i][0] && cmd[1] == 97 + coordinate[i][1])
					{
						origin[0] = coordinate[i][2];
						origin[1] = coordinate[i][3];
						printchess(x, y, 1, white, black);
					}
				}
				printpic();
			}
			valid = 1;
			if (invalid(black, white, 10, 1) == 1)
			{
				valid = 0;
			}
			if (valid == 1)
			{
				//printf("%d\n", value(black, white, 10, 1));
				judgeposit(black, white, 10, 1);
				for (i = 0; i <= SIZE - 1; i++)
				{
					for (j = 0; j <= SIZE - 1; j++)
					{
						whitelast[i][j] = white[i][j];
						blacklast[i][j] = black[i][j];
					}
				}
				for (i = 0; i <= 80; i++)
				{
					if (coordinate[i][0] != 100)
					{
						x = coordinate[i][0] + 1;
						y = coordinate[i][1] + 1;
						for (j = 0; j <= 80; j++)
						{
							if (x - 1 == coordinate[j][0] && y - 1 == coordinate[j][1])
							{
								origin[0] = coordinate[j][2];
								origin[1] = coordinate[j][3];
								blackwhite(x, y, 10, black, white);
							}
						}
						v = value(black, white, 10, 1);
						judgeposit(white, black, 1, 10);
						for (j = 0; j <= 80; j++)
						{
							if (coordinate[j][0] != 100)
							{
								x = coordinate[j][0] + 1;
								y = coordinate[j][1] + 1;
								for (k = 0; k <= 80; k++)
								{
									if (x - 1 == coordinate[k][0] && y - 1 == coordinate[k][1])
									{
										origin[0] = coordinate[k][2];
										origin[1] = coordinate[k][3];
										blackwhite(x, y, 1, white, black);
									}
								}
								s = value(white, black, 1, 10);
							}
							else { break; }
							if (s > maxs)
							{
								maxs = s;
							}

						}
						v = v - maxs;
						if (v > maxv)
						{
							maxv = v;
							maxi = i;
						}
						for (j = 0; j <= SIZE - 1; j++)
						{
							for (k = 0; k <= SIZE - 1; k++)
							{
								white[j][k] = whitelast[j][k];
								black[j][k] = blacklast[j][k];
							}
						}
					}
					else { break; }
				}
				judgeposit(black, white, 10, 1);
				//quanmax = coordinate[0][4];
				posit[0] = coordinate[maxi][0];
				posit[1] = coordinate[maxi][1];
				origin[0] = coordinate[maxi][2];
				origin[1] = coordinate[maxi][3];
				/*
				for (i = 0; i <= 999; i++)
				{
					if (quanmax < coordinate[i][4])
					{
						posit[0] = coordinate[i][0];
						posit[1] = coordinate[i][1];
						origin[0] = coordinate[i][2];
						origin[1] = coordinate[i][3];
					}
					if (coordinate[i][4] == -1000)
					{
						break;
					}
				}
				*/
				x = posit[0] + 1;
				y = posit[1] + 1;
				printf("%c%c\n", x + 48, y + 96);
				for (i = 0; i <= 999; i++)
				{
					if (x - 1 == coordinate[i][0] && y - 1 == coordinate[i][1])
					{
						origin[0] = coordinate[i][2];
						origin[1] = coordinate[i][3];
						printchess(x, y, 10, black, white);
					}
				}
				picture[2 * x][4 * y - 1] = 88;
				printpic();
			}
			else 
			{
				printf("Your turn.\n");
				valid = 1;
			}
			for (i = 0; i <= 7; i++)
			{
				for (j = 0; j <= 7; j++)
				{
					if (white[i][j] == 1)
						w = w + 1;
					if (black[i][j] == 10)
						b = b + 1;
				}
			}
			printf("white %d black %d\n", w, b);
			if (w > 0 && b == 0)
			{
				printf("You win!\n");
				break;
			}
			if (w == 0 && b > 0)
			{
				printf("You lose!\n");
				break;
			}
			if (w + b == 64 && w > b)
			{
				printf("You win!\n");
				break;
			}
			if (w + b == 64 && w < b)
			{
				printf("You lose!\n");
				break;
			}
			if (w + b == 64 && w == b)
			{
				printf("The game ends in a draw!\n");
				break;
			}
		}
	}
	system("PAUSE");
	return 0;
}

void printpic() //打印棋盘
{
	int i, j;
	for (i = 0; i <= 2 * SIZE + 1; i++)
	{
		for (j = 0; j <= 4 * SIZE + 1; j++)
		{
			printf("%c", picture[i][j]);
		}
		printf("\n");
	}
}

void printchess(int x, int y, int type,int self[][SIZE],int opp[][SIZE]) //打印棋子
{
	int i;
	if (x - 1 == origin[0]) //横向
	{
		if (y - 1 > origin[1])
		{
			for (i = origin[1] + 1; i <= y; i++)
			{
				picture[2 * x][4 * i - 1] = 78 + type;
				self[x - 1][i - 1] = type;
				opp[x - 1][i - 1] = 0;
			}
		}
		else
		{
			for (i = origin[1] + 1; i >= y; i--)
			{
				picture[2 * x][4 * i - 1] = 78 + type;
				self[x - 1][i - 1] = type;
				opp[x - 1][i - 1] = 0;
			}
		}
	}
	if (y - 1 == origin[1]) //纵向
	{
		if (x - 1 > origin[0])
		{
			for (i = origin[0] + 1; i <= x; i++)
			{
				picture[2 * i][4 * y - 1] = 78 + type;
				self[i - 1][y - 1] = type;
				opp[i - 1][y - 1] = 0;
			}
		}
		else
		{
			for (i = origin[0] + 1; i >= x; i--)
			{
				picture[2 * i][4 * y - 1] = 78 + type;
				self[i - 1][y - 1] = type;
				opp[i - 1][y - 1] = 0;
			}
		}
	}
	if (x - 1 > origin[0] && y - 1 > origin[1]) //斜线
	{
		for (i = 1; i <= x - origin[0]; i++)
		{
			picture[2 * (origin[0] + i)][4 * (origin[1] + i) - 1] = 78 + type;
			self[origin[0] + i - 1][origin[1] + i - 1] = type;
			opp[origin[0] + i - 1][origin[1] + i - 1] = 0;
		}
	}
	if (x - 1 > origin[0] && y - 1 < origin[1])
	{
		for (i = 1; i <= x - origin[0]; i++)
		{
			picture[2 * (origin[0] + i)][4 * (origin[1] + 2 - i) - 1] = 78 + type;
			self[origin[0] + i - 1][origin[1] + 1 - i] = type;
			opp[origin[0] + i - 1][origin[1] + 1 - i] = 0;
		}
	}
	if (x - 1 < origin[0] && y - 1 > origin[1])
	{
		for (i = 1; i <= origin[0] + 2 - x; i++)
		{
			picture[2 * (origin[0] + 2 - i)][4 * (origin[1] + i) - 1] = 78 + type;
			self[origin[0] + 1 - i][origin[1] + i - 1] = type;
			opp[origin[0] + 1 - i][origin[1] + i - 1] = 0;
		}
	}
	if (x - 1 < origin[0] && y - 1 < origin[1])
	{
		for (i = 1; i <= origin[0] + 2 - x; i++)
		{
			picture[2 * (origin[0] + 2 - i)][4 * (origin[1] + 2 - i) - 1] = 78 + type;
			self[origin[0] + 1 - i][origin[1] + 1 - i] = type;
			opp[origin[0] + 1 - i][origin[1] + 1 - i] = 0;
		}
	}
}

int judgevalid(char *cmd, int self[][SIZE], int opp[][SIZE], int type, int opptype) //判断己方棋子位置并判断是否此步棋合法
{
	int i, j;
	int x, y;
	for (i = 0; i <= 999; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			coordinate[i][j] = 100;
		}
	}
	row = 0;
	if (strlen(cmd) != 2)
	{
		return 0;
	}
	else
	{
		for (i = 0; i <= SIZE - 1; i++)
		{
			for (j = 0; j <= SIZE - 1; j++)
			{
				if (self[i][j] == 1)
				{
					judge(i, j, self, opp, 1, 10);
				}
			}
		}
		for (i = 0; i <= 999; i++)
		{
			if (cmd[0] - 49 == coordinate[i][0] && cmd[1] == 97 + coordinate[i][1]) 
			{ 
				origin[0] = coordinate[i][2];
				origin[1] = coordinate[i][3];
				return 1; 
			}
		}
		return 0;
	}
}

int judgeposit(int self[][SIZE], int opp[][SIZE], int type, int opptype)
{
	int i, j;
	int x, y;
	for (i = 0; i <= 999; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			coordinate[i][j] = 100;
		}
		coordinate[i][j] = -1000;
	}
	row = 0;
	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (self[i][j] == type)
			{
				judge(i, j, self, opp, type, opptype);
			}
		}
	}
}

int judge(int x, int y, int self[][SIZE], int opp[][SIZE], int type, int opptype) //判断八个方向哪些位置可以走
{
	int posit, time, selfposit;
	int m = x, n = y;
	int valid;
	if (x != 0 && y != 0) //左上角
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != 0 && y != 0)
		{
			posit = opp[x - 1][y - 1];
			selfposit = self[x - 1][y - 1];
			if (posit == opptype) { x--; y--; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x - 1;
			coordinate[row][1] = y - 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x - 1][y - 1];
			row++;
		}
		x = m; y = n;
	}
	if (x != 0 && y != SIZE - 1) //右上角
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != 0 && y != SIZE - 1)
		{
			posit = opp[x - 1][y + 1];
			selfposit = self[x - 1][y + 1];
			if (posit == opptype) { x--; y++; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x - 1;
			coordinate[row][1] = y + 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x - 1][y + 1];
			row++;
		}
		x = m; y = n;
	}
	if (x != SIZE - 1 && y != 0) //左下角
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != SIZE - 1 && y != 0)
		{
			posit = opp[x + 1][y - 1];
			selfposit = self[x + 1][y - 1];
			if (posit == opptype) { x++; y--; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x + 1;
			coordinate[row][1] = y - 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x + 1][y - 1];
			row++;
		}
		x = m; y = n;
	}
	if (x != SIZE - 1 && y != SIZE - 1) //右下角
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != SIZE - 1 && y != SIZE - 1)
		{
			posit = opp[x + 1][y + 1];;
			selfposit = self[x + 1][y + 1];
			if (posit == opptype) { x++; y++; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x + 1;
			coordinate[row][1] = y + 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x + 1][y + 1];
			row++;
		}
		x = m; y = n;
	}
	if (x != 0) //垂直上
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != 0)
		{
			posit = opp[x - 1][y];
			selfposit = self[x - 1][y];
			if (posit == opptype) { x--; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x - 1;
			coordinate[row][1] = y;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x - 1][y];
			row++;
		}
		x = m; y = n;
	}
	if (x != SIZE - 1) //垂直下
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (x != SIZE - 1)
		{
			posit = opp[x + 1][y];
			selfposit = self[x + 1][y];
			if (posit == opptype) { x++; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x + 1;
			coordinate[row][1] = y;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x + 1][y];
			row++;
		}
		x = m; y = n;
	}
	if (y != 0) //向左
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (y != 0)
		{
			posit = opp[x][y - 1];
			selfposit = self[x][y - 1];
			if (posit == opptype) { y--; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x;
			coordinate[row][1] = y - 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x][y - 1];
			row++;
		}
		x = m; y = n;
	}
	if (y != SIZE - 1) //向右
	{
		m = x; n = y;
		time = 0; valid = 0;
		while (y != SIZE - 1)
		{
			posit = opp[x][y + 1];
			selfposit = self[x][y + 1];
			if (posit == opptype) { y++; time++; }
			else { valid = 1; break; }
		}
		if (time != 0 && selfposit != type && valid == 1)
		{
			coordinate[row][0] = x;
			coordinate[row][1] = y + 1;
			coordinate[row][2] = m;
			coordinate[row][3] = n;
			coordinate[row][4] = quan[x][y + 1];
			row++;
		}
		x = m; y = n;
	}
}

int invalid(int self[][SIZE], int opp[][SIZE], int type, int opptype)
{
	int i, j;
	for (i = 0; i <= 999; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			coordinate[i][j] = 100;
		}
	}
	row = 0;
	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (self[i][j] == type)
			{
				judge(i, j, self, opp, type, opptype);
			}
		}
	}
	if (coordinate[0][0] == 100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int value(int self[][SIZE], int opp[][SIZE], int type, int opptype)
{
	int i, j, V = 0;
	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (self[i][j] == type)
			{
				V = V + quan[i][j];
			}
			else if (opp[i][j] == opptype)
			{
				V = V - quan[i][j];
			}
			else
			{
				continue;
			}
		}
	}
	for (i = 0; i <= 999; i++)
	{
		for (j = 0; j <= 4; j++)
		{
			coordinate[i][j] = 100;
		}
	}
	row = 0;
	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (self[i][j] == type)
			{
				judge(i, j, self, opp, type, opptype);
			}
		}
	}
	i = 0;
	while (1)
	{
		if (coordinate[i][0] != 100)
		{
			i++;
		}
		else
		{
			break;
		}
	}	
	V = V + 10 * i;
	return V;
}

int blackwhite(int x, int y, int type, int self[][SIZE], int opp[][SIZE])
{
	int i;
	if (x - 1 == origin[0]) //横向
	{
		if (y - 1 > origin[1])
		{
			for (i = origin[1] + 1; i <= y; i++)
			{
				self[x - 1][i - 1] = type;
				opp[x - 1][i - 1] = 0;
			}
		}
		else
		{
			for (i = origin[1] + 1; i >= y; i--)
			{
				self[x - 1][i - 1] = type;
				opp[x - 1][i - 1] = 0;
			}
		}
	}
	if (y - 1 == origin[1]) //纵向
	{
		if (x - 1 > origin[0])
		{
			for (i = origin[0] + 1; i <= x; i++)
			{
				self[i - 1][y - 1] = type;
				opp[i - 1][y - 1] = 0;
			}
		}
		else
		{
			for (i = origin[0] + 1; i >= x; i--)
			{
				self[i - 1][y - 1] = type;
				opp[i - 1][y - 1] = 0;
			}
		}
	}
	if (x - 1 > origin[0] && y - 1 > origin[1]) //斜线
	{
		for (i = 1; i <= x - origin[0]; i++)
		{
			self[origin[0] + i - 1][origin[1] + i - 1] = type;
			opp[origin[0] + i - 1][origin[1] + i - 1] = 0;
		}
	}
	if (x - 1 > origin[0] && y - 1 < origin[1])
	{
		for (i = 1; i <= x - origin[0]; i++)
		{
			self[origin[0] + i - 1][origin[1] + 1 - i] = type;
			opp[origin[0] + i - 1][origin[1] + 1 - i] = 0;
		}
	}
	if (x - 1 < origin[0] && y - 1 > origin[1])
	{
		for (i = 1; i <= origin[0] + 2 - x; i++)
		{
			self[origin[0] + 1 - i][origin[1] + i - 1] = type;
			opp[origin[0] + 1 - i][origin[1] + i - 1] = 0;
		}
	}
	if (x - 1 < origin[0] && y - 1 < origin[1])
	{
		for (i = 1; i <= origin[0] + 2 - x; i++)
		{
			self[origin[0] + 1 - i][origin[1] + 1 - i] = type;
			opp[origin[0] + 1 - i][origin[1] + 1 - i] = 0;
		}
	}
}