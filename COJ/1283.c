#include  <stdio.h>

int main()
{
    int h = 0, m = 0, a = 0, b = 0, i= 0;
    while(scanf("%d:%d",&a,&b)!=EOF)
    {
        char c = getchar();
        if(c == '!')
        {
            h = 0;
            m = 0;
        }
        if(c == '=')
        {
            printf("%d:%d\n", h, m);
        }
        if(c == '\n')
        {
            m += b;
            i = m/60;
            m = m - 60*i;
            h += a + i;
        }
    }
    return 0;
}
