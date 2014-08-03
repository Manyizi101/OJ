#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d, n;
    scanf("%d", &n);
    for (a = 6; a <= n; a++)
        for (b = 2;; b++)
        {
            if (a * a * a <= b * b * b)
                break;
            for (c = b + 1;; c++)
            {
                if (a * a * a <= b * b * b + c * c * c)
                    break;
                for (d = c + 1;; d++)
                {
                    if (a * a * a < b * b * b + c * c * c + d * d * d)
                        break;
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    return 0;
}