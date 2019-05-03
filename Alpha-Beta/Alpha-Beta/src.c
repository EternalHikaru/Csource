#include<stdio.h>

void alpha_beta()
{
	int flag;
	for (int k = 0; k < 8; k++)
	{
		const int* delta = DIR[k];
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			for (int y = 0; y < BOARD_SIZE; y++)
			{
				if (board[x][y] != me_flag)
				{
					continue;
				}
}