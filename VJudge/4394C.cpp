#include <stdio.h>
#include <math.h>

double r1, r2;
double s;

int main(int argc, char const *argv[])
{
    while (scanf("%f%f", &r1, &r2) && (r1 != 0 || r2 != 0))
    {
        if (r1 >= r2)
        {
            if (r1 * sqrt(2) >= r1 + r2 + r2 * sqrt(2))
                s = r1 * 2;
            else
                s = r1 + r2 + sqrt((r1 + r2) * (r1 + r2) - (r1 - r2) * (r1 - r2));
        }
        else
        {
            if (r2 * sqrt(2) >= r1 + r2 + r1 * sqrt(2))
                s = r2 * 2;
            else
                s = r1 + r2 + sqrt((r1 + r2) * (r1 + r2) - (r2 - r1) * (r2 - r1));
        }
        printf("%.2f\n", s);
    }
    return 0;
}