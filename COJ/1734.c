#include  <stdio.h>


int main()
{
    int a, b ,c, i= 0;
    for(a = 1; a < 10; a++)
        for(b = 0; b < 10; b++)
            for(c = 0; c < 9; c++)
            {
                if(a!=b&&b!=c&&a!=c&&c%2==0)
                {
                    printf("%d", 100*a+10*b+c);
                    if ((i+1)%8 != 0)
                    printf("%c", 32);
                    i++;
                    if(i%8==0 && i != 328)
                    {
                        printf("\n");
                    }
                }
            }
    return 0;
}
