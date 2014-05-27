#include  <stdio.h>

int main()
{
    int n,t[100];
    int i,j,key,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d", &t[i]);
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(t[i]>t[j])
            {
                key=t[i];
                t[i]=t[j];
                t[j]=key;
            }
        }
    }
    for(i=0;i<n-1;i++)  ans+=t[i+1]-t[i];
    printf("%d", ans);
    return 0;
}
