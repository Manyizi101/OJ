#include  <cstdio>
#include  <cmath>
#include  <stdlib.h>

using namespace std;

int main()
{
    double pi=0;
    int count = 1;
    double i=1, n=0;
    while(abs(1.0/i*pow(-1,n))>=0.0001)
    {
        pi += 1.0/i*pow(-1,n);
        i+=2;
        n+=1;
        count++;
    }
    printf("pi = %f\ncount = %d", pi*4, count);
    return 0;
}
