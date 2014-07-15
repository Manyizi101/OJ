#include <stdio.h>
#include <math.h>
using namespace  std;

long long jos( long long n , long long k )
{
    long long sum = 0 , a = ( long long  )  sqrt ( k ), b = k / a , i ;
    if ( n > k ) sum += ( n - k ) * k ;
    for ( i = a ; i > 1 ; i -- )
    {
        long long s = k / i , e = k / ( i - 1 ) ;
        if ( s > n ) break ;
        if ( e > n ) e = n ;
        sum += ( k % e + k % ( s + 1 ) ) * ( e - s ) / 2 ;
    }
    for ( i = 1 ; i <= n && i <= b ; i ++ ) sum += k % i ;
    return sum ;
}

int main(int argc, char const *argv[])
{
    long long n , k ;
    while ( scanf ( "%I64d%I64d", &n, &k ) != EOF )
        printf ( "%I64d\n" , jos(n, k) ) ;
    return 0 ;
}