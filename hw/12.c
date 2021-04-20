// 012
// 分數四則運算

// 計算兩個分數四則運算 。

// 輸入說明:
// ----------------------------
// 輸入四行，第一、二行各代表一個分數，第三行代表數學運算符號(+-*/)，第四行代表是否繼續運算(y表示繼續運算、n表示不繼續運算)

// --------------------
// 輸出說明:
// ----------------------------
// 輸出分數結果

// **輸入分子可能大於分母**
// 若有輸入分數的分母為0，則輸出ERROR。
// 若分數大於1，則分數部分要加括號，如一又六分之一輸出為1(1/6)
// 若為負數，負號在最前面。
// 若輸出為0，則顯示0
// 輸出的結果必須化簡為最簡分數
// ----------------
// Sample input:
// ----------------
// 1/2
// 2/3
// +
// y
// -1/4
// 1/5
// *
// n


// ----------------
// Sample output:
// ----------------
// 1(1/6)
// -1/20



// ----------------
// Sample input:
// ----------------
// 2/0
// 2/3
// -
// n


// ----------------
// Sample output:
// ----------------
// ERROR

#include <stdio.h>
#include <math.h>

int func(int m, int n) //求最大公因數
{
    int tmp;
    m = abs(m);
    n = abs(n);
    if (m == n)
        return m;
    if (m < n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    while (m % n != 0)
    {
        tmp = m;
        m = n;
        n = tmp % n;
    }
    return n;
}

void add(int *n, int *d, int n1, int d1, int n2, int d2)
{
    int x = func(d1, d2);
    *d = d1 * d2 / x;
    *n = n1 * (*d / d1) + n2 * (*d / d2);
}

void reduce(int *n, int *d, int n1, int d1, int n2, int d2)
{
    int x = func(d1, d2);
    *d = d1 * d2 / x;
    *n = n1 * (*d / d1) - n2 * (*d / d2);
}

void multiply(int *n, int *d, int n1, int d1, int n2, int d2)
{
    *d = d1 * d2;
    *n = n1 * n2;
}

void divide(int *n, int *d, int n1, int d1, int n2, int d2)
{
    *d = d1 * n2;
    *n = n1 * d2;
}

int main()
{
    int numerator1, denominator1, numerator2, denominator2, n, d, i = 0;
    int result1[999], result2[999];
    char c, ha = 'y';
    while (ha == 'y')
    {
        scanf("%d/%d\n", &numerator1, &denominator1);
        scanf("%d/%d\n", &numerator2, &denominator2);
        scanf("%c", &c);
        getchar();
        scanf("%c", &ha);

        if (denominator1 != 0 && denominator2 != 0)
        {
            switch (c)
            {
            case '+':
                add(&n, &d, numerator1, denominator1, numerator2, denominator2);
                break;
            case '-':
                reduce(&n, &d, numerator1, denominator1, numerator2, denominator2);
                break;
            case '*':
                multiply(&n, &d, numerator1, denominator1, numerator2, denominator2);
                break;
            case '/':
                divide(&n, &d, numerator1, denominator1, numerator2, denominator2);
                break;
            default:
                break;
            }

            if (n != 0)
            {
                int x = func(abs(d), abs(n));
                d = d / x;
                n = n / x;
            }
            result1[i] = n;
            result2[i] = d;
        }
        else
        {
            result1[i] = 0;
            result2[i] = 0;
        }
        i++;
    }
    
    for (int x = 0; x < i; x++)
    {
        if (result1[x] == 0 && result2[x] == 0)
            printf("ERROR\n");
        else if (result1[x] == 0)
            printf("0\n");
        else if ((result1[x] % result2[x]) == 0)
            printf("%d\n", result1[x] / result2[x]);
        else
        {
            int n;
            if (result2[x] < 0)
                printf("-%d/%d\n", abs(result1[x]), abs(result2[x]));
            else if (abs(result1[x]) > abs(result2[x]))
            {
                n = result1[x] / result2[x];
                result1[x] = result1[x] % result2[x];
                printf("%d(%d/%d)\n", n, abs(result1[x]), result2[x]);
            }
            else
                printf("%d/%d\n", result1[x], result2[x]);
        }
    }

    return 0;
}