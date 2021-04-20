// 013
// 輸入平面上兩個點，求直線方程式
// 輸入兩點座標，(x1, y1), (x2, y2)
// 輸出 y = mx + b(其中，m=(y1-y2)/(x1-x2)、b = (x2y1-x1y2)/(x2-x1))
// 註:1.不考慮斜率不存在的問題 2.若m與b為分數,表示方式同第12題

// ex:
// input:
// 1,0
// 0,-1

// output:
// y=x-1

// -------------

// input:
// 1,0
// 0,1

// output:
// y=-x+1

#include <stdio.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2, m1, m2, b1, b2;
    scanf("%d,%d", &x1, &y1);
    getchar();
    scanf("%d,%d", &x2, &y2);
    getchar();
    m1 = y1 - y2;
    m2 = x1 - x2;
    b1 = x2 * y1 - x1 * y2;
    b2 = x2 - x1;

    if (m1 == 0)
        printf("y=");
    else if ((m1 % m2) == 0)
    {
        if ((m1 / m2) == 1)
            printf("y=x");
        else if ((m1 / m2) == -1)
            printf("y=-x");
        else
            printf ("y=%dx", m1 / m2);
    }
    else
    {
        int n;
        if (m1 < 0 && m2 < 0)
            printf("y=%d/%dx", abs(m1), abs(m2));
        else if (m2 < 0)
            printf("y=-%d/%dx", abs(m1), abs(m2));
        else if (abs(m1) > abs(m2))
        {
            n = m1 / m2;
            m1 = m1 % m2;
            printf("y=%d(%d/%d)x", n, abs(m1), m2);
        }
        else
            printf("y=%d/%dx", m1, m2);
    }

    if ((b1 % b2) == 0)
    {
        if ((b1 / b2) > 0)
            printf("+%d\n", b1 / b2);
        else if ((b1 / b2) < 0)
            printf("%d\n", b1 / b2);
    }
    else
    {
        int n;
        if (b2 < 0)
            printf("-%d/%d\n", abs(b1), abs(b2));
        else if (abs(b1) > abs(b2))
        {
            n = b1 / b2;
            b1 = b1 % b2;
            printf("%d(%d/%d)\n", n, abs(b1), b2);
        }
        else
            printf("%d/%d\n", b1, b2);
    }

    return 0;
}