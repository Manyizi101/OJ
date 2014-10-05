#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int main( )
{
    //freopen( "1.in","r",stdin );
    freopen( "3.out", "w", stdout );
    srand( time( NULL ) );
    int t = 99, n = 10 ;
    while ( n-- )
    {
        printf( "%c\n", rand() % 26 + 'A' );
    }
    return 0;
}