#include <stdio.h>

int f(int x) {
if (x<0) return 1;
return g(x-1)+1;
}
int g(int y) {
if (y<0) return 2;
return f(y-1)+1;
}

int main() {
    int x=f(6);
    int y=g(5);
    printf("%d%d", x, y);
}