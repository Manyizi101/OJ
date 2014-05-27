#include <stdio.h>
#include <math.h>

int judge(int x)
{
    int key = 0, result = 0;
    for (key = 2; key <= sqrt(x*1.0); key++)
    {
        if (x%key == 0)   return result = 1;
    }
    return result = 0;
}


int main()
{
    int a = 1, b = 0, c = 0, d = 3, result = 0;
    for (a = 1; a < 10; a++)
    {
        for (b = 0; b < 10; b++)
        {
            for (c = 0; c < 10; c++)
            {
                for (d = 3; d < 10; d++)
                {
                    result = judge(1000*a+100*b+10*c+d);
                    if (result == 0)
                    {
                        result = judge(100*b+10*c+d);
                        if (result == 0)
                        {
                            result = judge(10*c+d);
                            if (result == 0)
                            {
                                result = judge(d);
                                if (result == 0)    printf("%d\n", 1000*a+100*b+10*c+d);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

