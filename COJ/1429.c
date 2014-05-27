#include  <stdio.h>

int main()
{
    long int n;
    while(scanf("%ld", &n)!= EOF)
    {
        int a[n], b[n], i, j=0, key=0, num=0;
        for(i=0; i<n; i++)  scanf("%d", &a[i]);
        for(i=0; i< n; i++)
        {
            if(a[i]%2==0)
            {
                b[j] =  a[i];
                j++;
                num = j;
            }
        }
        for(i = 0; i < num; i++)
        {
            for(j = num-1; j>i; j--)
            {
                if(b[i] < b[j])
                {
                    key = b[i];
                    b[i] = b[j];
                    b[j] = key;
                }
            }
        }
        for(i = 0; i < num; i++)
        {
            if(i!=num-1)    printf("%d ", b[i]);
            if(i==num-1)    printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
