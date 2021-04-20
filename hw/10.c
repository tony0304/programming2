// 010
// 數位電路模擬I
// 模擬一個數位IC，內有回饋電路與紀錄器電路
// 輸入m 是二進位 8 位元，輸出是二進位 4 位元
// 輸入範圍從 00000000 到 11111111 (十進位 0~255)
// 回饋方式為 :
// C(m) = m if m = 0 or m = 1 (十進位)
// C(m) = C(m/2) if m 偶數(十進位)
// C(m) = C((m+1)/2) if m 奇數(十進位)
// 例 :
// m=00001010(十進位 10)，則電路回饋依序為十進位 5, 3, 2, 1
// C(10)= C(5)=C(3)=C(2)=C(1)=1，共回饋 4 次
// 紀錄器會記錄回饋電路的回饋次數
// R(m) = [C(m) 的回饋次數]，例如 R(10) = 4
// 若數位IC的輸入為m=00001010(十進位 10) ，因回饋電路的回饋次數為4，則此數位IC輸出為 0100 (十進位 4)

// -------------
// 輸入說明 :
// 二進位 8 bit 位元
// 第一行是第一個測試案例資料
// 接著是一行 0 分隔測試資料
// 第三行是第二個測試案例資料
// ....
// 最後 -1 結束

// -------------
// 輸出說明 :
// 二進位 4 bit 位元
// 每一行是一個測試案例資料的結果

// -------------
// Sample Input:
// 00000000
// 0
// 11111111
// 0
// 00000001
// 0
// 10000000
// 0
// 00111111
// -1
// -------------
// Sample Output:
// 0000
// 1000
// 0000
// 0111
// 0110

// -------------
// Sample Input:
// 00001010
// 0
// 01100100
// -1
// -------------
// Sample Output:
// 0100
// 0111

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

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

int get(int input)
{
    int i = 0;
    while (input>1)
    {   
        if (input % 2 != 0) input += 1;
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
        out += (c[i] - '0') * pow(2, 7-i);
    }
    return out;
}

int main()
{
    char c[9];
    int out = 0, i = 0, result[999];
    

    while (true)
    {
        int ha = 0;
        scanf("%s\n", c);
        scanf("%d", &ha);

        result[i] = get(binaryToInt(c));
        i++;
        if (ha == -1)
            break;
    }

    for (int x = 0; x < i; x++)
    {
        printf("%s\n", decimalToBinaryNumber(result[x], 4));
    }
    
    return 0;
}