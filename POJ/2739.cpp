#include <cstring>
#include <iostream>
using namespace std;

bool flag[10002];
int prime[10002], sum[1402];
int tmp;

int main()
{
    int i, j, k ;
    memset(flag, -1, sizeof(flag));
    memset(sum, 0, sizeof(sum));
    memset(prime, 0, sizeof(prime));

    tmp = 0;
    for ( i = 2; i <= 10000; i++ )
    {
        if ( flag[i] )
        {
            prime[++tmp] = i;
            for ( j = 2; i * j <= 10000; j++ )
                flag[i * j] = 0;
        }
    }

    for ( i = 1; i <= tmp; i++ )
        sum[i] = sum[i - 1] + prime[i];

    int n, ans;
    while ( cin >> n && n )
    {
        ans = i = 0;
        while ( prime[i] < n && i < tmp ) i++;
        if ( prime[i] == n ) ans++;

        for ( j = i - 1; j >= 1; j-- )
        {
            for ( k = 0; k < j; k++ )
                if ( sum[j] - sum[k] == n )
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}