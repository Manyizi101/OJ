#include <cstdio>

int main()
{
    int n,m,a[110];
    int i,mm,car=0;
    scanf("%d%d", &n,&m);
    for(i=0;i<n;i++)     scanf("%d", &a[i]);
    mm=m;
    for(i=0;i<n;i++)
    {
        mm-=a[i];
        if(mm<0)
        {
            mm=m;
            car++;
            i--;
        }
    }
    printf("%d\n",car+1);
}
