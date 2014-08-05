#include<stdio.h>

const int maxn = 100000;

int main(int argc, char const *argv[])
{
    int s;
    while (scanf("%d", &s) != EOF)
    {
        int sum = 0;
        int i;
        for (i = 1; i < maxn; i++)
        {
            sum = (1 + i) * i / 2;
            if (sum >= s) break;
        }
        int index = i;

        for (;;)
        {
            sum = (1 + index) * index / 2;
            if ((sum - s) % 2 == 0)
            {
                printf("%d\n", index);
                break;
            }
            index++;
        }
    }
    return 0;
}
