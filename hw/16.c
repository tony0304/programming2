// 016 分散度

// 輸入一串整數序列和m分散度，輸出m分散度數量。
// m分散度定義為，序列中擁有長度為m 且有m 種不同數字的連續子序列之數量。

// 例如，m = 3，序列{1 2 3 5 4 5 4}，3 分散度數量{1 2 3}, {2 3 5}, {3 5 4}，總共三個。




// sample input:
// 1235454
// 3


// sample output:
// 3

// ----------------

// sample input:
// 1866454122
// 5

// sample output:
// 0

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int toInt(char c)
{
    return c - '0';
}

int getN(char *c)
{
    int i;
    for (i = 0; i < 999; i++)
    {
        if (toInt(c[i]) > 9 || toInt(c[i]) < 0)
            break;
    }
    return i;
}

int different(char *c)
{
    int count = 0;
    for (int i = 0; i < getN(c); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (c[j] == c[i])
            {
                count -= 1;
                break;
            }
        }
        count += 1;
    }
    return count;
}

int main()
{
    char input[999];
    int m, result = 0;
    scanf("%s", input);
    getchar();
    scanf("%d", &m);

    for (int i = 0; i < getN(input) - m + 1; i++)
    {
        int temp = 0;
        char c_temp[getN(input) + 1];
        for (int j = 0; j < m; j++)
        {
            c_temp[j] = input[i + j];
        }
        
        if (different(c_temp) == m)
            result++;
    }
    printf("%d", result);

    return 0;
}