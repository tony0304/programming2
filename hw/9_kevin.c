#include <stdio.h>
#include <stdlib.h>

char *decimalToBinaryNumber(int x, int n)
{
    int *binaryNumber = malloc(sizeof(x));
    char *output = (char *)malloc(sizeof(char) * n);
    int currentIndex = 0;
    int i = 0;
    while (x > 0)
    {
        binaryNumber[i] = x % 2;
        x = x / 2;
        i++;
    }

    for (int j = 0; j < n - i; j++)
    {
        output[currentIndex] = '0';
        currentIndex = currentIndex + 1;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        output[currentIndex] = binaryNumber[j] + '0';
        currentIndex = currentIndex + 1;
    }
    return output;
}

void generateGrayarr(int n, int k)
{
    int x = k ^ (k >> 1);
    char *result = decimalToBinaryNumber(x, n);
    printf("%s", result);
    printf("%s", "\n");
}

int main()
{
    while (1)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        generateGrayarr(n, k);
    }
    return 0;
}