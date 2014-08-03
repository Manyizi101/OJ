#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--)
    {
        int a, b, c, d, e;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (b - a == c - b && c - b == d - c)e = d + d - c;
        else e = d * d / c;
        printf("%d %d %d %d %d\n", a, b, c, d, e);
    }
    return 0;
}