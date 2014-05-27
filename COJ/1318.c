#include   <stdio.h>
#include   <math.h>

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
    int i, result;
    for (i = 100; i <= 1000; i++)
    {
        result = judge(i);
        if (result == 0)
            printf("%d\n", i);
    }
    return 0;
}
