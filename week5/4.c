#include <stdio.h>
#include <stdlib.h>

void function(int **a, int **b, int **c, int *d)
{
    *a=d;
    **b=(**a)/(**c);
    *d=(**b)*(**a);
}

void s(int **a, int **b, int **c, int *d)
{
    int **temp=a;
    a=b;
    b=temp;
    *a=d;
    (**a)=(**b)+(**c);
}

void main(void)
{
    int i=5, j=-2, k=9, *p=&i, *q=&j, *x=&k;
    s(&p, &q, &x, &k);
    printf("%d%d%d", i, j, k);
}