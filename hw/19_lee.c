#include <stdio.h>
#include <string.h>
#include <math.h>
int dice[4][6];
int ctlist[5] = {0, 3, 5, 2, 0};
int rtlist[5] = {0, 4, 5, 1, 0};

int cmp(int dice[])
{
    int i, j, ans = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (dice[i] == dice[j] && i != j)
                ans += 1;
        }
    return ans;
}

int count(int dice1, int dice2, int dice3, int dice4)
{
    int i, j;
    int dice[4] = {dice1, dice2, dice3, dice4};
    if (dice1 == dice2 && dice2 == dice3 && dice3 == dice4) // 四個一樣
        return 18;
    else if (cmp(dice) == 6 || cmp(dice) == 0) // 三個一樣或全不一樣
        return 0;
    else if (cmp(dice) == 4)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (dice[i] > dice[j] && i != j)
                    // printf("%d\n", cmp(dice));
                    return dice[i] * 2;
    }
    else if (cmp(dice) == 2)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (dice[i] == dice[j] && i != j)
                    return dice[0] + dice[1] + dice[2] + dice[3] - dice[i] - dice[j];
    }
    // return 2;
}

void ut(int n_dice)
{
    int i;
    int temp[4];
    for (i = 0; i < 4; i++)
    {
        temp[i] = dice[n_dice][ctlist[i + 1]];
    }
    for (i = 0; i < 4; i++)
    {
        dice[n_dice][ctlist[i]] = temp[i];
    }
}

void dt(int n_dice)
{
    int i, j = 3;
    int temp[4];
    for (i = 0; i < 4; i++)
    {
        temp[i] = dice[n_dice][ctlist[j]];
        j--;
    }
    j = 0;
    for (i = 4; i > 0; i--)
    {
        dice[n_dice][ctlist[i]] = temp[j];
        j++;
    }
}

void rt(int n_dice)
{
    int i;
    int temp[4];
    for (i = 0; i < 4; i++)
    {
        temp[i] = dice[n_dice][rtlist[i + 1]];
    }
    for (i = 0; i < 4; i++)
    {
        dice[n_dice][rtlist[i]] = temp[i];
    }
}

void lt(int n_dice)
{
    int i, j = 3;
    int temp[4];
    for (i = 0; i < 4; i++)
    {
        temp[i] = dice[n_dice][rtlist[j]];
        j--;
    }
    j = 0;
    for (i = 4; i > 0; i--)
    {
        dice[n_dice][rtlist[i]] = temp[j];
        j++;
    }
}

int main()
{
    int i, j;
    int cmdcount;
    int cmd;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 6; j++)
            dice[i][j] = j + 1;
    scanf("%d", &cmdcount);
    for (i = 0; i < cmdcount; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &cmd);
            if (cmd == 1)
                ut(j);
            if (cmd == 2)
                dt(j);
            if (cmd == 3)
                rt(j);
            if (cmd == 4)
                lt(j);
        }
    }
    printf("%d", count(dice[0][0], dice[1][0], dice[2][0], dice[3][0]));
    // printf("%d %d %d %d", dice[0][0], dice[1][0], dice[2][0], dice[3][0]);
}
