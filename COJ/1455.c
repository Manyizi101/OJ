#include   <stdio.h>

int main()
{
    int a,b,i;
    char c;
    for(i=0;i<10;i++)
    {
        scanf("%d %c %d", &a,&c,&b);
        if(c=='+')  printf("%d+%d=%.5f\n", a, b, a+(float)(b));
        if(c=='-')  printf("%d-%d=%.5f\n", a, b, a-(float)(b));
        if(c=='*')  printf("%d*%d=%.5f\n", a, b, a*(float)(b));
        if(c=='/')  printf("%d/%d=%.5f\n", a, b, a/(float)(b));
    }
    return 0;
}
