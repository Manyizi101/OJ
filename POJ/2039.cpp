#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[210];
int N;
int i, j;
int len, M;

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N), N != 0)
    {
        getchar();
        gets(str);
        len = strlen(str);
        M = (int)((double)N / (double)len + 0.999999);
        for (i = 0; i < N; i++)
        {
            for (j = 0; j * N < len; j++)
            {
                if (j % 2 == 0)
                {
                    printf("%c", str[N * j + i]);
                }
                else if (j % 2 == 1)
                {
                    printf("%c", str[N * (j + 1) - 1 - i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}