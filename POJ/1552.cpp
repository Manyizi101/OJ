#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int list[25];

int main(int argc, char const *argv[])
{
    int i, j, len;
    int sum;
    int num;

    while (scanf("%d", &num), num != -1)
    {
        for (i = 0; num != 0; i++)
        {
            list[i] = num;
            scanf("%d", &num);
        }
        len = i;
        sort(list, list + len);
        for (i = sum = 0; i < len; i++)
        {
            for (j = i; j < len; j++)
            {
                if (list[i] * 2 == list[j])
                {
                    sum++;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}