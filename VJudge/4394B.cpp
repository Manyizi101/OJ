#include<stdio.h>
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4, n, m, flag;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while (n--)
    {
        flag = 0;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if (x1 > x2)
        {
            m = x1;
            x1 = x2;
            x2 = m;
        }
        if (y1 > y2)
        {
            m = y1;
            y1 = y2;
            y2 = m;
        }
        if (y3 > y4)
        {
            m = y3;
            y3 = y4;
            y4 = m;
        }
        if (x3 > x4)
        {
            m = x3;
            x3 = x4;
            x4 = m;
        }
        if (y4 < y1 || x3 > x2 || y3 > y2 || x4 < x1)
        {
            printf("Miss\n");
        }
        else
            printf("Hit\n");
    }
    return 0;

}