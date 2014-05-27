#include  <stdio.h>


int main()
{
    int n, a, b, c;
    int x, y, z;
    while (scanf("%d%d%d%d", &n, &a, &b, &c) != EOF)
    {
        for (x = 100; x > 0; x--)
        {
            for (y = 0; y < 100; y++)
            {
                for (z = 0; z < 100; z++)
                {
                    if (a*x+b*y+c*z == n&& a+b+c==n)   printf("%d %d %d\n", x, y ,z);
                }
            }
        }
    }
    return 0;
}
