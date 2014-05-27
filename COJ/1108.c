#include  <stdio.h>
#include  <string.h>

int main()
{
    int len,i=0,ans=0;
    char shu[10];
    scanf("%s", shu);
    len = strlen(shu);
    for(i=0;i<len;i++)
    {
        if(shu[i]=='0')     ans+=6;
        if(shu[i]=='1')     ans+=2;
        if(shu[i]=='2')     ans+=5;
        if(shu[i]=='3')     ans+=5;
        if(shu[i]=='4')     ans+=4;
        if(shu[i]=='5')     ans+=5;
        if(shu[i]=='6')     ans+=6;
        if(shu[i]=='7')     ans+=3;
        if(shu[i]=='8')     ans+=7;
        if(shu[i]=='9')     ans+=6;
    }
    printf("%d", ans);
    return 0;
}
