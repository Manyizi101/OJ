#include <stdio.h>

using namespace std;

#define P 23
#define E 28
#define I 33
#define C 21252

int main(void)
{
    int p, e, i, d;
    int x;

    int flag = 1;
    while (scanf("%d %d %d %d", &p, &e, &i, &d)&&p>=0)
    {
        p %= P;
        e %= E;
        i %= I;
        x = i;

        while (!((x - p) % P == 0 && (x - e) % E == 0))
        {
            x += I;
        }

        x -= d;
        if (x <= 0) x += C;
        printf("Case %d: the next triple peak occurs in %d days.\n", flag, x);
        flag++;
    }

    return 0;
}