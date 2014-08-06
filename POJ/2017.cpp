#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF, n != -1)
    {
        int t1 = 0, t2 = 0, v = 0;
        int sumLen = 0;
        int i;
        for (i = 0; i < n; ++i)
        {
            t1 = t2;
            scanf("%d%d", &v, &t2);
            sumLen += (t2 - t1) * v;
        }
        printf("%d miles\n", sumLen);
    }
    return 0;
}