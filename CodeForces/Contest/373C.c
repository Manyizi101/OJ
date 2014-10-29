#include   <stdio.h>
#define  MAX  500001

int main()
{
    static long long int n=0,i=0,j=0,s[MAX],ans=0,key=0;
    scanf("%I64d", &n);
    for(i=0; i<n; i++)    scanf("%I64d", &s[i]);
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(s[i]<s[j])
            {
                key = s[i];
                s[i] = s[j];
                s[j] = key;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            if(s[i]>=2*s[j]&&s[i]*s[j]!=0)
            {
                ans++;
                s[i]=0;
                s[j]=0;
            }
        }
    }
    printf("%I64d", n-ans);
    return 0;
}
