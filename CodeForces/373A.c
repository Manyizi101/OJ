#include   <stdio.h>

int main()
{
    int k,i,j,s,num[10]= {0,0,0,0,0,0,0,0,0,0};
    char panel[4][4];
    scanf("%d", &k);
    for(i=0; i<4; i++)
    {
        scanf("%s", panel[i]);
        for(j=0; j<4; j++)
        {
            if(panel[i][j]=='.')    num[0]++;
            for(s=1; s<10; s++)
            {
                if(panel[i][j]-'0'==s)    num[s]++;
            }
        }
    }
    for(s=1; s<10; s++)
    {
        if(num[s]>2*k)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
