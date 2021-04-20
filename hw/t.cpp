#include <iostream>
using namespace std;
 
int width, idx, temp=0, nelson[4] = {0, 1, 4, 5}, nelson2[4] = {0, 2, 8, 10};
int data[16], pict[4][4];
string s;
 
void func(int w)
{
    idx++;
    if (s[idx] == '0')
    {
        for (int i = 0; i < w * w; i++)
        {
            data[temp] = 0;
            temp++;
        }
    }
    else if (s[idx] == '1')
    {
        for (int i = 0; i < w * w; i++)
        {
            data[temp] = 1;
            temp++;
        }
    }
    else if (s[idx] == '2')
    {
        w = w / 2;
        for (int i = 0; i < 4; i++)
        {
            func(w);
        }
        w = w * 2;
    }
}

void haha()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (data[nelson[j] + nelson2[i]] == 1)
            {
                printf("%d,%d\n", i, j);
            }
        }
    }
}

int main()
{
    cin >> s;
    cin >> width;
    idx = -1;
    func(width);
    // for (int i = 0; i < 16; i++)
    // {
    //     printf("%d", data[i]);
    // }
    haha();
}