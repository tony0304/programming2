// 014 1A2B

// 小明和小萱在玩猜數字遊戲，
// 由小明先輸入四個數字為謎底，
// 小萱輸入想要猜的四個數字。
// 若猜中數字則顯示win
// 若猜錯則顯示XAYB（X表示位置和數字皆正確的個數，而Y表示數字正確而位置不對的個數）
// ＊＊＊最多猜六次＊＊＊


// sample input1:
// 1234
// 5678
// 1234

// sample output1:
// 0A0B
// win


// ------------------

// sample input2:
// 0487
// 0234
// 1498
// 2378
// 3294
// 3681
// 5412

// sample output2:
// 1A1B
// 1A1B
// 0A2B
// 0A1B
// 1A0B
// 1A0B

#include <stdio.h>
#include <string.h>

int main()
{
    char answer[5];
    int n = 0;
    scanf("%s", answer);
    while (n < 6)
    {
        int a = 0, b = 0;
        char guess[5];
        scanf("%s", guess);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (guess[i] == answer[i])
                {
                    a++;
                    break;
                }
                else if (guess[i] == answer[j] && i != j)
                {
                    b++;
                }
            }
        }
        if (a == 4)
        {
            printf("win");
            n = 6;
        }
        else
        {
            printf("%dA%dB\n", a, b);
        }
        n++;
    }
    return 0;
}