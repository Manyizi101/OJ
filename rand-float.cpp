#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    //freopen( "1.in","r",stdin );
    //freopen( "3.out","w",stdout );
    srand( time( NULL ) );
    int t, n = 10 ;
    while ( n-- )
    {
        printf( "%.6lf\n", rand() * 1.0 / 100 );
    }
    return 0;
}
