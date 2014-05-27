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
    int n, m;
    while(scanf("%d", &n) != EOF)
    {
        m = judge(n);
        if (m == 0) printf("The number is:%d\n", n);
        if (m == 1) printf("No!\n");
    }
    return 0;
}
