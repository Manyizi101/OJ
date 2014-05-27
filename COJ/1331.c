#include  <stdio.h>

int main()
{
    int t,i,fen[100],s=0;
    while(scanf("%d", &t)!=EOF)
    {
        s=0;
        for(i=0; i<t; i++)
        {
            scanf("%d", &fen[i]);
            if(fen[i]>=425)  s++;
        }
        printf("%.2f%%\n", s/(float)(t)*100);
    }
    return 0;
}
