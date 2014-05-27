#include  <stdio.h>
#include  <string.h>

int main()
{
    int T;
    int i,k[1000],l,ans[1000];
    for(i=0;i<1000;i++) ans[i]=1;
    char N[1000][11];
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%s", N[i]);
        k[i] = strlen(N[i]);
    }
    for(i=0;i<T;i++)
    {
        if(N[i][0]!='1')    ans[i]=0;
        for(l=0;l<k[i];l++)
        {
            if((N[i][l]!='1'&&N[i][l]!='4'))  ans[i]=0;
            if(N[i][l]=='1'&&N[i][l+1]=='4'&&N[i][l+2]=='4'&&N[i][l+3]=='4')    ans[i] = 0;
        }
    }
    for(i=0;i<T;i++)
    {
        if(ans[i]==1)   printf("YES\n");
        if(ans[i]==0)   printf("NO\n");
    }
    return 0;
}
