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
                    printf("%6d", 100*a+10*b+c);
                    i++;
                    if(i%10==0)  printf("\n");
                }
            }
          return 0;
}
