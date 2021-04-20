#include <stdio.h>

int h(int N) {
    if (N<0) return -1;
    if (N<10) return N;
    return N%10+h(N/10);
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", h(a));
}