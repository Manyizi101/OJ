#include <cstdio>
#include <cstdlib>

int field[300][300];
int N, B, K;
int X, Y;
int i, j;
int min, max, tmp;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &N, &B, &K);
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &field[i][j]);
        }
    }
    while (K --)
    {
        scanf("%d%d", &X, &Y);
        min = max = field[X][Y];
        for (i = X; i < X + B; i++)
        {
            for (j = Y; j < Y + B; j++)
            {
                if (min > field[i][j])
                {
                    min = field[i][j];
                }
                if (max < field[i][j])
                {
                    max = field[i][j];
                }
            }
        }
        printf("%d\n", max - min);
    }
    return 0;
}
