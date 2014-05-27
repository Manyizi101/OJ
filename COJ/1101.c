#include  <stdio.h>
#include  <string.h>

void wright(char a[], char b[])
{
    int len,i;
    len = strlen(b);
    memset(a,0,30);
    for(i=0;i<len;i++)
    {
        a[i]=b[i];
    }
    return;
}
int main()
{
    int n,i,accept[100],time[100],best_accept,best_time;
    char team[100][30],best_team[30];
    scanf("%d", &n);
    for(i=0;i<n;i++)    scanf("%s%d%d", team[i], &accept[i], &time[i]);
    wright(best_team,team[0]);best_accept=accept[0];best_time=time[0];
    for(i=1;i<n;i++)
    {
        if(accept[i]>best_accept)
        {
            wright(best_team,team[i]);best_accept=accept[i];best_time=time[i];
        }
        if(accept[i]==best_accept)
        {
            if(time[i]<best_time)
            {
                wright(best_team,team[i]);best_accept=accept[i];best_time=time[i];
            }
        }
    }
    printf("%s", best_team);
    return 0;
}
