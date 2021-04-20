#include <stdio.h>

void f2(int a, int *b, int *c)
{
    int d=0;
    a+=(*b)++;
    c = &a;
    d = (*c)+1;
    b=&d;
    printf("%d, %d\n", a, *b);
    printf("%d, %d\n", *c, d);
}

void main()
{
    int a = 0, b= 1, c=2, d=3;
    f2(a, &b, &c);
    printf("%d, %d\n", a, b);
    printf("%d, %d\n", c, d);
}