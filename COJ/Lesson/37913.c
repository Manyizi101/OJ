#include  <stdio.h>
#include  <string.h>

int main()
{
    char a[12],b[12];
    while(scanf("%s%s", a,b)&&!(a[0]=='0'&&b[0]=='0'))
    {
        int c[12],d[12],e[12],i,lena=strlen(a),lenb=strlen(b),big,ans=0;
        for(i=0;i<12;i++)
        {
            c[i]=d[i]=e[i]=0;
        }
        for(i=0;i<lena;i++) c[i]=a[lena-i-1]-48;
        for(i=0;i<lenb;i++) d[i]=b[lenb-i-1]-48;
        if(lena>lenb)
        {
            big = lena;
        }
        else
        {
            big = lenb;
        }
        for(i=0;i<big;i++)
        {
            e[i]+=c[i]+d[i];
            if(e[i]>9)
            {
                ans++;
                e[i]-=10;
                e[i+1]+=1;
            }
        }
        if(ans==0)  printf("No carry operation.\n");
        if(ans==1)  printf("1 carry operation.\n");
        if(ans>1)    printf("%d carry operations.\n", ans);
    }
    return 0;
}
