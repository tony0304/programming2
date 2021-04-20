#include <stdio.h>
#include <string.h>
#include <math.h>

int block[6][9];
int ctlist[5] = {3, 5, 2, 0, 3};
int rtlist[5] = {3, 1, 2, 4, 3};

void rotation(int surface, int direction)
{
	int i, j;
	int temp[9];
	if (direction == 1) //左
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				temp[i * 3 + j] = block[surface][(2 - j) * 3 + i];
			}
		}
	}
	if (direction == 2) //右
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				temp[i * 3 + j] = block[surface][j * 3 + (2 - i)];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			block[surface][i * 3 + j] = temp[i * 3 + j];
		}
	}
}

void ct(int col)
{
	int i, j;
	int temp[4][3];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = block[ctlist[i + 1]][j * 3 + col];
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			block[ctlist[i]][j * 3 + col] = temp[i][j];
		}
	}
	if (col == 0)
		rotation(4, 1);
	else if (col == 2)
		rotation(1, 2);
}

void rt(int row)
{
	int i, j;
	int temp[4][3];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[i][j] = block[rtlist[i + 1]][3 * row + j];
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			block[rtlist[i]][3 * row + j] = temp[i][j];
		}
	}
	// if (row == 0)
	// 	rotation(0, 1);
	// else if (row == 2)
	// 	rotation(5, 2);
}

int main()
{
	int i, j;
	int cmdcount;
    int cmd;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 9; j++)
			block[i][j] = i + 1;
	scanf("%d", &cmdcount);
	for (i = 0; i < cmdcount; i++)
	{
		scanf("%d", &cmd);
		if (cmd / 10 == 1)
			ct(cmd % 10);
		if (cmd / 10 == 2)
			rt(cmd % 10);
	}

	for (j = 0; j < 3; j++)
		printf("%d %d %d\n", block[0][j * 3 + 0], block[0][j * 3 + 1], block[0][j * 3 + 2]);
}
