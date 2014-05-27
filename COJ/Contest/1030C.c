#include   <stdio.h>

int main()
{
    int n=0,m[10000]= {0},ts[25]= {0},te[25]= {0};
    int i=0,j=0,k=0,l=0,v=0,key=0;
    int time[100]= {1};
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
        for(j=0; j<m[i]; j++)
        {
            scanf("%d%d", &ts[j],&te[j]);
        }
    }
    for(i=0; i<n; i++)
    {

        for(j=0; j<m[i]; j++)
        {
            for(k=ts[j]+1; k<te[j]; k++)
            {
                if(ts[j]!=te[j])
                {
                    time[k]++;
                }
            }
        }
        for(l=0; l<24; l++)
        {
            for(v=23; v>l; v--)
            {
                if(time[l]<time[v])
                {
                    key = time[l];
                    time[l] = time[v];
                    time[v] = key;
                }
            }
        }
        printf("%d\n", time[0]-1);
    }
    return 0;
}
