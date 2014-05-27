#include   <stdio.h>
#include   <math.h>

int judge(long long int x)
{
    long long int key = 0, result = 0;
    for (key = 2; key <= sqrt(x*1.0); key++)
    {
        if (x%key == 0)   return result = 1;
    }
    return result = 0;
}

int main()
{
    long long int i = 2, k;
    while(scanf("%I64d", &k) != EOF)
    {
        if (k == 1) printf("1 ");
        for (i = 2; i < pow(2, 21); i++)
        {
            int a = judge(i);
            while (a == 0 && i <= k && k % i == 0)
            {
                printf("%I64d ", i);
                k = k / i;
            }
            if(k == 1)     break;
        }
        printf("\n");
    }
    return 0;
}
