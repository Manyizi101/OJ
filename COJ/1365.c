#include    <stdio.h>
#include    <string.h>


int main()
{
    int len,i,j;
    char n[1000],key;
    scanf("%s", n);
    len=strlen(n);
    for(i=0; i<len; i++)
    {
        for(j=len-1; j>i; j--)
        {
            if(n[i]>n[j])
            {
                key = n[i];
                n[i] = n[j];
                n[j] = key;
            }
        }
    }
    while(1)
    {
        if(n[0]=='0')
        {
            for(i=0; i<len-1; i++)
            {
                n[i]=n[i+1];
            }
            n[len-1]='\0';
        }
        if(n[0]!='0')
        {
            printf("%s\n", n);
            return 0;
        }
    }
}
