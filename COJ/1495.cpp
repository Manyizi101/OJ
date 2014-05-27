#include  <stdio.h>
#include  <math.h>
#define PI 3.14159254


int main()
{
    double a,b,c,d;
    while(scanf("%lf%lf%lf", &a,&b,&c)!=EOF)
    {
        d = a*a+b*b-2*a*b*cos(c/360*2*PI);
        if((a+b>(sqrt(d)+0.5))&&(a+sqrt(d)>b)&&(sqrt(d)+b>a)&&d>0) printf("%.3lf\n", sqrt(d));
        else printf("NO\n");
    }
    return 0;
}
