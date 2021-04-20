// DF - expression是儲存圖片資訊的表達方式。
// 在一個n*n方陣中，若方格是白色記為0；黑色記為1；
// 若方格可分為更小方格(左上、右上、左下、右下)，則記2，再依序(左上→右上→左下→右下)記錄這四個方格的資訊。
// 以下圖為例 :
// 第一張圖全為白，所以輸出為0。
// 第二張圖全為黑，所以輸出為1。
// 第三張圖因為有黑有白，所以記為2，接著繼續切，從左上開始，全為白，記為0，再來右上，有黑有白繼續切，記為2，接著繼續從右上那塊往下做，從左上開始，全為白，記為0，再來右上(白)，記0，左下(黑)，記1，右下(白)，記0，接著回到外面那塊的左下(黑)，記1，再來右下(白)，記0。最後輸出為202001010。

// □□□□
// □□□□
// □□□□
// □□□□
// 0

// ■■■■
// ■■■■
// ■■■■
// ■■■■
// 1

// □□|□□
// □□|■□
// --------
// ■■|□□
// ■■|□□
// 202001010

// 輸入：給定DF - expression的輸入、這張圖像寬度(必為2的非負整數次方)
// 輸出：這張圖中黑色格子的座標位置(輸出座標順序由左而右、由上到下，最左上為0,0)，如無黑色格子則輸出all white。

// Sample Input
// 1
// 2

// Sample Output
// 0,0
// 0,1
// 1,0
// 1,1
// -------------------------------
// Sample Input
// 202001010
// 4

// Sample Output
// 1,2
// 2,0
// 2,1
// 3,0
// 3,1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int width, idx, temp = 0, nelson[8] = {0, 1, 4, 5, 16, 17, 20, 21}, nelson2[8] = {0, 2, 8, 10, 32, 34, 40, 42};
int *data, pict[4][4];
char s[999];

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

void func(int w)
{
    idx++;
    if (s[idx] == '0')
    {
        for (int i = 0; i < w * w; i++)
        {
            data[temp] = 0;
            temp++;
        }
    }
    else if (s[idx] == '1')
    {
        for (int i = 0; i < w * w; i++)
        {
            data[temp] = 1;
            temp++;
        }
    }
    else if (s[idx] == '2')
    {
        w = w / 2;
        for (int i = 0; i < 4; i++)
        {
            func(w);
        }
        w = w * 2;
    }
}

void haha()
{
    int a = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // printf("%d ", data[nelson[j] + nelson2[i]]);
            if (data[nelson[j] + nelson2[i]] == 1)
            {
                printf("%d,%d\n", i, j);
                a = 1;
            }
        }
        // printf("\n");
    }
    if (a == 0)
    {
        printf("all white");
    }
}

int main()
{
    scanf("%s", &s);
    getchar();
    scanf("%d", &width);
    getchar();
    data = malloc(sizeof(int) * width * width);
    idx = -1;
    func(width);
    haha();
    
    return 0;
}