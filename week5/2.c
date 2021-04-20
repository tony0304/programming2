#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    int *num = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        *(num + i) = i * 3;
    p = num;
    p++;
    printf("%d, ", (*p)++); // p 值不會變，1變2
    printf("%d, ", ++(*p)); // p 值不會變，2變3
    printf("%d, ", *(p++)); // p 值會變，指向下一個，再取值
    printf("%d, ", *p++);   //要看 * 或 ++哪一個運算子優先
    free(num);
}