// 011
// 數位電路模擬II
// 模擬一個數位IC，內有回饋電路與紀錄器電路
// 輸入m 是二進位 8 位元，輸出是二進位 11 位元
// 輸入範圍從 00000000 到 11111111 (十進位 0~255)
// 回饋方式為 :
// C(m) = m if m = 0 or m = 1 (十進位)
// C(m) = C(m/2) if m 偶數(十進位)
// C(m) = C((m+1)/2) if m 奇數(十進位)
// 例如 m=00001010(十進位 10)，則電路回饋依序為十進位 5, 3, 2, 1
// C(10)= C(5)=C(3)=C(2)=C(1)=1，共回饋 4 次
// 紀錄器功能如下 :
// 給予回饋電路輸入 0, 1, 2, ..., m，並記錄每次回饋次數，R(0), R(1), ..., R(m)。例如R(10)=4 [C(10)的回饋次數]
// 會累加所有回饋電路的回饋次數。Out(10) = R(0)+R(1)+...+R(10)

// -------------
// 輸入說明:
// 二進位 8 bit 位元
// 第一行是第一個測試案例資料
// 接著是一行 0 分隔測試資料
// 第三行是第二個測試案例資料
// ....
// 最後 -1 結束

// -------------
// 輸出說明:
// 二進位 11 bit 位元
// 每一行是一個測試案例資料的結果

// -------------
// Sample Input:
// 00000000
// 0
// 11111111
// 0
// 10101010
// -1
// -------------
// Sample Output:
// 00000000000
// 11011111001
// 10001010001

// -------------
// Sample Input:
// 00001010
// 0
// 01100100
// -1
// -------------
// Sample Output:
// 00000011001
// 01000111101

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

void bin(char *arr1, int x)
{
    if (x >= 0 && x <= 2047)
    {
        for (int i = 11 - 1; i >= 0; i--)
        {
            if (x % 2 == 0)
            {
                arr1[i] = '0';
            }
            else
            {
                arr1[i] = '1';
            }
            x = x / 2;
        }
    }
    arr1[11] = '\0';
}

int get(int input)
{
    int i = 0;
    while (input > 1)
    {
        if (input % 2 != 0)
            input += 1;
        input = input / 2;
        i++;
    }
    return i;
}

int binaryToInt(char c[])
{
    int out = 0;
    for (int i = 7; i >= 0; i--)
    {
        out += (c[i] - '0') * pow(2, 7 - i);
    }
    return out;
}

int main()
{
    char c[9], arr[12];
    int out = 0, i = 0, result[999] = {0};

    while (true)
    {
        int ha = 0;
        scanf("%s\n", c);
        scanf("%d", &ha);
        int temp = binaryToInt(c);
        for (int t = 0; t <= temp; t++)
        {
            result[i] += get(t);
        }
        
        i++;
        if (ha == -1) break;
    }

    for (int x = 0; x < i; x++)
    {
        bin(arr, result[x]);
        printf("%s\n", arr);
    }
    return 0;
}