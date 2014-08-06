#include <stdio.h>
using namespace std;

int n;
double m = 999999.0;
double s, t;

int main()
{
    scanf("%d", &n);
    while (n != 0)
    {
        while (n--)
        {
            scanf("%lf%lf", &s, &t);
            if (t >= 0)
            {
                t += 4500.0 / (s / 3.6);
                if (t < m)
                    m = t;
            }
        }
        printf("%d\n", (int)(m + 0.999999));
        m = 999999.0;
        scanf("%d", &n);
    }
    return 0;
}