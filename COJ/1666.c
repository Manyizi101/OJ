#include "stdio.h"
#include "math.h"

int main()
{
    double a,b,c,x1,x2,d;
    while (scanf("%lf%lf%lf",&a, &b, &c)!=EOF)
    {
        d=b*b-4*a*c;
        if(d < 0)       printf("NO\n");
        if (d==0)
        {
            x1=(-b)/(2*a);
            printf("%.2lf\n",x1);
        }
        if (d>0)
        {
            x1=(-b-sqrt(d))/(2*a);
            x2=(-b+sqrt(d))/(2*a);
            printf("%.2lf %.2lf\n",x1,x2);
        }
    }
    return 0;
}
