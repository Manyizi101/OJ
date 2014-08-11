#include <stdio.h>

int main(int argc, char const *argv[])
{
    __int64 x[46] = {0, 2, 3, 5, 8,};
    int T, i, ans, a, c = 1;
    scanf("%d", &T);
    for (i = 5 ; i  < 46; ++i)
        x[i] = x[i - 1] + x[i - 2];
    do
    {
        scanf("%d", &a);
        printf("Scenario #%d:\n", c++);
        printf("%I64d\n\n", x[a]);
    }
    while (--T);

    return 0;
}