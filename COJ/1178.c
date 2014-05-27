#include   <stdio.h>

int main()
{
    int a[3][4] ;
    int b[4];
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4 ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(j = 0; j < 4; j++)
    {
        b[j] = a[0][j];
        for (i = 0; i <3; i++)
        {
            if(b[j] > a[i][j])  b[j] = a[i][j];
        }
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4 ; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    for(j = 0; j < 4; j++)  printf("%3d", b[j]);
    return 0;
}
