#include  <stdio.h>

int main()
{
    int L, i, j;
    scanf("%d", &L);
    for(i = L; i>0; i--)
    {
        for(j=0; j<i-1 ; j++) printf(" ");
        printf("/");
        for(j=L; j>i; j--)  printf("  ");
        printf("\\");
        if(i !=1)
        printf("\n");
    }
    printf("\n");
    for(i = L; i>0; i--)
    {
        for(j=L; j>i; j--) printf(" ");
        printf("\\");
        for(j=0; j<i-1 ; j++)  printf("  ");
        printf("/");
        if(i !=1)
        printf("\n");
    }
    return 0;
}
