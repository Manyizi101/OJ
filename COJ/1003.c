/*
#include <stdio.h>


int main()
{
    int i, j, key, T, M = 0;
    int sum_worth = 0, sum_time = 0;
    int time[100], worth[100];
    float choose[100];
    scanf("%d%d", &T, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d%d", &time[i], &worth[i]);
        choose[i] = (float)(worth[i]) / (float)(time[i]);
    }
    for (i = 0; i < M; i++)
    {
        for (j = M; j > i; j--)
        {
            if (choose[i] < choose[j])
            {
                key = worth[i];
                worth[i] = worth[j];
                worth[j] = key;
                key = time[i];
                time[i] = time[j];
                time[j] = key;
            }
        }
    }
    for (i = 0; i < M; i++)
    {
        sum_time += time[i];
        if (sum_time <= T)       sum_worth += worth[i];
        if (sum_time > T)       sum_time -= time[i];
    }
    printf("%d", sum_worth);
    return 0 ;
}
**/

#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int a[1001];
    int T,M;
    scanf("%d%d",&T,&M);
    memset(a,0,sizeof(a));
    int i = 0;
    for(i=0; i<M; i++)
    {
        int t,v;
        scanf("%d%d",&t,&v);
        int j;
        for(j=T-t; j>0; j--)
            if(a[j])
                a[j+t] = max(a[j+t],a[j] + v);
        a[t] = max(a[t],v);
    }
    int ans = 0;
    for( i=1; i<=T; i++)
        ans = max(ans,a[i]);
    printf("%d\n",ans);
    return 0;
}



/*
拷贝的代码，有空的时候要好好研究。
**/
