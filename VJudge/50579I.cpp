#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps 1e-6

int t;
double in;
double l, r, m;

float equal(float x)
{
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
}

int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        scanf("%lf", &in);
        if (in < equal(0) || in > equal(100))
        {
            printf("No solution!\n");
            continue;
        }
        else
        {
            l = 0;
            r = 100;
            while (r - l > eps)
            {
                m = (r + l) / 2.0;
                if (equal(m) - in >= 0)
                    r = m-eps;
                else
                    l = m+eps;
            }
            printf("%.4f\n", (r + l) / 2.0);
        }
    }
    return 0;
}