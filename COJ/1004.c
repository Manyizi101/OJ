
#include   <stdio.h>
#include   <math.h>

int main()
{
    int k, n;
    int length = 0;
    int i, data[10000] = {0};
    scanf("%d%d", &n, &k);
    data[0] = (pow(n, 1) - (int)(pow(n, 1)/pow(10, k))*pow(10, k)) / pow(10 ,k-1);
    for(i = 1; i < 1500; i++)
    {
        data[i] = (pow(n, i+1) - (int)(pow(n, i+1)/pow(10, k))*pow(10, k)) / pow(10 ,k-1);
        length += 1;
        if(data[i] == data [0])
        {
            printf("%d", length);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
