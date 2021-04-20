// 015 大數相加

// 輸入大數運算的模式，
// 以1代表大數相加；2代表大數相減；3代表大數相乘。
// 再輸入兩個20位數以上的整數做運算，
// 並輸出計算過後的結果。

// sample input:
// 1
// 10000000000000000001
// 99999999999999999999

// sample output:
// 110000000000000000000

// --------------------------------

// sample input:
// 2
// 10000100001000010000
// 100001000010000100001

// sample output:
// -90000900009000090001

// --------------------------------

// sample input:
// 3
// 10000100000000000001
// 12121212121212121212

// sample output:
// 121213333333333333344242412121212121212

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int toInt(char c)
{
    return c - '0';
}

int getA(int i)
{
    return i % 10;
}

int getAA(int i)
{
    return i / 10;
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

int bigger(char num1[], char num2[])
{
    for (int i = 0; i < getN(num1); i++)
    {
        if (toInt(num1[i]) < toInt(num2[i]))
        {
            return false;
        }
        else if (toInt(num1[i]) > toInt(num2[i]))
        {
            return true;
        }
    }
    return true;
}

char toChar(int i)
{
    return i + '0';
}

char* reverse(char *src)
{
    char *c = malloc(sizeof(char) * (getN(src) + 1));
    int index = 0;
    for (int i = getN(src); i > 0; i--)
    {
        c[index] = src[i - 1];
        index++;
    }
    c[index] = '\0';
    return c;
}

char *addLeftZero(char *c, int n)
{
    int i;
    char *cc = malloc(sizeof(char) * 999);
    for (i = 0; i < (n - getN(c)); i++)
    {
        cc[i] = '0';
    }
    for (i = (n - getN(c)); i < n; i++)
    {
        cc[i] = c[i - (n - getN(c))];
    }
    cc[n] = '\0';
    return cc;
}

char *addRightZero(char *c, int n)
{
    int i;
    char *cc = malloc(sizeof(char) * 999);
    for (i = 0; i < getN(c); i++)
    {
        cc[i] = c[i];
    }
    for (i = getN(c); i < n; i++)
    {
        cc[i] = '0';
    }
    cc[n] = '\0';
    return cc;
}

char *add(char num1[], char num2[])
{
    char *c = malloc(sizeof(char) * 999);
    for (int i = 0; i < 999; i++)
    {
        c[i] = '\0';
    }
    int temp = 0;
    int index = 0;
    for (int i = getN(num1); i > 0; i--)
    {
        int a = toInt(num1[i - 1]);
        int b = toInt(num2[i - 1]);
        c[index] = toChar(getA(a + b + temp));
        temp = getAA(a + b + temp);
        index++;
    }
    if (temp != 0)
    {
        c[index] = toChar(temp);
    }
    return c;
}

char *subtract(char num1[], char num2[])
{
    char *c = malloc(sizeof(char) * 999);
    for (int i = 0; i < 999; i++)
    {
        c[i] = '\0';
    }
    int temp = 0;
    int index = 0;
    for (int i = getN(num1); i > 0; i--)
    {
        int a = toInt(num1[i - 1]);
        int b = toInt(num2[i - 1]);
        if ((a - temp) >= b)
        {
            c[index] = toChar(a - b - temp);
            temp = 0;
        }
        else
        {
            c[index] = toChar(a + 10 - b - temp);
            temp = 1;
        }
        index++;
    }
    for (int i = index - 1; i > 0; i--)
    {
        if (c[i] == '0')
        {
            c[i] = '\0';
        }
        else
        {
            break;
        }
    }
    return c;
}

char *multiply(char *num1, char *num2)
{
    // char *c = malloc(sizeof(char) * 999);
    // for (int i = 0; i < 999; i++)
    // {
    //     c[i] = '\0';
    // }
    
    // int zero = 0;
    // int index;
    // for (int j = getN(num1); j > 0; j--)
    // {
    //     index = 0;
    //     int temp = 0;
    //     int b = toInt(num2[j - 1]);
    //     char *c_temp = malloc(sizeof(char) * 999);
    //     for (int i = 0; i < 999; i++)
    //     {
    //         c_temp[i] = '\0';
    //     }

    //     for (int i = getN(num2); i > 0; i--)
    //     {
    //         int a = toInt(num1[i - 1]);
    //         c_temp[index] = toChar(getA(b * a + temp));
    //         temp = getAA(b * a + temp);
    //         index++;
    //     }
    //     if (temp != 0)
    //     {
    //         c_temp[index] = toChar(temp);
    //     }
    //     c_temp = addRightZero(reverse(c_temp), getN(c_temp) + zero);
    //     c = addLeftZero(c, getN(c_temp));

    //     c = reverse(add(c, c_temp));

    //     zero++;
    // }
    // c = reverse(c);
    // for (int i = getN(c) - 1; i > 0; i--)
    // {
    //     if (c[i] == '0')
    //     {
    //         c[i] = '\0';
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // return c;
}

int main()
{
    int i;
    char *a = malloc(sizeof(char) * 999), *b = malloc(sizeof(char) * 999), *c;
    scanf("%d", &i);
    getchar();
    scanf("%s", a);
    getchar();
    scanf("%s", b);
    getchar();
    if (getN(a) > getN(b))
        b = addLeftZero(b, getN(a));
    else
        a = addLeftZero(a, getN(b));
    switch (i)
    {
    case 1:
        c = reverse(add(a, b));
        printf("%s", c);
        break;
    case 2:
        if (bigger(a, b))
        {
            c = reverse(subtract(a, b));
            printf("%s", c);
        }
        else
        {
            c = reverse(subtract(b, a));
            printf("-%s", c);
        }
        break;
    case 3:
        c = reverse(multiply(a, b));
        printf("%s", c);
        break;
    default:
        break;
    }
    return 0;
}