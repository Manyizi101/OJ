#include  <stdio.h>
#include  <string.h>
#include  <math.h>

int main()
{
    char my[10];
    int n,i,j,my2=0,they2[23],mylen,theylen[23],chaju[23],key=0;
    for(i=0; i<23; i++)
    {
        they2[i] = 0;
        theylen[i] = 0;
        chaju[i]=0;
    }
    char they[23][10];
    scanf("%s", my);
    scanf("%d", &n);
    mylen = strlen(my);
    for(j=0; j<mylen; j++)
    {
        if(my[j]=='2')    my2++;
    }
    for(i=0; i<n; i++)
    {
        scanf("%s", they[i]);
        theylen[i] = strlen(they[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<theylen[i]; j++)
        {
            if(they[i][j]=='2') they2[i]++;
        }
    }
    for(i=0; i<n; i++)
    {
        chaju[i] = abs(my2-they2[i]);
    }
    for(i=0; i<n-1; i++)
    {
        if(chaju[i+1]<chaju[key])   key=i+1;
    }
    printf("%s", they[key]);
    return 0;
}
