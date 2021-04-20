// 009
// 葛雷碼 (Gray code)
// 反射二進位編碼-葛雷碼 (Gray code)，是編碼成兩個連續的不同位元
// 其編碼規則如下
// G_1 = {0, 1}
// G_1_r = {1, 0}
// G_n = {0G_(n-1), 1G_(n-1)_r }
// [G_n_r 是 G_n 的逆向順序]
// 例 :
// G_2 = {0G_1, 1G_1_r} = {00, 01, 11, 10}
// G_2_r = {10, 11, 01, 00}

// -------------
// 輸入說明 :
// 第一行是一個測試案例資料，整數 n k
// n代表Gray code的位元數
// k代表G_n中的第幾個元素(從0開始)
// 接著是一行 0 分隔測試資料
// 第三行是第二個測試案例資料
// ....
// 最後 -1 結束

// -------------
// 輸出說明 :
// 二進位 Gray code
// 每一行是一個測試案例資料的結果

// -------------
// Sample Input:
// 1 1
// 0
// 2 3
// 0
// 3 6
// 0
// 4 12
// -1
// -------------
// Sample Output:
// 1
// 10
// 101
// 1010

// -------------
// Sample Input:
// 5 3
// 0
// 6 10
// -1
// -------------
// Sample Output:
// 00010
// 001111

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char *decimalToBinaryNumber(int x, int n)
{
    int *binaryNumber = malloc(sizeof(int));
    char *output = (char *)malloc(sizeof(char) * (n+1));
    int currentIndex = 0;
    int i = 0;
    while (x > 0)
    {
        binaryNumber[i] = x % 2;
        x = x / 2;
        i++;
    }

    for (int j = 0; j < n - i; j++)
    {
        output[currentIndex] = '0';
        currentIndex = currentIndex + 1;
    }
    

    for (int j = i - 1; j >= 0; j--)
    {
        output[currentIndex] = binaryNumber[j] + '0';
        currentIndex = currentIndex + 1;
    }
    output[currentIndex] = '\0';
    return output;
}

void g(int *list, int n)
{
    for (int i = pow(2, n-1); i < pow(2, n); i++)
    {
        int t = pow(2, n)-i-1;
        list[i] = list[t] + pow(2, n-1);
    }
}

int main()
{
    int n, k, j=0;
    int list[99999], result1[99999], result2[99999];
    list[0] = 0;
    list[1] = 1;
    
    while (true)
    {
        int ha = 0;
        scanf("%d %d\n", &n, &k);
        scanf("%d", &ha);
        
        for (int i = 2; i <= n; i++)
        {
            g(list, i);
        }
        result1[j] = list[k];
        result2[j] = n;
        j++;
        if (ha == -1)
            break;
    }
    for (int i = 0; i < j; i++)
    {
        printf("%s\n", decimalToBinaryNumber(result1[i], result2[i]));
    }
}