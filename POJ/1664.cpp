#include <iostream>
#include <stdio.h>
using namespace std;

int apple(int m, int n )
{
    if (m == 0 || n == 1)
        return 1;
    if (m < n)
        return apple(m, m);
    return apple(m - n, n) + apple(m, n - 1);
}

int main(int argc, char const *argv[])
{
    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        printf("%d\n", apple(m, n));
    }
    return 0;
}