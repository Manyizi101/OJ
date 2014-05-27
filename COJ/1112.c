#include  <stdio.h>
#include  <string.h>

int main()
{
    char a[1010],b[1010];
    //while(scanf("%s%s", a,b)!=EOF)
    //{
        scanf("%s%s", a,b);
        int c[1010],d[1010],e[1010],i,lena=strlen(a),lenb=strlen(b),big,ans=0;
        memset(c,0,1010);
        memset(d,0,1010);
        memset(e,0,1010);
        for(i=0; i<lena; i++) c[i]=a[lena-i-1]-48;
        for(i=0; i<lenb; i++) d[i]=b[lenb-i-1]-48;
        if(lena>lenb)
        {
            big = lena;
        }
        else
        {
            big = lenb;
        }
        for(i=0; i<big; i++)
        {
            e[i]+=c[i]+d[i];
            if(e[i]>9)
            {
                ans++;
                e[i]-=10;
                e[i+1]+=1;
            }
        }
        if(e[big]!=0)
        {
            for(i=big; i>=0; i--)
            {
                printf("%d", e[i]);
            }
            printf("\n");
        }
        if(e[big]==0)
        {
            for(i=big-1; i>=0; i--)
            {
                printf("%d", e[i]);
            }
            printf("\n");
        }
    //}
    return 0;
}
