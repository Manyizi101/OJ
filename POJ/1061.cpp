#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


long long x, y, m, n, l;
long long a, b, d, k, s, t;

long long gcd(long long a, long long b)
{
    long long c;
    if (a < b)
    {
        c = a;    a = b;
        b = c;
    }
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
    long long ans, t;
    if (b == 0)
    {
        x = 1;    y = 0;
        return a;
    }
    else
    {
        ans = extended_gcd(b, a % b, x, y);
        t = x;    x = y;
        y = t - (a / b) * y;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    while (scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l) != EOF)
    {
        a = n - m;
        b = l;
        d = x - y;
        long long r = gcd(a, b);
        if (d % r != 0)
        {
            printf("Impossible\n");
            continue;
        }
        a /= r;
        b /= r;
        d /= r;
        extended_gcd(a, b, s, k);
        s = s * d;
        k = k * d;
        t = s / b;
        s = s - t * b;
        if (s < 0)
            s += b;
        printf("%lld\n", s);
    }
    return 0;
}