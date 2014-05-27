#include  <stdio.h>
#include  <math.h>

int judge(int x)
{
    int i = 2;
    for (i = 2; i <= sqrt(x*1.0); i++)
        if (x%i == 0) return 1;
    return 0;
}


int main()
{
    int a = 4, b = 0 , c = 0, result = 0;
    for (a = 4; a < 10; a++)
    {
        for (b = 0; b < 10; b++)
        {
            for (c = 0; c < 10; c++)
            {
                result = judge(a*100+b*10+c);
                if (result == 1)
                {
                    result = judge(a*10+b);
                    if (result == 1)
                    {
                        result = judge(a);
                        if (result == 1)    printf("%d\n", a*100+b*10+c);
                    }
                }
            }
        }
    }
    return 0;
}
