#include  <stdio.h>
#include  <algorithm>

using namespace  std;

int main()
{
    int k,a[25],flag,ans=0,tmp;
    scanf("%d", &k);
    for(int i=0;i<k;i++)    scanf("%d", &a[i]);
    for(int i=k-1;i>=0;i--)
    {
        flag=a[i];
        tmp=0;
        for(int j=i;j>=0;j--)
        {0
            if(a[j]>=flag)
            {
                tmp++;
                flag=a[j];
            }
        }
        ans>=tmp?tmp=0:ans=tmp;
    }
    printf("%d",ans);
    return 0;
}
