#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


double esp = 1e-5;
int main()
{
    double L, n, C;
    while (scanf("%lf%lf%lf", &L, &n, &C) != EOF)
    {
        if (L < 0 && n < 0 && C < 0)
            break;
        double LL;
        LL = (1 + n * C) * L;
        double low, high;
        double R, mid;
        low = 0;
        high = L / 2;
        while (high - low > esp)
        {
            mid = (high + low) / 2;
            R = ((mid * mid * 4) + (L * L)) / (8 * mid);
            if ((2 * R * asin(L / (2 * R))) < LL)
                low = mid;
            else
                high = mid;
        }
        printf("%.3f\n", mid);
    }
    return 0;
}