#include <stdio.h>

void merge(int C[], int A[], int am, int an, int B[], int bm, int bn)
{
    int k = am;
    while ((am <= an) && (bm <= bn))
    {
        if (A[am] <= B[bm]) C[k++] = A[am++];
        else C[k++] = B[bm++];
    }
    printf("%d %d %d", C[1], C[4], C[6]);
    while (am <= an) C[k++] = A[am++];
    while (bm <= bn) C[k++] = B[bm++];
}

int main()
{
    int c[10];
    int X[] = {12, 17, 23, 56, 11, 17, 34, 38, 67};
    merge(c, X, 0, 3, X, 4, 8);
    return 0;
}