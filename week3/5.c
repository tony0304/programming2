#include <stdio.h>
#include <math.h>

void f(int A,int *B,int *C){
    printf("%p\n", &C);
    int d;
    A = 2;
    *B = 3;
    C = &A;
    printf("%p\n%p", &A, C);
    d = 5;
    // printf("%d", *c);
    // printf("%p\n %p\n", &a, &c);
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main(){
    // int a=1, b=2, c=3, d=4;
    // printf("%p\n", &b);
    // printf("%p\n", &c);
    // f(a, &b, &c);


    int a = 2;
    int b = 3;
    printf("%d", convertBinaryToDecimal(a));
    // print_bin(a);
    // printf("%p\n", &b);
    // printf("%p\n", &c);
    return 0;
}