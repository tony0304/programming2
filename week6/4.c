#include <stdio.h>
#include <string.h>

void tran(int x, char *data)
{
    int temp;
    int a = 0;
    char cc[4];
    for (int i = 3; i >= 0; i--)
    {
        char c;
        int temp = x % 16;
        switch (temp)
        {
        case 10:
            c = 'A';
            break;
        case 11:
            c = 'B';
            break;
        case 12:
            c = 'C';
            break;
        case 13:
            c = 'D';
            break;
        case 14:
            c = 'E';
            break;
        case 15:
            c = 'F';
            break;
        default:
            c = temp + '0';
            break;
        }
        data[i] = c;
        x = x / 16;
    }
    data[4] = '\0';
}

int main()
{
    int i;
    char c[5];
    scanf("%d", &i);
    tran(i, c);
    printf("%s", c);
    return 0;
}

// for (i = 0; i &lt; = b[0]; i++)

// {
//     a[i] = b[i] % 16;

//     b[i + 1] = b[i] / 16;

//     y = y + 1;

//     if (b[i + 1] == 0)
//     {
//         break;
//     }
// }

// for (j = y - 1; j &gt; = 0; j--)

// {
//     x = a[j];

//     switch (x)

//     {
//     case 10:
//         printf(&quot; A & quot;);
//         break;

//     case 11:
//         printf(&quot; B & quot;);
//         break;

//     case 12:
//         printf(&quot; C & quot;);
//         break;

//     case 13:
//         printf(&quot; D & quot;);
//         break;

//     case 14:
//         printf(&quot; E & quot;);
//         break;

//     case 15:
//         printf(&quot; F & quot;);
//         break;

//     default:
//         printf(&quot; % d & quot;, a[j]);
//         break;
//     }
// }