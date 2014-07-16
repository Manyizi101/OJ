#include <cstdio>
using namespace std;

int num[6] = {0};
int value[6] = {1, 2, 3, 4, 5, 6};
int mod[6] = {60, 30, 20, 15, 12, 10};
int t = 0;
int cp[6] = {0};

int divide(int a)
{
    if (a == 0) return 1;
    for (int i = 5; i >= 0; --i)
    {
        if (cp[i] && a >= value[i])
        {
            cp[i]--;
            if (divide(a - value[i]) == 1) return 1;
            cp[i]++;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int sum = 0;
        for (int i = 0; i < 6; ++i)
        {
            scanf("%d", &num[i]);
            num[i] = num[i] % mod[i];
            sum += value[i] * num[i];
            cp[i] = num[i];
        }
        if (!sum) break;
        printf("Collection #%d:\n", ++t);
        if (sum % 2 != 0) printf("Can't be divided.\n");
        else
        {
            sum = sum / 2;
            if (divide(sum)) printf("Can be divided.\n");
            else printf("Can't be divided.\n");
        }
        printf("\n");
    }
    return 0;
}