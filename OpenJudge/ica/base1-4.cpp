#include  <iostream>
#include  <math.h>
#include  <cstdio>
#include  <stdlib.h>
#define A b*b-4*a*c
#define eps 1e-5
using namespace std;

int compare(double x)
{
    if((x-0)>eps)     return 1;
    else if ((x-0)<-eps)    return -1;
    else return 0;
}

int main()
{
    int n;
    double a,b,c;
    double x1,x2;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(compare(A)==0)
        {
            x1= -b/(2*a);
            if(compare(x1)==0)  x1=0;
            printf("x1=x2=%.5f\n", x1);
        }
        else
        {
            if(compare(A)==1)
            {
                x1= (-b + sqrt(A))/(2*a);
                x2= (-b - sqrt(A))/(2*a);
                if(compare(x1)==0)  x1=0;
                if(compare(x2)==0)  x2=0;
                printf("x1=%.5f;x2=%.5f\n", x1, x2);
            }
            else
            {
                x1= -b/(2*a);
                x2= sqrt(fabs(A))/(2*a);
                if(compare(x1)==0)  x1=0;
                if(compare(x2)==0)  x2=0;
                printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n", x1, x2, x1, x2);
            }
        }
    }
    return 0;
}
