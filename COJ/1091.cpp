#include  <stdio.h>
#include  <math.h>
#include  <string.h>

int main()
{
    char type[10];
    int n,i,j,k,tmp;
    int data[100];
    memset(data,0,100);
    scanf("%s", type);
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &data[i]);
    }
    if(type[0]=='F')
    {
        for(j=0; j<n; j++)
        {
            for(k=n-1; k>j; k--)
            {
                if(data[i]>data[k])
                {
                    tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }
        }
        printf("%d", data[0]);
    }
    if(type[0]=='H'||type[0]=='S')
    {
        for(j=0; j<n; j++)
        {
            for(k=n-1; k>j; k--)
            {
                if(data[j]<=data[k])
                {
                    tmp = data[k];
                    data[k] = data[j];
                    data[j] = tmp;
                }
            }
        }
        printf("%d", data[0]);
    }
    return 0;
}
