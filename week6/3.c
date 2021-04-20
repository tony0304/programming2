#include <stdio.h>
#include <string.h>

int check(char data[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (data[i] == data[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    char c[4];
    scanf("%s", &c);
    printf("%s", c);
    printf("%d", check(c));
    return 0;
}