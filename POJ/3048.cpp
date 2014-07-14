#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int p[4000], pNum = 0;
bool f[20001];
void Prime()
{
    int i, j;
    for (i = 2; i < 20001; i++)
    {
        if (!f[i])
        {
            p[pNum++] = i;
        }
        for (j = 0; j < pNum && i * p[j] < 20001; j++)
        {
            f[i * p[j]] = 1;
            if (!(i % p[j])) break;
        }
    }
}
int main()
{
    int i, n, t, mmax = -1, pos;
    scanf("%d", &n);
    Prime();
    while (n--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            if (mmax < 1)
            {
                mmax = 1;
                pos = 1;
            }
        }
        else
        {
            for (i = pNum - 1; i >= 0; i--)
            {
                if (t >= p[i] && t % p[i] == 0)
                {
                    if (mmax < p[i])
                    {
                        mmax = p[i];
                        pos = t;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", pos);
}