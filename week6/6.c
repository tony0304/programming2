#include <stdio.h>

int binarySearch(int d[], int left, int right, int key)
{
    int mid = 0;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (d[mid] == key) return mid;
        else if (d[mid] > key)
        {
            printf("0");
            right = mid;
        }
        else left = mid;
    }
    return -1;
}

int main()
{
    int data[] = {1, 2, 5, 7, 9, 14, 23, 26};
    printf("%d, %d\n", binarySearch(data, 0, 7, 9), 9);
    return 0;
}