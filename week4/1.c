#include <stdio.h>

void f3(int *a, int *b, int *c)
{
    int *temp=a;
    *b=(*c)*(*temp);
    (*c)=(*temp);
    (*a)=3;
    a=b;
    b=c;
    c=temp;
    printf("%d, %d\n", *c, *b);
    printf("%d, %d\n", *a, *temp);
}

void main()
{
    int i=0, j=1, k=2, *p=&i, *q=&j;
    f3(p, q, &k);
    printf("%d, %d\n", i, j);
    printf("%d\n", k);
}