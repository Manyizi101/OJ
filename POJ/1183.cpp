#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned int m, n, a, sum;
    while (scanf("%d", &a) != EOF)
    {
        for (m = a; ; m++)
            if ((a * a + 1) % m == 0)
                break;
        n = (a * a + 1) / m;
        sum = 2 * a + m + n;
        printf("%d\n", sum);
    }
    return 0;
}