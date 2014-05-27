#include  <stdio.h>

int main()
{
    char a[3];
    while(scanf("%s", a)!=EOF)
    {
        int i,j;
        char key;
        for(i=0;i<3;i++)
        {
            for(j=2;j>i;j--)
            {
                if(a[i]>a[j])
                {
                    key = a[i];
                    a[i] = a[j];
                    a[j] = key;
                }
            }
        }
        for(i=0;i<2;i++)
        {
            printf("%c ", a[i]);
        }
        printf("%c", a[2]);
        printf("\n");
    }
    return 0;
}
