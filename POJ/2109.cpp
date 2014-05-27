#include <cstdio>
#include <cmath>

int main()
{
    double n , m ;
    while ( scanf( "%lf%lf" , &m , &n ) != EOF )
        printf( "%.0lf\n" , exp(log(n)/m));
    return 0;
}
