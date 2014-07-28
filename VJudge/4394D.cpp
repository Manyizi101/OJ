#include<stdio.h>
using namespace std;

int a, b, c, d;

int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d%d", &a, &b, &c, &d) && (a != 0 || b != 0 || c != 0 || d != 0))
    {
        if ((2 * c - b) > a || (2 * c - b) < 0)
        {
            if (c > b)
                printf("%d\n", a - (2 * c - b - a));
            else
                printf("%d\n", 0 - (2 * c - b));
        }
        else
            printf("%d\n", 2 * c - b);
    }
    return 0;
}