#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define MAX 107
using namespace std ;
int n,a[MAX];
int dp[ 107 ][ 1 << 17 ];
int pre[ 107 ][ 1 << 17 ];
int num[ 107 ][ 1 << 17 ];
int prime[]= { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 39 , 41 , 43 , 47 , 53 };
int state[ 60 ];
void print ( int i , int u )
{
    if ( i == 1 ) {
        printf ( "%d " , num[i][u] );
        return ;
    }
    print ( i- 1 , pre[i][u] );
    printf ( "%d " , num[i][u] );
}
int main ( )
{
    while ( ~ scanf ( "%d" , &n ) ) {
        for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
        memset ( dp , 0x3f , sizeof ( dp ) );
        int INF = dp[ 0 ][ 0 ];
        dp[ 0 ][ 0 ] = 0 ;
        memset ( state , 0 , sizeof ( state ) );
        for ( int i = 2 ; i < 60 ; i ++ ) for ( int j = 0 ; j < 17 ; j++ ) if ( i%prime[j] == 0 )
                    state[i] |= ( 1 <<j);
        int total = 1 << 17 ;
        for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j < total ; j++ ) {
                if ( dp[i][j] == INF ) continue ;
                for ( int k = 1 ; k < 59 ; k++ ) {
                    if ( state[k]&j ) continue ;
                    int x = state[k]|j;
                    if ( dp[i+ 1 ][x] > dp[i][j] + abs ( a[i+ 1 ] - k ) ) {
                        dp[i+ 1 ][x] = dp[i][j] + abs ( a[i+ 1 ] - k );
                        pre[i+ 1 ][x] = j;
                        num[i+ 1 ][x] = k;
                    }
                }
            }
        int ans = INF,loc = - 1 ;
        for ( int i = 0 ; i < total ; i++ ) if ( ans > dp[n][i] ) {
                ans = dp[n][i];
                loc = i;
            }
        print ( n ,  loc );
        puts ( "" );
    }
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std ;
int dp[ 1 << 21 ];
char s[ 26 ][ 26 ];
int c[ 26 ][ 26 ];
int v[ 26 ][ 26 ];
int state[ 26 ][ 26 ];
int n,m;
int main ( )
{
    while ( ~ scanf ( "%d%d" , &n , &m ) ) {
        for ( int i = 0 ; i < n ; i++ ) scanf ( "%s" , s[i] );
        for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j < m ; j++ ) scanf ( "%d" , &c[i][j] );
        int total = ( 1 <<n)- 1 ;
        for ( int i = 0 ; i < n ; i++ ) for ( int k = 0 ; k < m ; k++ ) {
                int maxn = 0 ;
                for ( int j = 0 ; j < n ; j++ ) {
                    if ( s[i][k] != s[j][k] ) continue ;
                    v[i][k] += c[j][k];
                    maxn = max ( c[j][k] , maxn );
                    state[i][k] |= 1 <<j;
                }
                v[i][k] -= maxn;
            }
        memset ( dp , 0x3f , sizeof ( dp ) );
        dp[ 0 ] = 0 ;
        for ( int i = 0 ; i < total ; i++ ) for ( int j = 0 ; ; j++ ) if ( !((i>>j)& 1 )) {
                    int a = 1 <<j;
                    for ( int k = 0 ; k < m ; k++ ) {
                        int b = state[j][k];
                        dp[i|a] = min ( dp[i|a] , dp[i] + c[j][k] );
                        dp[i|b] = min ( dp[i|b] , dp[i] + v[j][k] );
                    }
                    break ;
                }
        printf ( "%d\n" , dp[total] );
    }
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define MAX 1007
using namespace std ;
struct Node {
    int c,p,id;
    bool operator < ( const Node & a ) const
    {
        if ( p == a.p ) return c < a.c;
        return p > a.p;
    }
} p[MAX];
struct PP {
    int a,b;
    PP ( int x , int y )
    {
        a = x;
        b = y;
    } bool operator < ( const PP &x ) const
    {
        return a < x.a;
    }
};
int n,k,r,m;
multiset <PP> table;
vector <pair< int , int > > pp;
int main ( )
{
    while ( ~ scanf ( "%d" , &n ) ) {
        for ( int i = 0 ; i < n ; i++ ) {
            scanf ( "%d%d" , &p[i].c , &p[i].p );
            p[i].id = i+ 1 ;
        }
        sort ( p , p+n );
        scanf ( "%d" , &m );
        for ( int i = 0 ; i < m ; i++ ) {
            scanf ( "%d" , &r );
            table.insert ( PP ( r , i+ 1 ) );
        }
        int ans = 0 ;
        multiset <PP> ::iterator it;
        for ( int i = 0 ; i < n ; i++ ) {
            it = table.lower_bound ( PP ( p[i].c , 1 ) );
            if ( it == table.end() ) continue ;
            ans += p[i].p;
            table.erase ( it );
            pp.push_back ( make_pair ( p[i].id , it->b ) );
        }
        printf ( "%d %d\n" , ( int )pp.size() ,ans );
        for ( int i = 0 ; i < pp.size() ; i++ ) printf ( "%d %d\n" , pp[i].first , pp[i].second );
    }
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define MAX 1000007
using namespace std ;
char s[MAX];
int b[MAX];
int dp[MAX];
stack < int > stk;
void Clear ( )
{
    while ( !stk.empty())
        stk.pop();
}
int main ( )
{
    while ( ~ scanf ( "%s" , s ) ) {
        Clear();
        int n = strlen ( s );
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == '(' )
                stk.push ( i );
            if ( s[i] == ')' ) {
                if ( stk.empty() ) {
                    b[i] = - 1 ;
                    dp[i] = - 1 ;
                    continue ;
                }
                int x = stk.top();
                stk.pop();
                dp[i] = b[i] = x;
                if ( s[x- 1 ] == ')' && dp[x- 1 ] != - 1 )
                    dp[i] = dp[x- 1 ];
            }
        }
        int ans = 0 ,num= 0 ;
        for ( int i = 0 ; i < n ; i++ ) if ( s[i] == ')' && dp[i] != - 1 )
                ans = max ( ans , i-dp[i]+ 1 );
        for ( int i = 0 ; i < n ; i++ ) if ( s[i] == ')' && dp[i] != - 1 ) if (i-dp[i]+ 1 == ans ) num++;
        if ( ans ) printf ( "%d %d\n" , ans , num );
        else puts ( "0 1" );
    }
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 2000007
using namespace std ;
typedef long long LL;
int n,q;
int a[MAX];
int pre[MAX];
int cnt[MAX];
int main ( )
{
    while ( ~ scanf ( "%d%d" , &n , &q )) {
        for ( int i = 1 ; i <= n ; i++ ) {
            scanf ( "%d" , &a[i] );
            a[i+n] = a[i];
            pre[i] = i;
        }
        sum[ 0 ] = 0 ;
        for ( int i = 1 ; i <= 2 *n ; i++ )
            sum[i] = sum[i- 1 ] + a[i];
        while ( q-- ) {
            scanf ( "%I64d" , &b );
            int j = 1 ;
            for ( int i = n+ 1 ; i <= 2 *n ; i++ ) {
                while ( sum[i] - sum[j] > b ) j++;
                pre[i] = pre[j];
                cnt[i] = cnt[j]+ 1 ;
                if ( i - pre[i] >= n ) {
                    printf ( "%d\n" , cnt[i] );
                    break ;
                }
            }
        }
    }
    return 0 ;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 27
using namespace std ;
typedef long long LL;
char l[MAX],r[MAX];
void init ( )
{
    pp[ 0 ] = 1 ;
    for ( int i = 1 ; i < MAX ; i++ )
        pp[i] = pp[i- 1 ]* 10L L;
}
{
    LL ret = 0 ;
    int n = strlen ( s );
    if ( n > 1 ) ret += 10 ;
    else ret += s[ 0 ]- 48 + 1 ;
    if ( n > 2 ) ret += 9 ;
    for ( int i = 1 ; i < n- 2 ; i++ )
        ret += 9L L*pp[i];
    for ( int i = 0 ; i < n- 1 ; i++ ) {
        int x = s[i]- 48 ;
        if ( i == 0 ) x--;
        ret += x*pp[n- 2 -i];
    }
    if ( n > 1 && s[n- 1 ] >= s[ 0 ] ) ret++;
    return ret;
}
int main ( )
{
    init ( );
    while ( ~ scanf ( "%s%s" , l , r ) ) {
//cout << solve( r ) << " " << solve ( l ) << endl; int n = strlen ( l ); printf ( "%I64d\n" , solve ( r ) - solve(l) + ( l[n- 1 ] == l[ 0 ]? 1L L: 0L L) );
    }
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 200007
using namespace std ;
typedef long long LL;
const LL mod = 1e9 + 7 ;
int h,w,n;
struct Node {
    int x,y;
    bool operator < ( const Node & a ) const
    {
        return x+y < a.x+a.y;
    }
} p[MAX];
{
    LL ret = 1 ;
    while ( n ) {
        if ( n& 1 ) {
            ret *= num;
            ret %= mod;
        }
        num *= num;
        num %= mod;
        n >>= 1 ;
    }
    return ret;
}
void init ( )
{
    f[ 0 ] = 1 , f[ 1 ] = 1 ;
    for ( int i = 2 ; i < MAX ; i++ )
        f[i] = f[i- 1 ]*i%mod;
}
{
    return f[i]*inv( f[j]*f[i-j]%mod , mod- 2 )%mod;
}
int main ( )
{
    init ( );
    while ( ~ scanf ( "%d%d%d" , &h , &w , &n ) ) {
        for ( int i = 0 ; i < n ; i++ ) {
            scanf ( "%d%d" , &p[i].x , &p[i].y );
            p[i].x--;
            p[i].y--;
        }
        p[n].x = h- 1 , p[n].y = w- 1 ;
        sort ( p , p+n+ 1 );
        memset ( dp , 0 , sizeof ( dp ));
        for ( int i = 0 ; i <= n ; i++ ) {
            int x = p[i].x , y = p[i].y;
            dp[i] = C ( x+y , x );
            for ( int j = 0 ; j < i ; j++ ) {
                int u = p[j].x , v = p[j].y;
                if ( u > x || v > y ) continue ;
                dp[i] -= C( x-u+y-v , x-u )*dp[j]%mod;
                dp[i] = (dp[i]%mod+mod)%mod;
            } //cout << i << " : " << dp[i] << endl; } printf ( "%I64d\n" , dp[n] );
        }
    }
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 4007
    using namespace std ;
    int dp[MAX][MAX];
    int a[MAX],n;
    int main ( ) {
        while ( ~ scanf ( "%d" , &n ) ) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            int ans = 1 ;
            for ( int i = 1 ; i <= n ; i++ ) {
                int k = - 1 ;
                for ( int j = 1 ; j < i ; j++ ) {
                    if ( k == - 1 )
                        dp[i][j] = 2 ;
                    else dp[i][j] = dp[j][k] + 1 ;
                    if ( a[j] == a[i] )
                        k = j;
                    ans = max ( ans , dp[i][j] );
                }
            }
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 107
    using namespace std ;
    int n,dp[MAX][MAX<< 1 ][MAX<< 1 ],t[MAX],w[MAX];
    int main ( ) {
        while ( ~ scanf ( "%d" , &n ) ) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d %d" , &t[i] , &w[i] );
            memset ( dp , 0 , sizeof ( dp ) );
            dp[ 0 ][ 0 ][ 0 ] = 1 ;
            for ( int i = 1 ; i <= n ; i++ )
                for ( int j = 0 ; j <= 2 *n ; j++ )
                    for ( int k = 0 ; k <= 2 *n; k++ ) {
                        if ( j >= t[i] && dp[i- 1 ][j-t[i]][k] )
                            dp[i][j][k] = 1 ;
                        if ( k >= w[i] && dp[i- 1 ][j][k-w[i]] )
                            dp[i][j][k] = 1 ;
                    }
            bool flag = true ;
            for ( int i = 0 ; i <= 200 &&flag ; i++ )
                for ( int k = 0 ; k <= i&&flag ; k++ )
                    if ( dp[n][i][k] ) {
                        printf ( "%d\n" , i );
                        flag = false ;
                    }
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 507
    using namespace std ;
    int n,m,b,mod;
    int a[MAX];
    int dp[MAX][MAX];
    int main ( ) {
        while (~ scanf ( "%d%d%d%d" , &n , &m , &b , &mod )) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            memset ( dp , 0 , sizeof ( dp ));
            dp[ 0 ][ 0 ] = 1 ;
            for ( int i = 1 ; i <= n ; i++ )
                for ( int j = 1 ; j <= m ; j++ )
                    for ( int k = 0 ; k <= b ; k++ )
                        if ( k >= a[i] ) {
                            dp[j][k] += dp[j- 1 ][k-a[i]];
                            dp[j][k] %= mod;
                        }
            int ans = 0 ;
            for ( int k = 0 ; k <= b ; k++ ) {
                ans += dp[m][k];
                ans %= mod;
            }
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 100007
    using namespace std;
    int n, k, cc;
    char s[MAX];
    struct Node {
        int branch[26];
        Node()
        {
            memset(branch, -1, sizeof(branch));
        }
        int win, lose;
    } p[MAX << 1];
    void add() {
        int u = 0;
        int m = strlen(s);
        for (int i = 0; i < m; i++) {
            int x = s[i] - 'a';
            if (p[u].branch[x] == -1)
                p[u].branch[x] = cc++;
            u = p[u].branch[x];
        }
    }
    void dfs(int u, int d) {
        int temp1, temp2;
        temp1 = temp2 = (d & 1) ? 0 : 1;
        bool flag = false;
        for (int i = 0; i < 26; i++) {
            int v = p[u].branch[i];
            if (v == -1) continue;
            flag = true;
            dfs(v, d + 1);
            if (d & 1) {
                temp1 = temp1 || p[v].win;
                temp2 = temp2 || p[v].lose;
            } else {
                temp1 = temp1 && p[v].win;
                temp2 = temp2 && p[v].lose;
            }
        }
        if (!flag) {
            p[u].win = p[u].lose = 0;
            if (d & 1) p[u].lose = 1;
            else p[u].win = 1;
        } else {
            p[u].win = temp1;
            p[u].lose = temp2;
        }
    }
    int main() {
        while (~scanf("%d%d", &n, &k)) {
            cc = 1;
            for (int i = 0; i < n; i++) {
                scanf("%s", s);
                add();
            }
            dfs(0, 1);
            int win = p[0].win;
            int lose = p[0].lose;
            if (!win) puts("Second");
            else if (lose) puts("First");
            else {
                if (k & 1) puts("First");
                else puts("Second");
            }
        }
    }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 1007
    using namespace std;
    int dp[MAX][MAX];
    const int mod = 1e9 + 7;
    int n, p[MAX];
    void dfs(int x, int y) {
        if (x == y) {
            dp[x][y] = 1;
            return;
        }
        if (dp[x][y]) return;
        dfs(x, y - 1);
        dfs(p[y - 1], y - 1);
        dp[x][y] = dp[x][y - 1] + dp[p[y - 1]][y - 1] + 1;
        dp[x][y] %= mod;
    }
    int main() {
        while (~scanf("%d", &n)) {
            for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
            memset(dp, 0, sizeof(dp));
            dfs(1, n + 1);
            printf("%d\n", ((dp[1][n + 1] - 1) % mod + mod) % mod);
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 400007
    using namespace std;
    int dp[2][MAX];
    int r, g;
    const int mod = 1e9 + 7;
    int cal(int h) {
        return h * (h + 1) / 2;
    }
    int main() {
        while (~scanf("%d%d", &r, &g)) {
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            int ans = 0;
            for (int i = 1; ; i++) {
                int x = i % 2;
                int y = (i + 1) % 2;
                bool flag = true;
                int low = cal(i - 1);
                int high = cal(i);
                for (int j = 0; j <= high; j++)
                    dp[x][j] = 0;
                for (int j = 0; j <= high; j++) {
                    int jj = high - j;
                    if (j > g || jj > r) continue;
                    if (j >= i) {
                        dp[x][j] += dp[y][j - i];
                        dp[x][j] %= mod;
                    }
                    dp[x][j] += dp[y][j];
                    dp[x][j] %= mod;
                }
                bool mark = true;
                int temp = 0;
                for (int j = 0; j <= high; j++)
                    if (dp[x][j]) {
                        mark = false;
                        temp += dp[x][j];
                        temp %= mod;
                    }
                if (mark) break;
                ans = temp;
            }
            printf("%d\n", ans);
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 200007
    using namespace std;
    typedef long long LL;
    typedef pair<long long, int> PII;
    int n, k;
    void make() {
        for (int i = 1; i <= n; i++) {
            dp[i][0] = b[i];
            ans[i][0] = i;
        }
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
                if (dp[i][j - 1] == dp[i][j]) ans[i][j] = ans[i][j - 1];
                else ans[i][j] = ans[i + (1 << (j - 1))][j - 1];
            }
    }
    int k = (int) ((log((r - l + 1) * 1.0)) / log(2.0));
    LL maxn;
    int temp;
    maxn = max(dp[l][k], dp[r - (1 << k) + 1][k]);
    if (maxn == dp[l][k]) temp = ans[l][k];
    else temp = ans[r - (1 << k) + 1][k];
    return make_pair(maxn, temp);
}
int main()
{
    while (~scanf("%d%d", &n, &k)) {
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }
        for (int i = k; i <= n; i++) b[i] = a[i] - a[i - k];
        make();
        int loc = -1;
        PII temp = make_pair(0, 0);
        for (int i = 2 * k; i <= n; i++) {
            PII tmp = query(k, i - k);
            if (tmp.first + b[i] > temp.first) {
                temp = tmp;
                temp.first += b[i];
                loc = i;
            }
        }
        temp.second -= k - 1;
        loc -= k - 1;
        printf("%d %d\n", (int) temp.second, loc);
    }
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#define MAX 27
using namespace std;
typedef long long LL;
map<LL, int> mp[MAX];
int n, k;
bool fac(LL num, LL &res)
{
    res = 1L
          L;
    while (num) {
        res *= num;
        if (res > S) return false;
        num--;
    }
    return true;
}
void dfs1(int m, int t, LL sum)
{
    if (m == n / 2) {
        mp[t][sum]++;
        return;
    }
    LL temp;
    if (fac(a[m], temp)) if (temp <= sum && t >= 1)
            dfs1(m - 1, t - 1, sum - temp);
    if (a[m] <= sum)
        dfs1(m - 1, t, sum - a[m]);
    dfs1(m - 1, t, sum);
}
void dfs2(int m, int t, LL sum)
{
    if (m == n / 2 + 1) {
        for (int i = t; i <= k; i++)
            ans += mp[i][sum];
        return;
    }
    LL temp;
    if (fac(a[m], temp) && t < k && sum + temp <= S)
        dfs2(m + 1, t + 1, sum + temp);
    if (sum + a[m] <= S)
        dfs2(m + 1, t, sum + a[m]);
    dfs2(m + 1, t, sum);
}
int main()
{
    while (~scanf("%d%d%I64d", &n, &k, &S)) {
        ans = 0;
        for (int i = 0; i < MAX; i++)
            mp[i].clear();
        for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
        dfs1(n, k, S);
        dfs2(1, 0, 0);
        printf("%I64d\n", ans);
    }
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 4007
using namespace std;
typedef long long LL;
int n;
const LL mod = 1e9 + 7;
void init()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i < MAX; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0 || j == i) c[i][j] = 1;
            else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                c[i][j] %= mod;
            }
    b[0][0] = b[1][1] = 1;
    for (int i = 2; i < MAX; i++) {
        b[i][1] = b[i - 1][i - 1];
        for (int j = 2; j <= i; j++) {
            b[i][j] = b[i][j - 1] + b[i - 1][j - 1];
            b[i][j] %= mod;
        }
    }
}
int main()
{
    init();
    while (~scanf("%d", &n)) {
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[n][i] * b[i][i] % mod;
            ans %= mod;
        }
        printf("%I64d\n", ans);
    }
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 200007
using namespace std;
int dp1[MAX];
int dp2[MAX];
vector<int> e[MAX];
int n, m;
const int INF = 1 << 29;
void add(int u, int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}
void dfs(int u, int p, int d)
{
    bool flag = true;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == p) continue;
        dfs(v, u, d + 1);
        flag = false;
    }
    if (flag) {
        m++;
        dp1[u] = dp2[u] = 1;
        return;
    }
    if (d & 1) {
        dp1[u] = INF;
        dp2[u] = 0;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (v == p) continue;
            dp1[u] = min(dp1[v], dp1[u]);
            dp2[u] += dp2[v];
        }
    } else {
        dp1[u] = 0;
        dp2[u] = INF;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (v == p) continue;
            dp1[u] += dp1[v];
            dp2[u] = min(dp2[v], dp2[u]);
        }
    }
}
int main()
{
    while (~scanf("%d", &n)) {
        m = 0;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        dfs(1, -1, 1);
        printf("%d %d\n", m + 1 - dp1[1], dp2[1]);
    }
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1000007
using namespace std;
char s[MAX];
int next[MAX];
int hash[MAX];
void kmp(int n)
{
    memset(next, 0, sizeof(next));
    for (int i = 2; i <= n; i++) {
        int k = next[i - 1];
        while (k && s[k + 1] != s[i]) k = next[k];
        if (s[k + 1] == s[i]) next[i] = k + 1;
    }
}
int main()
{
    while (~scanf("%s", s + 1)) {
        int n = strlen(s + 1);
        kmp(n);
        memset(hash, 0, sizeof(hash));
        for (int i = 2; i < n; i++)
            hash[next[i]] = 1;
        int x = next[n];
        while (!hash[x] && x) x = next[x];
        if (!x) printf("Just a legend");
        else for (int i = 1; i <= x; i++) printf("%c", s[i]);
        puts("");
    }
}
\left\ {
    \begin{aligned}
    & min ( dp[i-1][k]+1 ) ( k \neq j \&\& s[i] \neq j ) \\
    & min ( dp[i-1][k] ) ( k \neq j \&\& \neq j )
    \end{aligned}
    \right. 然后输出答案时寻找任意一条能够达到最优解的路径即可。 然后这样直接做的复杂度是 O ( k 2 ⋅ n ) \mathcal{O}(k^2 \cdot  n) ，会超时，我们可以利用前缀和和后缀和进行优化，也就是每次将前dp[i][j]的前j个中最小的处理出来，后缀中最小的处理出来，每次为了保证不同，其实就是找出当前点之前的前缀最小的和当前点之后的后缀最小的，然后就可以将每次就可以 O ( 1 ) \mathcal{O}(1) 的转移（原本是 O ( k ) \mathcal{O}(k) 的），这个预处理是 O ( k ) \mathcal{O}(k) 的,所以复杂度优化为了 O ( k ⋅ n ) \mathcal{O}(k \cdot n ) ,只是常熟略大，几百毫秒过的。
    AC代码：
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
#define MAX 500007
    using namespace std;
    int dp[MAX][30];
    int lef[30];
    int rig[30];
    char s[MAX];
    int a[MAX];
    int n, k;
    int main()
    {
        while (~scanf("%d%d", &n, &k)) {
            scanf("%s", s + 1);
            for (int i = 1; i <= n; i++)
                a[i] = s[i] - 'A';
            memset(dp, 0x3f, sizeof(dp));
            for (int i = 0; i < k; i++) if (i == a[1]) dp[1][i] = 0;
                else dp[1][i] = 1;
            lef[0] = dp[1][0];
            for (int i = 1; i < k; i++)
                lef[i] = min(lef[i - 1], dp[1][i]);
            rig[k - 1] = dp[1][k - 1];
            for (int i = k - 2; i >= 0; i--)
                rig[i] = min(rig[i + 1], dp[1][i]);
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j < k; j++) {
                    int temp;
                    if (j == 0) temp = rig[j + 1];
                    else if (j == k - 1) temp = lef[j - 1];
                    else
                        temp = min(lef[j - 1], rig[j + 1]);
                    if (j == a[i]) dp[i][j] = temp;
                    else dp[i][j] = temp + 1;
                }
                lef[0] = dp[i][0];
                for (int j = 1; j < k; j++)
                    lef[j] = min(lef[j - 1], dp[i][j]);
                rig[k - 1] = dp[i][k - 1];
                for (int j = k - 2; j >= 0; j--)
                    rig[j] = min(rig[j + 1], dp[i][j]);
            }
            int minn = 1 << 29;
            for (int i = 0; i < k; i++)
                minn = min(minn, dp[n][i]);
            printf("%d\n", minn);
            stack<char> ans;
            int kk = -1;
            for (int i = n; i > 0; i--)
                for (int j = 0; j < k; j++) {
                    if (j != kk && dp[i][j] == minn) {
                        ans.push((char) ('A' + j));
                        if (j != a[i]) minn--;
                        kk = j;
                        break;
                    }
                }
            while (!ans.empty()) {
                printf("%c", ans.top());
                ans.pop();
            }
            puts("");
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#define MAX 100007
    using namespace std;
    int n;
    char s[MAX];
    int dp[MAX][2];
    int main()
    {
        while (~scanf("%s", s)) {
            n = strlen(s);
            dp[0][0] = dp[0][1] = 0;
            if (isupper(s[0])) dp[0][1] = 1;
            else dp[0][0] = 1;
            for (int i = 1; i < n; i++) {
                if (isupper(s[i])) {
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
                    dp[i][0] = dp[i - 1][0];
                } else {
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                    dp[i][0] = dp[i - 1][0] + 1;
                }
            }
            printf("%d\n", min(dp[n - 1][0], dp[n - 1][1]));
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 100007
    using namespace std;
    int dp[MAX];
    int x[MAX];
    int h[MAX];
    int n;
    const int INF = 2e9 + 7;
    int bsearch(int x)
    {
        int l = 0, r = n, mid;
        while (l != r) {
            mid = (l + r + 1) >> 1;
            if (dp[mid] < x) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    int main()
    {
        while (~scanf("%d", &n)) {
            for (int i = 1; i <= n; i++)
                dp[i] = INF;
            dp[0] = -INF;
            for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &h[i]);
            for (int i = 1; i <= n; i++) {
                int id = bsearch(x[i]) + 1;
                if (i == n || x[i] + h[i] < x[i + 1])
                    dp[id] = min(dp[id], x[i] + h[i]);
                id = bsearch(x[i] - h[i]) + 1;
                if (i == 1 || x[i] - h[i] > x[i - 1])
                    dp[id] = min(dp[id], x[i]);
            }
            int ans;
            for (int i = n; i >= 1; i--)
                if (dp[i] != INF) {
                    ans = i;
                    break;
                }
            printf("%d\n", ans);
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 200007
    using namespace std;
    int n, s, t;
    vector<int> e[MAX];
    vector<int> f[MAX];
    int dp[MAX], dir[MAX];
    void add(int u, int v)
    {
        e[u].push_back(v);
        f[u].push_back(0);
        e[v].push_back(u);
        f[v].push_back(1);
    }
    void dfs(int u, int p)
    {
        dp[u] = 0;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (v == p) continue;
            dir[v] = f[u][i];
            dfs(v, u);
            dp[u] += dp[v] + dir[v];
        }
    }
    void solve(int u, int p)
    {
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (v == p) continue;
            dp[v] = dp[u] + (dir[v] ? -1 : 1);
            solve(v, u);
        }
    }
    int main()
    {
        while (~scanf("%d", &n)) {
            for (int i = 0; i < MAX; i++) {
                e[i].clear();
                f[i].clear();
            }
            for (int i = 1; i < n; i++) {
                scanf("%d%d", &s, &t);
                add(s, t);
            }
            dfs(1, -1);
            solve(1, -1);
            int ans = 1 << 29;
            for (int i = 1; i <= n; i++)
                ans = min(ans, dp[i]);
            printf("%d\n", ans);
            vector<int> pp;
            for (int i = 1; i <= n; i++)
                if (dp[i] == ans)
                    pp.push_back(i);
            sort(pp.begin(), pp.end());
            for (int i = 0; i < pp.size(); i++) printf("%d ", pp[i]);
            puts("");
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define MAX 5007
#define M 100007
    using namespace std;
    int n, m, a[MAX], b[MAX];
    int prime[M], g[MAX];
    map<int, bool> mp;
    void init()
    {
        memset(prime, 0, sizeof(prime));
        prime[1] = prime[0] = 1;
        for (int i = 2; i * i < M; i++) {
            if (prime[i]) continue;
            for (int j = i * i; j < M; j += i)
                prime[j] = 1;
        }
    }
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }
    int main()
    {
        init();
        while (~scanf("%d%d", &n, &m)) {
            mp.clear();
            for (int i = 0; i < n; i++) scanf("%d", &a[i]);
            for (int i = 0; i < m; i++) scanf("%d", &b[i]);
            g[0] = a[0];
            for (int i = 0; i < m; i++)
                mp[b[i]] = true;
            for (int i = n - 1; i >= 0; i--) {
                int x = 0;
                for (int j = 0; j <= i; j++)
                    x = gcd(x, a[j]);
                int xx = x;
                int num1, num2;
                num1 = num2 = 0;
                for (int j = 2; j * j <= x; j++) {
                    if (prime[j]) continue;
                    if (x % j) continue;
                    bool flag = mp[j];
                    while (x % j == 0) {
                        x /= j;
                        if (flag) num1++;
                        else num2++;
                    }
                }
                if (x > 1) {
                    if (mp[x]) num1++;
                    else num2++;
                }
                if (num1 > num2)
                    for (int j = 0; j <= i; j++)
                        a[j] /= xx;
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                int x = a[i];
                for (int j = 2; j * j <= x; j++) {
                    if (prime[j]) continue;
                    if (x % j) continue;
                    bool flag = mp[j];
                    while (x % j == 0) {
                        x /= j;
                        if (flag) ans--;
                        else ans++;
                    }
                }
                if (x > 1) {
                    if (mp[x]) ans--;
                    else ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 5007
    using namespace std ;
    typedef long long LL;
    int n;
    {
        dp[l][r] = r-l+ 1 ;
        if ( l == r ) return ;
        LL hh  = 1L L<< 48 ;
        for ( int i = l ; i <= r ; i++ )
            hh = min ( hh , a[i] );
        LL ans = hh-h;
        for ( int i = l ; i <= r ; i++ )
        {
            if ( a[i] == hh ) continue ;
            int j;
            for ( j = i; j <= r ; j++ ) {
                if ( j == r ) break ;
                if ( a[j+ 1 ] == hh ) break ;
            }
            solve ( i , j , hh );
            ans += dp[i][j];
            i = j+ 1 ;
        }
        dp[l][r] = min ( dp[l][r] , ans );
    } int main ( )
    {
        while ( ~ scanf ( "%d" , &n )) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
            solve ( 1 , n , 0 );
            printf ( "%I64d\n" , dp[ 1 ][n] );
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX (1<<18)
    using namespace std ;
    typedef long long LL;
    {
        while ( ~ scanf ( "%s" , s ) )
        {
            scanf ( "%d" , &m );
            n = strlen ( s );
            int total = 1 <<n;
            memset ( num , 0 , sizeof ( num ) );
            memset ( dp , 0 , sizeof ( dp ) );
            dp[ 0 ][ 0 ] = 1 ;
            fac[ 0 ] = 1 ;
            for ( LL i = 0 ; i < n ; i++ ) {
                fac[i+ 1 ] = fac[i]*(i+ 1L L);
                num[s[i]- 48 ]++;
            }
            for ( int i = 0 ; i < total ; i++ ) for ( int k = 0 ; k < m ; k++ ) {
                    if ( !dp[i][k] ) continue ;
                    for ( int j = 0 ; j < n ; j++ ) {
                        int x = s[j]- 48 ;
                        if ( x == 0 && i == 0 ) continue ;
                        if ( ( 1 <<j)&i ) continue ;
                        int y = ( 1 <<j)|i;
                        int z = (k* 10L L+x)%m;
                        dp[y][z] += dp[i][k];
                    }
                }
            LL temp = 1 ;
            for ( int i = 0 ; i < 10 ; i++ )
                temp *= fac[num[i]];
            printf ( "%lld\n" , dp[total- 1 ][ 0 ]/temp );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 2007
    using namespace std ;
    typedef long long LL;
    int n,d,a[MAX];
    const LL mod = 1e9 + 7 ;
    vector < int > e[MAX];
    {
        for ( int i = 0 ; i < MAX ; i++ )
            e[i].clear();
    } void add ( int u , int v )
    {
        e[u].push_back ( v );
        e[v].push_back ( u );
    }
    void dfs ( int u , int p , int x )
    {
        dp[u] = 1 ;
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            if ( v == p ) continue ;
            if ( a[v] > a[x] ) continue ;
            if ( a[v] < max( 0 ,a[x]-d) ) continue ;
            if ( a[v] == a[x] && v < x ) continue ;
            dfs ( v , u , x );
            dp[u] *= dp[v]+ 1L L;
            dp[u] %= mod;
        }
    }
    int main ( )
    {
        while ( ~ scanf ( "%d%d" , &d , &n ) ) {
            Clear();
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            for ( int i = 1 ; i < n ; i++ ) {
                int x,y;
                scanf ( "%d%d" , &x , &y );
                add ( x , y );
            }
            LL ans = 0 ;
            memset ( used , 0 , sizeof ( used ) );
            for ( int i = 1 ; i <= n ; i++ ) {
                dfs ( i , - 1 , i );
                ans += dp[i];
                ans %= mod;
            }
            printf ( "%lld\n" , ans );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 200007
    using namespace std ;
    int n;
    int w[MAX];
    int h[MAX];
    int lsum[MAX];
    int rsum[MAX];
    int dp[MAX][ 23 ];
    void init ( )
    {
        for ( int i = 1 ; i <= n ; i++ )
            dp[i][ 0 ] = h[i];
        for ( int j = 1 ; ( 1 <<j) <= n ; j++ ) for ( int i = 1 ; i+( 1 <<j)- 1 <= n ; i++ )
                dp[i][j] = max ( dp[i][j- 1 ] , dp[i+( 1 <<(j- 1 ))][j- 1 ] );
        lsum[ 0 ] = rsum[n+ 1 ] = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
            lsum[i] = lsum[i- 1 ] + w[i];
        for ( int i = n ; i >= 1 ; i-- )
            rsum[i] = rsum[i+ 1 ] + w[i];
    }
    int query ( int l , int r )
    {
        int k = ( int )(( log (r-l+ 1 )* 1.0 )/ log ( 2.0 ));
        return max ( dp[l][k] , dp[r-( 1 <<k)+ 1 ][k] );
    }
    int main ( )
    {
        while ( ~ scanf ( "%d" , &n ) ) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d%d" , &w[i] , &h[i] );
            init (); //cout << query ( 1 , 2 ) << " " << query ( 2 , 3 ) << endl; printf ( "%d" , rsum[ 2 ]*query( 2 ,n) ); for ( int i = 2 ; i <= n ; i++ )
            {
                int x = query( 1 , i- 1 );
                if ( i != n )
                    x = max ( x , query ( i+ 1 , n ));
                printf ( " %d" , (lsum[i- 1 ] + rsum[i+ 1 ])*x );
            }
            puts ( "" );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 5007
    using namespace std ;
    int dp[MAX][MAX],n,m;
    char s[MAX],t[MAX];
    int sum[MAX];
    const int mod = 1e9 + 7 ;
    int main ( )
    {
        while ( ~ scanf ( "%s %s" , s , t ) ) {
            n = strlen ( s );
            m = strlen ( t );
            memset ( dp , 0 , sizeof ( dp ) );
            int ans = 0 ;
            for ( int i = 0 ; i < n ; i++ ) if ( s[i] == t[ 0 ] ) {
                    dp[i][ 0 ] = 1 ;
                    ans++;
                }
            for ( int i = 1 ; i < m ; i++ ) if ( s[ 0 ] == t[i] ) {
                    dp[ 0 ][i] = 1 ;
                    ans++;
                }
            for ( int i = 1 ; i < n ; i ++ ) {
                sum[ 0 ] = dp[i- 1 ][ 0 ];
                for ( int j = 1 ; j < m ; j++ ) {
                    sum[j] = sum[j- 1 ] + dp[i- 1 ][j];
                    sum[j] %= mod;
                }
                for ( int j = 1 ; j < m ; j++ ) {
                    if ( s[i] == t[j] )
                        dp[i][j] = sum[j- 1 ] + 1 ;
                    else dp[i][j] = 0 ;
                    dp[i][j] %= mod;
                    ans += dp[i][j];
                    ans %= mod;
                }
            }
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
    using namespace std ;
    typedef long long LL;
    {
        while ( ~ scanf ( "%lld%lld" , &l , &r ) )
        {
            ans = 0 ;
            LL num = 1 ;
            while ( num <= r ) num *= 2L L;
            num /= 2 ;
            LL num1,num2,x;
            while ( num ) {
                x = num;
                num1 = num2 = 0 ;
                while ( num ) {
                    if ( num > r ) {
                        num >>= 1 ;
                        continue ;
                    }
                    if ( num1 >= l && num2 >= l ) {
                        if ( num1 + num <= r ) {
                            num1 += num;
                            ans += num;
                        } else if ( num2 + num <= r ) {
                            num2 += num;
                            ans += num;
                        }
                    } else if ( num1 >= l ) {
                        num2 += num;
                        ans += num;
                    } else {
                        num1 += num;
                        ans += num;
                    }
                    num >>= 1 ;
                }
                if ( num1 >= l && num2 >= l ) break ;
                else ans = 0 ;
                l -= x;
                r -= x;
                while ( x > r ) x /= 2 ;
                num = x;
            }
            printf ( "%lld\n" , ans );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 100007
    using namespace std ;
    int n,a[MAX];
    struct Tree
    {
        int l,r,maxn;
    } tree[MAX<< 2 ];
    void push_up ( int u )
    {
        tree[u].maxn = max ( tree[u<< 1 ].maxn , tree[u<< 1 | 1 ].maxn );
    }
    void build ( int u , int l , int r )
    {
        tree[u].l = l;
        tree[u].r = r;
        int mid = l+r>> 1 ;
        tree[u].maxn = 0 ;
        if ( l == r ) return ;
        build ( u<< 1 , l , mid );
        build ( u<< 1 | 1 , mid+ 1 , r );
    }
    void update ( int u , int x , int v )
    {
        int l = tree[u].l;
        int r = tree[u].r;
        int mid = l+r>> 1 ;
        if ( l == r ) {
            tree[u].maxn = v;
            return ;
        }
        if ( x > mid ) update ( u<< 1 | 1 , x , v );
        else update ( u<< 1 , x , v );
        push_up ( u );
    }
    int query ( int u , int left , int right )
    {
        int l = tree[u].l;
        int r = tree[u].r;
        int mid = l+r>> 1 ;
        if ( left <= l && r <= right ) return tree[u].maxn;
        int ret = 0 ;
        if ( left <= mid && right >= l )
            ret = max ( ret , query ( u<< 1 , left , right ) );
        if ( left <= r && right > mid )
            ret = max ( ret , query ( u<< 1 | 1 , left , right ) );
        return ret;
    }
    int main ( )
    {
        while ( ~ scanf ( "%d" , &n ) ) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            build ( 1 , 1 , n );
            int x,ans= 1 ;
            update ( 1 , a[ 1 ] , 1 );
            for ( int i = 2 ; i <= n ; i++ ) {
                x = query ( 1 , 1 , a[i] );
                ans = max ( ans , x+ 1 );
                update ( 1 , a[i] , x+ 1 );
            }
            printf ( "%d\n" , ans );
        }
    }
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 100007
    using namespace std ;
    char s[MAX];
    int r[MAX],sa[MAX],wa[MAX],wb[MAX],wv[MAX],wss[MAX],rank[MAX],height[MAX];
    int cnt[MAX];
    bool mark[MAX];
    int cmp ( int *r , int a , int b , int len )
    {
        return r[a]==r[b]&&r[a+len]==r[b+len];
    }
    void da ( int * r , int * sa , int n , int m )
    {
        int i,j,p, *x = wa , *y = wb , *t;
        for ( i = 0 ; i < m ; i++ ) wss[i] = 0 ;
        for ( i = 0 ; i < n ; i++ ) wss[x[i] = r[i]]++;
        for ( i = 0 ; i < m ; i++ ) wss[i] += wss[i- 1 ];
        for ( i = n- 1 ; i >= 0 ; i-- ) sa[--wss[x[i]]] = i;
        for ( j = 1 , p = 1 ; p < n ; j *= 2 , m = p ) {
            for ( p = 0 , i = n - j ; i < n ; i++ ) y[p++] = i;
            for ( i = 0 ; i < n ; i++ ) if ( sa[i] >= j ) y[p++] = sa[i]-j;
            for ( i = 0 ; i < n ; i++ ) wv[i] = x[y[i]];
            for ( i = 0 ; i < m ; i++ ) wss[i] = 0 ;
            for ( i = 0 ; i < n ; i++ ) wss[wv[i]]++;
            for ( i = 0 ; i < m ; i++ ) wss[i] += wss[i- 1 ];
            for ( i = n- 1 ; i >= 0 ; i-- ) sa[--wss[wv[i]]] = y[i];
            for ( t = x , x = y , y = t , p = 1 , x[sa[ 0 ]] = 0 , i = 1 ; i < n ; i++ )
                x[sa[i]] = cmp ( y , sa[i- 1 ] , sa[i] , j ) ? p- 1 : p++;
        }
    }
    void calheight ( int *r , int *sa , int n )
    {
        int i , j , k = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) rank[sa[i]] = i;
        for ( int i = 0 ; i < n ; height[rank[i++]] = k ) for ( k?k--: 0 , j = sa[rank[i]- 1 ] ; r[i+k] == r[j+k] ; k++ );
    }
    int main ( )
    {
        while ( ~ scanf ( "%s" , s ) ) {
            memset ( cnt , 0 , sizeof ( cnt ) );
            memset ( mark , 0 , sizeof ( mark ) );
            int len = strlen ( s );
            for ( int i = 0 ; i < len ; i++ )
                r[i] = s[i] - 'A' + 1 ;
            da ( r , sa , len+ 1 , 27 );
            calheight ( r , sa, len );
            int x = rank[ 0 ];
            int temp = 1 << 29 ;
            for ( int i = x + 1 ; i <= len; i ++ ) {
                temp = min ( temp , height[i] );
                int id = sa[i];
                if ( sa[i]+temp >= len )
                    mark[temp] = true ;
                cnt[temp]++;
            }
            temp = height[x];
            for ( int i = x- 1 ; i >= 1 ; i -- ) {
                cnt[temp]++;
                int id = sa[i];
                if ( sa[i]+temp >= len )
                    mark[temp] = true ;
                temp = min ( temp , height[i] );
            }
            mark[len] = true ;
            cnt[len] = 1 ;
            int ans = 0 ;
            for ( int i = len- 1 ; i > 0 ; i-- )
                cnt[i] += cnt[i+ 1 ];
            for ( int i = 1 ; i <= len ; i ++ ) if ( mark[i] )  ans++;
            printf ( "%d\n" , ans );
            for ( int i = 1 ; i <= len ; i++ ) {
                if ( !mark[i] ) continue ;
                printf ( "%d %d\n" , i , cnt[i] );
            }
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1007
    using namespace std;
    int n, m ;
    int a[MAX][MAX];
    int u,v;
    int dp[ 4 ][MAX][MAX];
    int main ( )
    {
        while ( ~scanf ( " %d %d " , &n , & m ) ) {
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ )
                    scanf ( " %d " , &a[i][j] );
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ ) {
                    dp[ 0 ][i][j] = 0 ;
                    if ( i > 1 )
                        dp[ 0 ][i][j] = max ( dp[ 0 ][i- 1 ][j] , dp[ 0 ][i][j] );
                    if ( j > 1 )
                        dp[ 0 ][i][j] = max ( dp[ 0 ][i][j- 1 ] , dp[ 0 ][i][j] );
                    dp[ 0 ][i][j] += a[i][j];
                }
            for ( int i = n ; i >= 1 ; i-- ) for ( int j = 1 ; j <= m ; j++ ) {
                    dp[ 1 ][i][j] = 0 ;
                    if ( i < n )
                        dp[ 1 ][i][j] = max ( dp[ 1 ][i+ 1 ][j] , dp[ 1 ][i][j] );
                    if ( j > 1 )
                        dp[ 1 ][i][j] = max ( dp[ 1 ][i][j- 1 ] , dp[ 1 ][i][j] );
                    dp[ 1 ][i][j] += a[i][j];
                }
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = m ; j >= 1 ; j-- ) {
                    dp[ 2 ][i][j] = 0 ;
                    if ( i > 1 )
                        dp[ 2 ][i][j] = max ( dp[ 2 ][i- 1 ][j] , dp[ 2 ][i][j] );
                    if ( j < m )
                        dp[ 2 ][i][j] = max ( dp[ 2 ][i][j+ 1 ] , dp[ 2 ][i][j] );
                    dp[ 2 ][i][j] += a[i][j];
                }
            for ( int i = n ; i >= 1 ; i-- ) for ( int j = m ; j >= 1 ; j-- ) {
                    dp[ 3 ][i][j] = 0 ;
                    if ( i < n )
                        dp[ 3 ][i][j] = max ( dp[ 3 ][i+ 1 ][j] , dp[ 3 ][i][j] );
                    if ( j < m )
                        dp[ 3 ][i][j] = max ( dp[ 3 ][i][j+ 1 ] , dp[ 3 ][i][j] );
                    dp[ 3 ][i][j] += a[i][j];
                }
            / *for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ ) {
                    dp[ 0 ][i][j+ 1 ] = max ( dp[ 0 ][i][j+ 1 ] , dp[ 0 ][i][j] + a[i][j+ 1 ] );
                    dp[ 0 ][i+ 1 ][j] = max ( dp[ 0 ][i+ 1 ][j] , dp[ 0 ][i][j] + a[i+ 1 ][j] );
                }
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = m ; j >= 1 ; j-- ) {
                    dp[ 2 ][i][j- 1 ] = max ( dp[ 2 ][i][j- 1 ] , dp[ 2 ][i][j] + a[i][j- 1 ] );
                    dp[ 2 ][i+ 1 ][j] = max ( dp[ 2 ][i+ 1 ][j] , dp[ 2 ][i][j] + a[i+ 1 ][j] );
                }
            for ( int i = n ; i >= 1 ; i-- ) for ( int j = 1 ; j <= m ; j++ ) {
                    dp[ 1 ][i][j+ 1 ] = max ( dp[ 1 ][i][j+ 1 ] , dp[ 1 ][i][j] + a[i][j+ 1 ] );
                    dp[ 1 ][i- 1 ][j] = max ( dp[ 1 ][i- 1 ][j] , dp[ 1 ][i][j] + a[i- 1 ][j] );
                }
            for ( int i = n ; i >= 1 ; i-- ) for ( int j = n ; j >= 1 ; j-- ) {
                    dp[ 3 ][i][j- 1 ] = max ( dp[ 3 ][i][j- 1 ] , dp[ 3 ][i][j] + a[i][j- 1 ] );
                    dp[ 3 ][i- 1 ][j] = max ( dp[ 3 ][i- 1 ][j] , dp[ 3 ][i][j] + a[i- 1 ][j] );
                } */ int ans = 0 ;
            for ( int i = 2 ; i < n ; i++ ) for ( int j = 2 ; j < m ; j++ ) {
                    ans = max ( ans , dp[ 0 ][i- 1 ][j]+dp[ 3 ][i+ 1 ][j]+dp[ 1 ][i][j- 1 ]+dp[ 2 ][i][j+ 1 ] );
                    ans = max ( ans , dp[ 0 ][i][j- 1 ]+dp[ 3 ][i][j+ 1 ]+dp[ 1 ][i+ 1 ][j]+dp[ 2 ][i- 1 ][j] );
                }
            printf ( " %d \n" , ans );
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 1007
    using namespace std;
    int n, x ;
    int dp[ 2 ][MAX][MAX];
    int p[ 2 ][MAX][MAX];
    void print ( int x , int y , int k , int f  )
    {
        if ( x == 1 && y == 1 );
        else if ( x == 1 ) print ( x , y - 1 , k , 0 );
        else if ( y == 1 ) print ( x - 1 , y , k , 1 );
        else {
            if ( dp[k][ x ][ y ] == dp[k][ x - 1 ][ y ] + p[k][ x ][ y ] ) print ( x - 1 , y , k , 1 );
            else print ( x , y - 1 , k , 0 );
        }
        if ( f == 3 ) return ;
        printf ( " %c " , f? 'D' : 'R' );
    }
    int main ( )
    {
        while ( ~scanf ( " %d " , &n ) ) {
            int flag = 0 ,a,b;
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= n ; j++ ) {
                    scanf ( " %d " , & x );
                    if ( ! x ) {
                        flag = 1 ;
                        p[ 0 ][i][j]++;
                        p[ 1 ][i][j]++;
                        a = i , b = j;
                        continue ;
                    }
                    while ( x %2 == 0 ) {
                        p[ 0 ][i][j]++;
                        x /= 2 ;
                    }
                    while ( x %5 == 0 ) {
                        p[ 1 ][i][j]++;
                        x /= 5 ;
                    }
                }
            memset ( dp , 0x3f , sizeof ( dp ) );
            for ( int k = 0 ; k < 2 ; k++ ) for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= n ; j++ ) {
                        if ( i- 1 )
                            dp[k][i][j] = min ( dp[k][i][j] , dp[k][i- 1 ][j] );
                        if ( j- 1 )
                            dp[k][i][j] = min ( dp[k][i][j] , dp[k][i][j- 1 ] );
                        if ( i == j && i == 1 )
                            dp[k][i][j] = 0 ;
                        dp[k][i][j] +=  p[k][i][j];
                    }
            int ans = min ( dp[ 0 ][n][n] , dp[ 1 ][n][n] );
            if ( ans > 1 && flag ) {
                puts ( "1" );
                for ( int i = 1 ; i < a ; i++ ) printf ( " %c " , 'D' );
                for ( int j = 1 ; j < b ; j++ ) printf ( " %c " , 'R' );
                for ( int i = a ; i < n ; i++ ) printf ( " %c " , 'D' );
                for ( int j = b ; j < n ; j++ ) printf ( " %c " , 'R' );
                puts ( "" );
                continue ;
            }
            printf ( " %d \n" , ans );
            if ( dp[ 0 ][n][n] < dp[ 1 ][n][n] ) print ( n , n , 0 , 3 );
            else print ( n , n , 1 , 3 );
            puts ( "" );
        }
    }
#include <iostream>
# include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100007
#define INF (-(1<<29));
    using namespace std ;
    int n,m,d;
    int dp[MAX];
    int dd[MAX];
    int mark[MAX];
    int lef[MAX],rig[MAX];
    vector < int > e[MAX];
    void add ( int u , int v )
    {
        e[u].push_back ( v );
        e[v].push_back ( u );
    }
    void dfs ( int u , int p )
    {
        if ( mark[u] ) dp[u] = 0 ;
        else dp[u] = INF;
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            if ( v == p ) continue ;
            dfs ( v , u );
            dp[u] = max ( dp[u] , dp[v] + 1 );
        }
    }
    void dfs1 ( int u , int p )
    {
        lef[ 0 ] = INF;
        rig[e[u].size()+ 1 ] = INF;
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int x = i+ 1 ;
            int v = e[u][i];
            if ( v == p ) {
                lef[x] = lef[x- 1 ];
                continue ;
            }
            lef[x] = max ( lef[x- 1 ] , dp[v] );
        }
        for ( int i = e[u].size()- 1 ; i >= 0 ; i-- ) {
            int x = i+ 1 ;
            int v = e[u][i];
            if ( v == p ) {
                rig[x] = rig[x+ 1 ];
                continue ;
            }
            rig[x] = max ( rig[x+ 1 ] , dp[v] );
        }
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            if ( v == p ) continue ;
            dd[v] = max ( dd[u] , max ( lef[i], rig[i+ 2 ])+ 1 )+ 1 ;
            dp[v] = max ( dp[v] , dd[v] );
        }
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            if ( v == p ) continue ;
            dfs1 ( v , u );
        }
    }
    void Clear ()
    {
        for ( int i = 0 ; i < MAX ; i++ )
            e[i].clear();
    }
    int main ( )
    {
        while ( ~ scanf ( "%d%d%d" , &n , &m, &d ) ) {
            int x,y;
            Clear();
            memset ( mark , 0 , sizeof ( mark ) );
            memset ( dd , - 0x3f , sizeof ( dd ) );
            for ( int i = 0 ; i < m ; i++ ) {
                scanf ( "%d" , &x );
                mark[x] = 1 ;
            }
            for ( int i = 1 ; i < n ; i++ ) {
                scanf ( "%d%d" , &x , &y );
                add ( x, y );
            }
            dfs ( 1 , - 1 );
            if ( mark[ 1 ] ) dd[ 1 ] = 0 ;
            else dd[ 1 ] = INF;
            dfs1 ( 1 , - 1 );
            int ans = 0 ;
            for ( int i = 1 ; i <= n ; i ++ ) if ( dp[i] <= d && dp[i] >= 0 )
                    ans++;
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 200007
#define INF (1<<29)
    using namespace std ;
    typedef long long LL;
    int n;
    int a[MAX];
    {
        e[u].push_back ( v );
    } void dfs ( int u )
    {
        if ( !e[u].size()) {
            dp[u][ 1 ] = a[u];
            dp[u][ 0 ] = 0 ;
            return ;
        }
        dp[u][ 1 ] = -INF;
        dp[u][ 0 ] = 0 ;
        LL t1,t0;
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            dfs ( v );
            t1 = dp[u][ 1 ];
            t0 = dp[u][ 0 ];
            dp[u][ 1 ] = max ( t0 + dp[v][ 1 ] , t1 + dp[v][ 0 ] );
            dp[u][ 0 ] = max ( t0 + dp[v][ 0 ] , t1 + dp[v][ 1 ] );
        }
        dp[u][ 1 ] = max ( dp[u][ 1 ] , dp[u][ 0 ] + a[u] );
    }
    int main ( )
    {
        int x,y;
        while ( ~ scanf ( "%d" , &n )) {
            for ( int i = 0 ; i < MAX ; i++ )
                e[i].clear();
            for ( int i = 1 ; i <= n ; i++ ) {
                scanf ( "%d%d" , &x , &y );
                if ( x != - 1 )
                    add ( x , i );
                a[i] = y;
            }
            dfs ( 1 );
            printf ( "%I64d\n" , max ( dp[ 1 ][ 0 ] , dp[ 1 ][ 1 ]) );
        }
    }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 107
    using namespace std ;
    int n1,n2,k1,k2;
    const int mod = 1e8 ;
    int dp[MAX<< 1 ][MAX][ 12 ][ 2 ];
    int main ( )
    {
        while ( ~ scanf ( "%d%d%d%d" , &n1 , &n2 , &k1 , &k2 ) ) {
            memset ( dp , 0 , sizeof ( dp ) );
            dp[ 1 ][ 1 ][ 1 ][ 0 ] = 1 ;
            dp[ 1 ][ 0 ][ 1 ][ 1 ] = 1 ;
            int n = n1+n2;
            for ( int i = 2 ; i <= n; i ++ ) for ( int j = 0 ; j <= i && j <= n1 ; j++ ) {
                    for ( int k = 1 ; k <= k2 && k <= i-j ; k++ ) {
                        dp[i][j][ 1 ][ 0 ] += dp[i- 1 ][j- 1 ][k][ 1 ];
                        dp[i][j][ 1 ][ 0 ] %= mod;
                    }
                    for ( int k = 1 ; k <= k1 && k <= j ; k++ ) if ( i- 1 >= j ) {
                            dp[i][j][ 1 ][ 1 ] += dp[i- 1 ][j][k][ 0 ];
                            dp[i][j][ 1 ][ 1 ] %= mod;
                        }
                    for ( int k = 2 ; k <= j&& k <= k1 ; k++ ) {
                        dp[i][j][k][ 0 ] += dp[i- 1 ][j- 1 ][k- 1 ][ 0 ];
                        dp[i][j][k][ 0 ] %= mod;
                    }
                    if ( i- 1 < j ) continue ;
                    for ( int k = 2 ; k <= i-j && k <= k2 ; k++ ) {
                        dp[i][j][k][ 1 ] += dp[i- 1 ][j][k- 1 ][ 1 ];
                        dp[i][j][k][ 1 ] %= mod;
                    }
                } /*cout << "-------------------" << endl;
cout << "====================" << endl;
cout << dp[3][1][1][0] << endl;
cout << "====================" << endl;
cout << dp[5][2][1][0] << endl;
cout << dp[5][2][1][1] << endl;
cout << dp[5][2][2][1] << endl;
cout << "-------------------" << endl;*/ int ans = 0 ;
            for ( int i = 1 ; i <= k1 ; i++ ) {
                ans += dp[n][n1][i][ 0 ];
                ans %= mod;
            }
            for ( int i = 1 ; i <= k2 ; i++ ) {
                ans += dp[n][n1][i][ 1 ];
                ans %= mod;
            }
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 3007
    using namespace std ;
    int n;
    int a[ 3 ][MAX];
    int dp[MAX][ 3 ][ 3 ];
    int main ()
    {
        while ( ~ scanf ( "%d" , &n ) ) {
            for ( int i = 0 ; i < 3 ; i++ ) for ( int j = 1 ; j <= n ; j ++ ) scanf ( "%d" , &a[i][j] );
            int INF =-( 1 << 29 );
            memset ( dp , - 0x3f , sizeof ( dp ) );
            dp[ 1 ][ 0 ][ 0 ] = a[ 0 ][ 1 ];
            dp[ 1 ][ 1 ][ 1 ] = a[ 1 ][ 1 ];
            dp[ 1 ][ 1 ][ 0 ] = dp[ 1 ][ 2 ][ 0 ] = INF;
            for ( int i = 2 ; i <= n ; i++ ) {
                dp[i][ 0 ][ 0 ] = max ( dp[i- 1 ][ 1 ][ 1 ] + a[ 0 ][i] , dp[i- 1 ][ 2 ][ 0 ] + a[ 0 ][i] );
                dp[i][ 1 ][ 0 ] = max ( dp[i- 1 ][ 1 ][ 0 ] + a[ 1 ][i] , dp[i- 1 ][ 0 ][ 0 ] + a[ 1 ][i] );
                dp[i][ 1 ][ 1 ] = max ( dp[i- 1 ][ 1 ][ 1 ] + a[ 1 ][i] , dp[i- 1 ][ 2 ][ 0 ] + a[ 1 ][i] );
                dp[i][ 2 ][ 0 ] = max ( dp[i- 1 ][ 1 ][ 0 ] + a[ 2 ][i] , dp[i- 1 ][ 0 ][ 0 ] + a[ 2 ][i] );
            }
            int ans = 0 ;
            ans = max ( ans , dp[n][ 0 ][ 0 ] );
            ans = max ( ans , dp[n][ 1 ][ 0 ] );
            printf ( "%d\n" , ans );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 100007
    using namespace std ;
    typedef long long LL;
    {
        for ( int i = 0 ; i < MAX ; i++ )
            e[i].clear();
        memset ( dp , 0 , sizeof ( dp ));
    } void add ( int u , int v )
    {
        e[u].push_back ( v );
        e[v].push_back ( u );
    }
    void dfs ( int u , int p )
    {
        dp[u][c[u]] = 1 ;
        for ( int i = 0 ; i < e[u].size() ; i++ ) {
            int v = e[u][i];
            if ( v == p ) continue ;
            dfs ( v , u );
            LL old[]= {dp[u][ 0 ],dp[u][ 1 ]};
            dp[u][ 1 ] = old[ 1 ]*dp[v][ 0 ]%mod + old[ 0 ]*dp[v][ 1 ]%mod+ old[ 1 ]*dp[v][ 1 ]%mod;
            dp[u][ 1 ] %= mod;
            dp[u][ 0 ] = old[ 0 ]*dp[v][ 0 ]%mod + old[ 0 ]*dp[v][ 1 ]%mod;
            dp[u][ 0 ] %= mod;
        }
    }
    int main ( )
    {
        while ( ~ scanf ( "%d" , &n )) {
            Clear();
            for ( int i = 1 ; i < n ; i++ ) {
                int x;
                scanf ( "%d" , &x );
                add ( i , x );
            }
            for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &c[i] );
            dfs ( 0 , - 1 );
            printf ( "%I64d\n" , dp[ 0 ][ 1 ] );
        }
    }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 100007
    using namespace std ;
    typedef pair< int , int > PII;
    int n,m,a[MAX],lef[MAX],rig[MAX],dp[MAX][ 30 ],ans[MAX][ 30 ];
    void make ( )
    {
        for ( int i = 1 ; i <= n ; i++ ) {
            dp[i][ 0 ] = a[i];
            ans[i][ 0 ] = i;
        }
        for ( int j = 1 ; ( 1 <<j) <= n ; j++ ) for ( int i = 1 ; i+( 1 <<j)- 1 <= n ; i++ ) {
                dp[i][j] = max ( dp[i][j- 1 ] , dp[i+( 1 <<(j- 1 ))][j- 1 ]);
                if ( dp[i][j- 1 ] == dp[i][j] )
                    ans[i][j] = ans[i][j- 1 ];
                else ans[i][j] = ans[i+( 1 <<(j- 1 ))][j- 1 ];
            }
        for ( int i = 1 ; i <= n ; i++ )
            lef[i] = rig[i] = 1 ;
        for ( int i = 2 ; i <= n ; i++ ) if ( a[i- 1 ] <= a[i] )
                lef[i] = lef[i- 1 ]+ 1 ;
        for ( int i = n- 1 ; i >= 1 ; i-- ) if ( a[i+ 1 ] <= a[i] )
                rig[i] = rig[i+ 1 ]+ 1 ;
    }
    {
        int k = ( int )(( log ((r-l+ 1 )* 1.0 ))/ log ( 2.0 ));
        int maxn;
        int temp;
        maxn = max ( dp[l][k] , dp[r-( 1 <<k)+ 1 ][k] );
        if ( maxn == dp[l][k] ) temp = ans[l][k];
        else temp = ans[r-( 1 <<k)+ 1 ][k];
        return make_pair ( maxn , temp );
    } int main ( )
    {
        while ( ~ scanf ( "%d%d" , &n , &m )) {
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            make();
            while ( m-- ) {
                int l,r;
                scanf ( "%d%d" , &l , &r );
                PII temp = query ( l , r );
                int x = temp.second; //cout << x << " " << lef[x] << " " << rig[x] << endl; if ( x-lef[x]+ 1 <= l && x+rig[x]- 1 >= r ) puts ( "Yes" ); else puts ( "No" );
            }
        }
    }
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 2007
    using namespace std ;
    double dp[MAX][MAX],p;
    int n,t;
    int main ( )
    {
        while ( ~ scanf ( "%d%lf%d" , &n , &p , &t ) ) {
            memset ( dp , 0 , sizeof ( dp ));
            dp[ 0 ][ 0 ] = 1 ;
            for ( int i = 1 ; i <= t ; i++ ) for ( int j = 0 ; j <= n ; j++ ) {
                    if ( j == n )dp[i][j] = dp[i- 1 ][j];
                    else dp[i][j] = ( 1 -p)*dp[i- 1 ][j];
                    if ( j )
                        dp[i][j] += p*dp[i- 1 ][j- 1 ]; //sum[i][j] += sum[i-1][j] + dp[i][j]; } double ans = 0 ; for ( int i = 1 ; i <= n ; i++ )
                    ans += dp[t][i]*i;
                    printf ( "%.7f\n" , ans );
                }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 10007
        using namespace std ;
        int dp[MAX];
        int s[MAX];
        int a[MAX];
        int cnt[ 307 ];
        int n,t,ans;
        int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &t ) ) {
                memset ( cnt , 0 , sizeof ( cnt ) );
                for ( int i = 1 ; i <= n ; i++ ) {
                    scanf ( "%d" , &a[i] );
                    cnt[a[i]]++;
                }
                int total = min(t,n)*n;
                for ( int i = n+ 1 ; i <= total; i++ )
                    a[i] = a[i-n];
                s[ 0 ] = 0 ;
                int top = 0 ;
                for ( int i = 1 ; i <= total; i++ ) {
                    int l= 0 ,r=top,mid;
                    while ( l != r ) {
                        mid = (l+r+ 1 )>> 1 ;
                        if ( s[mid] <= a[i] ) l = mid;
                        else r = mid- 1 ;
                    }
                    ans = max ( ans , l+ 1 );
                    if ( ans > top ) s[++top] = a[i];
                    else s[l+ 1 ] = min ( s[l+ 1 ] , a[i] );
                }
                int maxn = 0 ;
                for ( int i = 1 ; i <= 300 ; i++ )
                    maxn = max ( maxn , cnt[i] );
                ans += max ( t-n , 0 )*maxn;
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 1000007
        using namespace std ;
        int n;
        int a[MAX];
        int dp[MAX];
        int loc[MAX];
        int main ( ) {
            scanf ( "%d" , &n );
            for ( int i = 1 ; i <= n ; i++ )
                dp[i] = 1 ;
            memset ( loc , 0 , sizeof ( loc ) );
            int limit = 0 ;
            for ( int i = 1 ; i <= n ; i++ ) {
                scanf ( "%d" , &a[i] );
                loc[a[i]] = i;
                limit = max ( a[i] , limit );
            }
            int ans = 1 ;
            for ( int i = 1 ; i < n ; i++ ) for ( int j = 2 *a[i] ; j <= limit; j += a[i] ) {
                    int x = loc[j];
                    if ( !x ) continue ;
                    dp[x] = max ( dp[i]+ 1 , dp[x] );
                }
            for ( int i = 1 ; i <= n ; i++ )
                ans = max ( ans , dp[i] );
            printf ( "%d\n" , ans );
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define MAX 5007
        using namespace std ;
        typedef long long LL;
        {
            while ( ~ scanf ( "%d%d%d%d" , &n , &a , &b , &k ) ) {
                memset ( dp , 0 , sizeof ( dp ) );
                dp[ 0 ][a] = 1 ;
                for ( int i = 0 ; i <= k ; i++ ) {
                    for ( int j = 1 ; j <= n ; j++ ) {
                        if ( j == b ) continue ;
                        int d = abs ( j - b );
                        int l = max(j-d+ 1 , 1 );
                        int r = min(j+d,n+ 1 );
                        dp[i+ 1 ][l] += dp[i][j];
                        dp[i+ 1 ][l] %= mod;
                        dp[i+ 1 ][r] -= dp[i][j];
                        dp[i+ 1 ][r] %= mod;
                        if ( l <= j <= r ) {
                            dp[i+ 1 ][j] -= dp[i][j];
                            dp[i+ 1 ][j] %= mod;
                            dp[i+ 1 ][j+ 1 ] += dp[i][j];
                            dp[i+ 1 ][j+ 1 ] %= mod;
                        }
                    }
                    for ( int j = 1 ; j <= n ; j++ ) {
                        dp[i+ 1 ][j] += dp[i+ 1 ][j- 1 ];
                        dp[i+ 1 ][j] %= mod;
                    } /*cout << "i : " << i <<  endl;
    for ( int j = 1 ; j <= n ; j++ )
cout << dp[i][j] << " ";
    cout << endl;*/
                }
                LL ans = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    if ( i == b ) continue ;
                    ans += dp[k][i];
                    ans %= mod;
                }
                ans = (ans+mod)%mod;
                printf ( "%I64d\n" ,ans );
            }
        }
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100007
        using namespace std ;
        int n,s,l,a[MAX];
        int dp[MAX][ 30 ];
        int dp2[MAX][ 30 ];
        void make ( ) {
            for ( int i = 1 ; i <= n ; i++ )
                dp[i][ 0 ] = a[i],dp2[i][ 0 ] = a[i];
            for ( int j = 1 ; ( 1 <<j) <= n ; j++ ) for ( int i = 1 ; i + ( 1 <<j) - 1 <= n ; i++ ) {
                    dp[i][j] = max ( dp[i][j- 1 ] , dp[i+( 1 <<(j- 1 ))][j- 1 ] );
                    dp2[i][j] = min ( dp2[i][j- 1 ] , dp2[i+( 1 <<(j- 1 ))][j- 1 ] );
                }
        }
        int big ( int l , int r ) {
            int k = ( int )(( log (r-l+ 1 )* 1.0 )/( log ( 2.0 )));
            return max ( dp[l][k] , dp[r-( 1 <<k)+ 1 ][k] );
        }
        int small ( int l , int r ) {
            int k = ( int )(( log (r-l+ 1 )* 1.0 )/( log ( 2.0 )));
            return min ( dp2[l][k] , dp2[r-( 1 <<k)+ 1 ][k] );
        }
        struct Tree {
            int minn,l,r;
        } tree[MAX<< 2 ];
        void build ( int u , int l, int r ) {
            tree[u].l = l;
            tree[u].r = r;
            tree[u].minn = 1 << 30 ;
            if ( l == r ) return ;
            int mid = (l+r)>> 1 ;
            build ( u<< 1 , l , mid );
            build ( u<< 1 | 1 , mid+ 1 , r );
        }
        void push_up ( int u ) {
            tree[u].minn = min ( tree[u<< 1 ].minn , tree[u<< 1 | 1 ].minn );
        }
        void update ( int u , int x , int v ) {
            int l = tree[u].l;
            int r = tree[u].r;
            if ( l == r) {
                tree[u].minn = v;
                return ;
            }
            int mid = l+r>> 1 ;
            if ( x > mid )
                update ( u<< 1 | 1 , x , v );
            else update ( u<< 1 , x , v );
            push_up (u );
        }
        int query ( int u , int left , int right ) {
            int l = tree[u].l;
            int r = tree[u].r;
            if ( left <= l && r <= right ) return tree[u].minn;
            int ret = 1 << 30 ;
            int mid = l+r>> 1 ;
            if ( left <= mid && right >= l )
                ret = min ( ret , query ( u<< 1 , left , right ) );
            if ( left <= r && right > mid )
                ret = min ( ret , query ( u<< 1 | 1 , left , right ) );
            return ret;
        }
        int bsearch ( int x ) {
            int l = 1 , r = x , mid;
            while ( l < r ) {
                mid = (l+r)>> 1 ;
                if ( big ( mid , x ) - small( mid , x ) > s ) l = mid+ 1 ;
                else r = mid;
            }
            return l;
        }
        int main () {
            while ( ~ scanf ( "%d%d%d" , &n , &s , &l ) ) {
                for ( int i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &a[i] );
                make ( );
                build ( 1 , 1 , n );
                for ( int i = 1 ; i <= n ; i++ ) {
                    int ll = bsearch ( i )- 1 ;
                    int rr = i-l;
                    if ( rr < ll ) continue ;
                    if ( ll <= 0 ) {
                        update ( 1 , i , 1 );
                        continue ;
                    }
                    int x = query ( 1 , ll , rr );
                    update ( 1 , i , x+ 1 );
                }
                int x = query ( 1 , n , n );
                if ( x == 1 << 30 ) puts ( "-1" );
                else printf ( "%d\n" , x );
                return 0 ;
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 2007
        using namespace std ;
        typedef long long LL;
        int temp[MAX<< 1 ];
        int Len[MAX<< 1 ];
        int init ( char *st , int n ) {
            int i;
            temp[ 0 ] = - 1 ;
            for ( int i = 1 ; i <= 2 *n ; i+= 2 ) {
                temp[i] = - 2 ;
                temp[i+ 1 ] = st[i/ 2 ];
            }
            temp[ 2 *n+ 1 ] = - 2 ;
            temp[ 2 *n+ 2 ] = - 3 ;
            temp[ 2 *n+ 3 ] = 0 ;
            return 2 *n+ 1 ;
        }
        void manacher ( int *st , int len ) {
            int mx = 0 , ans = 0 , po = 0 ;
            for ( int i = 1 ; i <= len ; i++ ) {
                if ( mx > i )
                    Len[i] = min ( mx - i , Len[ 2 *po-i] );
                else Len[i] = 1 ;
                while ( st[i-Len[i]] == st[i+Len[i]] )
                    Len[i]++;
                if ( Len[i]+i > mx )
                    mx = Len[i]+i , po = i;
            }
        }
        char s[MAX];
        {
            while ( ~ scanf ( "%s" , s ) ) {
                ans = 0 ;
                memset ( a , 0 , sizeof ( a ) );
                int n = strlen ( s );
                manacher ( temp , init ( s, n ) );
                for ( int i = 1 ; i <= 2 *n ; i++ ) {
                    int x = Len[i];
                    if ( i& 1 ) for ( int j = 1 ; j < x ; j += 2 )
                            a[i+j]++;
                    else for ( int j = 0 ; j < x ; j += 2 )
                            a[i+j]++;
                }
                a[ 0 ] = 0 ;
                for ( int i = 1 ; i <= 2 *n ; i++ )
                    a[i] += a[i- 1 ];
                for ( int i = 1 ; i <= 2 *n ; i++ ) {
                    int x = Len[i];
                    if ( i& 1 ) for ( int j = 1 ; j < x ; j += 2 )
                            ans += a[i-j- 1 ];
                    else for ( int j = 0 ; j < x ; j += 2 )
                            ans += a[i-j- 1 ];
                }
                printf ( "%lld\n" , ans );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define MAX 307
        using namespace std ;
        typedef pair< int , int > PII;
        typedef map < int , int > MII;
        int n;
        {
            return !b?a:gcd ( b , a%b );
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n ) ) {
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &a[i].first );
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &a[i].second );
                dp.clear();
                MII::iterator it;
                dp[ 0 ] = 0 ;
                for ( int i = 0 ; i < n ; i++ ) {
                    int x = a[i].first;
                    int c = a[i].second;
                    for ( it = dp.begin() ; it != dp.end() ; it++ ) {
                        int y = it->first;
                        int d = gcd ( x , y );
                        int temp = it->second+c;
                        if ( dp[d] && dp[d] < temp ) continue ;
                        dp[d] = temp;
                    }
                }
                if ( !dp[ 1 ] ) puts ( "-1" );
                else printf ( "%d\n" , dp[ 1 ] );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 5007
        using namespace std ;
        int n,m,s[MAX],dp[MAX];
        double x;
        int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &m ) ) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d %lf" , &s[i] , &x );
                s[++n] = m+ 1 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    dp[i] = 0 ;
                    for ( int j = 1 ; j < i ; j++ ) if ( s[i] >= s[j] )
                            dp[i] = max ( dp[i] , dp[j] );
                    dp[i]++;
                }
                printf ( "%d\n" , n-dp[n] );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 4007
        using namespace std ;
        int dp[MAX][MAX],n,k;
        struct Node {
            int t,d;
            bool operator < ( const Node& a ) const
            {
                return t < a.t;
            }
        } p[MAX];
        int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                for ( int i = 0 ; i < n ; i ++ ) scanf ( "%d%d" , &p[i].t , &p[i].d );
                sort ( p , p+n );
                p[n].t = 86401 ;
                dp[ 0 ][ 1 ] = 0 ;
                dp[ 0 ][ 0 ] = p[ 0 ].t+p[ 0 ].d- 1 ;
                if ( k == n ) {
                    puts ( "86400" );
                    continue ;
                }
                for ( int i = 1 ; i < n ; i++ ) {
                    dp[i][ 0 ] = max ( p[i].t- 1 , dp[i- 1 ][ 0 ] ) + p[i].d;
                    for ( int j = 1 ; j <= k && j <= i; j++ ) {
                        int xx = p[i].t- 1 ;
                        if ( i- 1 >= j ) xx = max ( xx , dp[i- 1 ][j] );
                        dp[i][j] = min ( xx + p[i].d, dp[i- 1 ][j- 1 ] );
                    }
                }
                int ans = 0 ;
                for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j <= k ; j++ ) {
                        int x = min ( n , k-j+i+ 1 );
                        ans = max ( ans , p[x].t- 1 - dp[i][j] );
                    }
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 100007
        using namespace std ;
        char s[MAX],t[MAX];
        int mark[MAX];
        const int mod = 1e9 + 7 ;
        int dp[MAX];
        int sum[MAX];
        void get_next ( char p[] , int next [] ) {
            int i = 0 , k = - 1 , len = strlen ( p );
            next[ 0 ] = - 1 ;
            while ( i < len ) if ( k == - 1 || p[i] == p[k] )
                    i++,k++,next[i]=k;
                else k = next[k];
        }
        void match ( char s[] , char p[] ) {
            memset ( mark , 0 , sizeof ( mark ) );
            int next[MAX];
            get_next ( p , next );
            int len1 = strlen ( s );
            int len2 = strlen ( p );
            int i = 0 , j = 0 ;
            while (i < len1 ) {
                if ( j == - 1 || s[i] == p[j] ) i++ , j++;
                else j = next[j];
                if ( j == len2 )
                    mark[i] = i-len2+ 1 ;
            }
        }
        int main ( ) {
            while ( ~ scanf ( "%s" , s ) ) {
                scanf ( "%s" , t );
                match ( s , t );
                sum[ 0 ] = dp[ 0 ] = 0 ;
                int n = strlen ( s );
                for ( int i = 1 ; i <= n ; i++ ) if ( !mark[i] )
                        mark[i] = mark[i- 1 ];
                for ( int i = 1 ; i <= n ; i++ ) {
                    dp[i] = dp[i- 1 ];
                    int l = mark[i];
                    if ( !l ) continue ;
                    dp[i] += (sum[l- 1 ]+l)%mod;
                    dp[i] %= mod;
                    sum[i] = sum[i- 1 ] + dp[i];
                    sum[i] %= mod;
                }
                printf ( "%d\n" , dp[n] );
            }
        }
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAX 2007
        using namespace std ;
        typedef long long LL;
        int n,k;
        const LL mod= 1e9 + 7 ;
        {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                memset ( dp , 0 , sizeof ( dp ) );
                for ( int i = 1 ; i <= n ; i++ )
                    dp[ 1 ][i] = 1 ;
                for ( int i = 2 ; i <= k ; i++ ) for ( int j = 1 ; j <= n ; j++ ) for ( int k = 1 ; k*k<=j ; k++ ) {
                            if ( j%k ) continue ;
                            dp[i][j] += dp[i- 1 ][k];
                            dp[i][j] %= mod;
                            int x = j/k;
                            if ( x == k ) continue ;
                            dp[i][j] += dp[i- 1 ][x];
                            dp[i][j] %= mod;
                        }
                int ans = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    ans += dp[k][i];
                    ans %= mod;
                }
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 107
        using namespace std ;
        double dp[MAX][MAX][MAX];
        int r,s,p;
        int main () {
            while (~ scanf ( "%d%d%d" , &r , &s , &p )) {
                memset ( dp , 0 , sizeof ( dp ));
                dp[r][s][p] = 1.0 ;
                for ( int i = r ; i >= 1 ; i-- ) for ( int j = s ; j >= 1 ; j-- ) for ( int k = p ; k >= 1 ; k-- ) {
                            double sum = i*j+j*k+k*i;
                            dp[i- 1 ][j][k] += dp[i][j][k]*(i*k* 1.0 /sum);
                            dp[i][j- 1 ][k] += dp[i][j][k]*(j*i* 1.0 /sum);
                            dp[i][j][k- 1 ] += dp[i][j][k]*(j*k* 1.0 /sum); /*cout << dp[1][1][0] << endl;
    cout << dp[2][2][0] << endl;
    cout << dp[1][2][0] << endl;
    cout << dp[2][1][0] << endl;*/
                        }
                double ans1,ans2,ans3;
                ans1 = ans2 = ans3 = 0.0 ;
                for ( int i = 1 ; i <= 100 ; i++ ) for ( int j = 0 ; j <= 100 ; j++ ) {
                        ans1 += dp[i][j][ 0 ];
                        ans2 += dp[ 0 ][i][j];
                        ans3 += dp[j][ 0 ][i];
                    }
                printf ( "%.10f %.10f %.10f\n" , ans1 , ans2 , ans3 );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 5007
        using namespace std ;
        int n,w,h;
        int dp[MAX];
        int back[MAX];
        struct Node {
            int w,h,x;
            bool operator < ( const Node & a ) const
            {
                if ( w == a.w ) return h < a.h;
                return w < a.w;
            }
        } a[MAX];
        void print ( int x ) {
            if ( a[x]. w <= w || a[x].h <= h ) return ;
            print ( back[x] );
            printf ( "%d " , a[x].x );
        }
        int main ( ) {
            while ( ~ scanf ( "%d%d%d" , &n , &w , &h )) {
                for ( int i = 1 ; i <= n ; i++ ) {
                    scanf ( "%d%d" , &a[i].w , &a[i].h );
                    a[i].x = i;
                }
                dp[ 0 ] = - 1 ;
                sort ( a+ 1 , a+n+ 1 );
                for ( int i = 1 ; i <= n ; i++ ) {
                    int temp = - 1 ,id = 0 ;
                    for ( int j = 0 ; j < i ; j++ ) if ( a[j].w < a[i].w && a[j].h < a[i].h && a[j].w > w && a[j].h > h ) if ( temp < dp[j] ) {
                                temp = dp[j];
                                id = j;
                            }
                    if ( a[i].w > w && a[i].h > h ) dp[i] = 1 , back[i] = 0 ;
                    else dp[i] = - 1 ;
                    if ( temp+ 1 > dp[i] ) {
                        dp[i] = temp+ 1 ;
                        back[i] = id;
                    }
                }
                int maxn = 0 ;
                for ( int i = 1 ; i <= n ; i++ )
                    maxn = max ( maxn , dp[i] );
                if ( maxn == 0 ) {
                    puts ( "0" );
                    continue ;
                }
                printf ( "%d\n" , maxn );
                for ( int i = 1 ; i <= n ; i++ ) if ( maxn == dp[i] ) {
                        print ( i );
                        puts ( "" );
                        break ;
                    }
            }
        }
        \Rightarrow  h_i = max ( 0 , \min_ {j=0}^i \ { min( h_{i-j}+j-k , h_{i+j}+j-k \
                                                          } 因为k是常数，所以对于，每一项我们找到的就是最小的 h i − j + j 和 h i + j + j h_ {i-j}+j和h_ {i+j}+j ，这可用线段树进行维护。 而且要设定两个虚拟的高度为0的塔，分别放在这一堆塔的两头，这样能够维护两侧的在每次操作拿光的情况。 至于线段树维护的部分，就是遍历i两次，分别从小到大和从大到小，每次修改之前遍历过的位置为所要的状态，也就是之前遍历过的位置区间内全部加1，然后统计[0,i]的最小值，右侧的同理。
                                 AC代码：
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#define MAX 100007
        using namespace std ; int n; int l[MAX],r[MAX],h[MAX]; struct Tree {
            int l,r,minn,lazy;
        } tree[MAX<< 2 ]; void push_up ( int u ) {
            tree[u].minn = min ( tree[u<< 1 ].minn , tree[u<< 1 | 1 ].minn );
        }
        void build ( int u , int l , int r ) {
            tree[u].l = l;
            tree[u].r = r;
            tree[u].lazy = 0 ;
            int mid = l+r>> 1 ;
            if ( l == r ) {
                tree[u].minn = h[l];
                return ;
            }
            build ( u<< 1 , l , mid );
            build ( u<< 1 | 1 , mid+ 1 , r );
            push_up ( u );
        }
        void push_down ( int u ) {
            int ll = tree[u].lazy;
            tree[u].lazy = 0 ;
            if ( ll ) {
                tree[u<< 1 ].lazy += ll;
                tree[u<< 1 | 1 ].lazy += ll;
                tree[u<< 1 ].minn += ll;
                tree[u<< 1 | 1 ].minn += ll;
            }
        }
        void update ( int u , int left , int right ) {
            int l = tree[u].l;
            int r = tree[u].r;
            int mid = l+r>> 1 ;
            if ( left <= l && r <= right ) {
                tree[u].minn += 1 ;
                tree[u].lazy += 1 ;
                return ;
            }
            push_down ( u );
            if ( left <= mid && right >= l )
                update ( u<< 1 , left , right );
            if ( left <= r && right > mid )
                update ( u<< 1 | 1 , left , right );
            push_up ( u );
        }
        int query ( int u , int left , int right ) {
            int l = tree[u].l;
            int r = tree[u].r;
            int mid = l+r>> 1 ;
            if ( left <= l && r <= right ) return tree[u].minn;
            push_down ( u );
            int ret = 1 << 29 ;
            if ( left <= mid && right >= l )
                ret = min ( ret , query ( u<< 1 , left , right ) );
            if ( left <= r && right > mid )
                ret = min ( ret , query ( u<< 1 | 1 , left , right ) );
            return ret;
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n ) ) {
                h[ 0 ] = h[n+ 1 ] = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &h[i] );
                build ( 1 , 0 , n+ 1 );
                for ( int i = 1 ; i <= n ; i++ ) {
                    update ( 1 , 0 , i- 1 );
                    l[i] = query ( 1 , 0 , i );
                }
                build ( 1 , 0 , n+ 1 );
                for ( int i = n ; i > 0 ; i-- ) {
                    update ( 1 , i+ 1 , n+ 1 );
                    r[i] = query ( 1 , i , n+ 1 );
                }
                int ans = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    //cout << "YES : " << l[i] << " " << r[i] << endl; ans = max ( ans , min ( l[i] , r[i] ));
                } printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 300007
        using namespace std ; int n,k,a[MAX]; int dp[ 5007 ][ 5007 ]; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
                sort ( a+ 1 , a+n+ 1 );
                int num1 = n%k;
                int len1 = n/k+ 1 ;
                int num2 = k - num1;
                int len2 = n/k;
                a[ 0 ] = a[ 1 ];
                memset ( dp , 0 , sizeof ( dp ) );
                for ( int i = 0 ; i <= num1 ; i++ ) for ( int j = 0 ; j <= num2 ; j++ ) {
                        if ( i ) {
                            int k = (i- 1 )*len1 + j*len2;
                            dp[i][j] = max ( dp[i][j] , dp[i- 1 ][j] + a[k+ 1 ]-a[k] );
                        }
                        if ( j ) {
                            int k = i*len1 + (j- 1 )*len2;
                            dp[i][j] = max ( dp[i][j] , dp[i][j- 1 ] + a[k+ 1 ]-a[k] );
                        }
                    }
                int ans = a[n]-a[ 1 ] - dp[num1][num2];
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 30
        using namespace std ; int n,m; char a[MAX][MAX]; int h[MAX][MAX]; int l[MAX][MAX]; int r[MAX][MAX]; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &m ) ) {
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%s" , a[i] );
                for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j < m ; j++ ) {
                        if ( a[i][j] == '1' ) {
                            h[i][j] = 0 ;
                            continue ;
                        }
                        if ( i == 0 || a[i- 1 ][j] == '1' )
                            h[i][j] = 1 ;
                        else h[i][j] = h[i- 1 ][j] + 1 ;
                    }
                int ans = 0 ;
                for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j < m ; j++ ) for ( int k = 1 ; k <= h[i][j] ; k++ ) {
                            int l = j;
                            while ( l >= 0 && h[i][l] >= k )
                                l--;
                            ans = max ( ans , (j-l)+k );
                        }
                printf ( "%d\n" , ans* 2 );
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#define MAX 200007
        using namespace std ; typedef long long LL; int n,k; int a[MAX]; map < int ,LL> dp[ 4 ];
        {
            while (~ scanf ( "%d%d" , &n , &k ) ) {
                ans = 0 ;
                for ( int i = 0 ; i < 4 ; i++ )
                    dp[i].clear();
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
                for ( int i = 1 ; i <= n ; i++ ) {
                    int x = a[i];
                    if ( x%k == 0 ) {
                        dp[ 3 ][x] += dp[ 2 ][x/k];
                        dp[ 2 ][x] += dp[ 1 ][x/k];
                    }
                    dp[ 1 ][x] += 1 ;
                }
                map < int ,LL> ::iterator it = dp[ 3 ].begin();
                for ( ; it != dp[ 3 ].end() ; it++ )
                    ans += (*it).second;
                printf ( "%I64d\n" , ans );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 1007
        using namespace std ; int n,m; int a[MAX*MAX]; int dp[MAX][MAX]; int main ( ) {
            scanf ( "%d%d" , &n , &m );
            for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
            if ( n > m ) {
                puts ( "YES" );
                return 0 ;
            }
            memset ( dp , 0 , sizeof ( dp ) );
            dp[ 0 ][ 0 ] = 1 ;
            bool flag = false ;
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = m- 1 ; j >= 0 ; j-- ) {
                    int x = ((j-a[i])%m+m)%m;
                    if ( dp[i- 1 ][x] ) {
                        dp[i][j] = 1 ;
                        if ( j == 0 )
                            flag = true ;
                    }
                    if ( dp[i- 1 ][j] )  dp[i][j] = 1 ;
                }
            if ( flag ) puts ( "YES" );
            else puts ( "NO" );
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 300007
        using namespace std ; int n,m; int dp[MAX],g[MAX]; struct Edge {
            int u,v,w; bool operator < ( const Edge& a ) const {
                return w < a.w;
            }
        } e[MAX]; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &m ) ) {
                for ( int i = 0 ; i < m ; i++ ) scanf ( "%d%d%d" , &e[i].u , &e[i].v , &e[i].w );
                sort ( e , e+m );
                int t = 0 ;
                e[m].w = - 1 ;
                int ans = 0 ;
                for ( int i = 0 ; i < m ; i++ ) {
                    int v = e[i].v;
                    int u = e[i].u;
                    int w = e[i].w;
                    dp[i] = g[e[i].u]+ 1 ;
                    if ( e[i].w != e[i+ 1 ].w ) {
                        for ( int j = t ; j <= i ; j++ )
                            g[e[j].v] = max ( g[e[j].v] , dp[j] );
                        t = i+ 1 ;
                    }
                    ans = max ( ans , dp[i] );
                }
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 507
        using namespace std ; typedef long long LL; const LL mod = 1e9 + 7 ;
        {
            if ( dp[l][r] != - 1 ) return dp[l][r];
            if ( l == r ) return dp[l][r] = 1L L;
            LL ans = 0 ;
            for ( int i = l+ 1 ; i <= r ; i++ ) {
                if ( i != r && b[l+ 1 ] >= b[i+ 1 ] ) continue ;
                ans += dfs ( l+ 1 , i )* dfs ( i , r )%mod;
                ans %= mod;
            }
            return dp[l][r] = ans;
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n )) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d" , &b[i] );
                memset ( dp , - 1 , sizeof ( dp ));
                printf ( "%I64d\n" , dfs( 1 , n ) );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define M 27
#define N 100007
        using namespace std ; typedef long long LL; typedef map <LL,LL> Dic;
        {
            for ( int i = 0 ; i < 26 ; i++ ) {
                dic[i].clear();
                scanf ( "%d" , &a[i] );
            }
            scanf ( "%s" , s );
            int n = strlen ( s );
            LL sum = 0 ;
            LL ans = 0 ;
            for ( int i = 0 ; i < n ; i++ ) {
                int x = s[i]- 'a' ;
                LL y = dic[x][sum];
                sum += a[x];
                ans += y;
                dic[x][sum]++;
            }
            printf ( "%I64d\n" , ans );
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define MAX 100007
        using namespace std ; typedef long long LL; int n,u,v;
        {
            up[u] = down[u] = 0 ;
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                dfs ( v , u );
                up[u] = max ( up[u] , up[v] );
                down[u] = max ( down[u] , down[v] );
            }
            a[u] += up[u]-down[u];
            if ( a[u] > 0 ) down[u] += a[u];
            else up[u] -= a[u];
        }
        void add ( int u , int v ) {
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        int main () {
            while (~ scanf ( "%d" , &n )) {
                for ( int i = 0 ; i < MAX ; i++ )
                    e[i].clear();
                for ( int i = 1 ; i < n ; i++ ) {
                    scanf ( "%d%d" , &u , &v );
                    add ( u , v );
                }
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%I64d" , &a[i] );
                dfs ( 1 , - 1 );
                printf ( "%I64d\n" , up[ 1 ]+down[ 1 ] );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 50007
        using namespace std ; typedef long long LL; int n,k,a,b;
        {
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        void Clear ( ) {
            for ( int i = 0 ; i < MAX ; i++ )
                e[i].clear();
        }
        void dfs ( int u , int p ) {
            dp[u][ 0 ] = 1 ;
            for ( int i = 1 ; i <= k ; i++ )
                dp[u][i] = 0 ;
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                dfs ( v , u );
                for ( int j = 1 ; j <= k ; j++ )
                    dp[u][j] += dp[v][j- 1 ];
            }
        }
        void solve ( int u , int p ) {
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                for ( int j = k; j >= 1 ; j-- ) {
                    dp[v][j] += dp[u][j- 1 ];
                    if ( j > 1 ) dp[v][j] -= dp[v][j- 2 ];
                }
                solve ( v , u );
            }
        }
        int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                Clear();
                for ( int i = 1 ; i < n ; i++ ) {
                    scanf ( "%d%d" , &a , &b );
                    add ( a , b );
                }
                ans = 0 ;
                dfs ( 1 , - 1 );
                solve ( 1 , - 1 ); /*for ( int i = 1; i <= n ; i++ )
    for ( int j = 0 ; j <= k ; j++ )
cout << i << " " << j << " " << dp[i][j] << endl;*/ for ( int i = 1 ; i <= n ; i++ )
                    ans += dp[i][k];
                printf ( "%I64d\n" , ans/ 2L L );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100007
        using namespace std ; int fa[MAX][ 25 ]; int dp[MAX]; int siz[MAX]; int n,m; vector < int > e[MAX]; void add ( int u , int v ) {
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        void dfs ( int u , int p ) {
            if ( p == - 1 ) dp[u] = 1 ;
            siz[u] = 1 ;
            for ( int i = 1 ; i < 21 ; i++ )
                fa[u][i] = fa[fa[u][i- 1 ]][i- 1 ];
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                dp[v] = dp[u]+ 1 ;
                fa[v][ 0 ] = u;
                dfs ( v , u );
                siz[u] += siz[v];
            }
        }
        int lca ( int u , int v ) {
            if ( dp[u] < dp[v] )
                swap ( u , v );
            for ( int i = 20 ; i >= 0 ; i-- ) {
                if ( dp[fa[u][i]] >= dp[v] )
                    u = fa[u][i];
                if ( u == v ) return u;
            }
            for ( int i = 20 ; i >= 0 ; i-- ) if ( fa[u][i] != fa[v][i] ) {
                    v = fa[v][i];
                    u = fa[u][i];
                }
            return fa[u][ 0 ];
        }
        void init ( ) {
            for ( int i = 0 ; i < MAX ; i++ )
                e[i].clear();
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n )) {
                init ();
                for ( int i = 1 ; i < n ; i++ ) {
                    int x,y;
                    scanf ( "%d%d" , &x , &y );
                    add ( x , y );
                }
                dfs ( 1 , - 1 );
                scanf ( "%d" , &m );
                while ( m-- ) {
                    int x,y,ans;
                    scanf ( "%d%d" , &x , &y );
                    if ( x == y ) {
                        printf ( "%d\n" , n );
                        continue ;
                    }
                    int f = lca ( x , y );
                    if ( dp[x] > dp[y] ) swap ( x , y );
                    if ( f == x ) {
                        int l = dp[y] - dp[x];
                        if ( l& 1 ) ans = 0 ;
                        else {
                            l /= 2 ;
                            l--;
                            int fy = y,fx;
                            int num = 0 ;
                            while ( l ) {
                                if ( l& 1 ) fy = fa[fy][num];
                                num++;
                                l >>= 1 ;
                            }
                            fx = fa[fy][ 0 ];
                            ans = siz[fx] - siz[fy];
                        }
                    } else {
                        int l = dp[x]+dp[y]- 2 *dp[f];
                        if ( l& 1 ) ans = 0 ;
                        else {
                            l /= 2 ;
                            l--;
                            int ll = l;
                            int fy = y ,fx;
                            int num = 0 ;
                            while ( l ) {
                                if ( l& 1 ) fy = fa[fy][num];
                                num++;
                                l >>= 1 ;
                            }
                            if ( dp[x] == dp[y] ) {
                                fx = x;
                                int num = 0 ;
                                while ( ll ) {
                                    if ( ll& 1 ) fx = fa[fx][num];
                                    num++;
                                    ll >>= 1 ;
                                }
                                ans = n - siz[fx] - siz[fy];
                            } else {
                                fx = fa[fy][ 0 ];
                                ans = siz[fx] - siz[fy];
                            }
                        }
                    }
                    printf ( "%d\n" , ans );
                }
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 500
        using namespace std ; int s[ 2 ][MAX]; int len[MAX]; int n,a[MAX]; void print ( int i ) {
            int x = i% 2 ;
            for ( int j = len[i]- 1 ; j >= 0 ; j-- ) printf ( "%d" , s[x][j] );
            puts ( "" );
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n ) ) {
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &a[i] );
                memset ( len , 0 , sizeof ( len ));
                int temp = a[ 0 ];
                while ( temp ) {
                    if ( temp > 8 ) {
                        s[ 0 ][len[ 0 ]++] = 9 ;
                        temp -= 9 ;
                    } else {
                        s[ 0 ][len[ 0 ]++] = temp;
                        temp = 0 ;
                    }
                }
                s[ 0 ][len[ 0 ]] = 0 ;
                print ( 0 );
                for ( int i = 1 ; i < n ; i++ ) {
                    int x = i% 2 ;
                    int y = (i- 1 )% 2 ;
                    memset ( s[x] , 0 , sizeof ( s[x] ));
                    if ( a[i] > a[i- 1 ] ) {
                        int d = a[i]-a[i- 1 ];
                        int j = 0 ;
                        while ( d ) {
                            int tt = s[y][j];
                            if ( s[y][j] != 9 ) {
                                if ( d >= 9 -tt ) {
                                    d -= 9 -tt;
                                    s[x][len[i]++] = 9 ;
                                } else {
                                    s[x][len[i]++] = tt+d;
                                    d = 0 ;
                                }
                            } else s[x][len[i]++] = 9 ;
                            j++;
                        }
                        for ( int k = j ; k < len[i- 1 ] ; k++ )
                            s[x][len[i]++] = s[y][k];
                    } else {
                        int d = a[i- 1 ]-a[i]+ 1 ;
                        for ( int j = 1 ; j <= len[i- 1 ] ; j++ ) {
                            int sum = -d;
                            for ( int k = j- 1 ; k >= 0 ; k-- ) {
                                int tt = s[y][k];
                                sum += tt;
                            }
                            if ( sum < 0 ) continue ;
                            for ( int k = 0 ; k < j ; k++ ) {
                                if ( sum >= 9 ) {
                                    s[x][k] = 9 ;
                                    sum -= 9 ;
                                } else {
                                    s[x][k] = sum;
                                    sum = 0 ;
                                }
                            }
                            if ( sum == 0 && s[y][j] != 9 ) {
                                s[x][j] = s[y][j]+ 1 ;
                                if ( j == len[i- 1 ] ) len[i] = len[i- 1 ]+ 1 ;
                                else len[i] = len[i- 1 ];
                                for ( int k = j+ 1 ; k < len[i] ; k++ )
                                    s[x][k] = s[y][k];
                                break ;
                            }
                        }
                    }
                    print ( i );
                }
            }
        }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#define MAX 507
        using namespace std ; typedef long long LL;
        {
            while (~ scanf ( "%d" , &n )) {
                mp.clear();
                for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= n ; j++ ) scanf ( "%I64d" , &a[i][j] );
                for ( int i = 1 ; i <= n ; i++ ) {
                    scanf ( "%d" , &x[i] );
                    mp[x[i]] = n+ 1 -i;
                }
                for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= n ; j++ )
                        dp[mp[i]][mp[j]] = a[i][j];
                for ( int k = 1 ; k <= n ; k++ ) {
                    for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= n ; j++ )
                            dp[i][j] = min ( dp[i][j] , dp[i][k] + dp[k][j] );
                    for ( int i = 1 ; i <= k; i++ ) for ( int j = 1 ; j <= k; j++ )
                            ans[n-k+ 1 ] += dp[i][j];
                }
                for ( int i = 1 ; i <= n ; i++ ) printf ( "%I64d " , ans[i] );
                puts ( "" );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 500007
        using namespace std ; int n; char s[MAX][ 12 ]; int len[MAX]; int dp[ 30 ][ 30 ]; int main ( ) {
            while ( ~ scanf ( "%d" , &n )) {
                for ( int i = 0 ; i < n ; i++ ) {
                    scanf ( "%s" , s[i] );
                    len[i] = strlen ( s[i] );
                }
                memset ( dp , - 1 , sizeof ( dp ));
                for ( int i = 0 ; i < n ; i++ ) {
                    int x = s[i][ 0 ]- 'a' ;
                    int y = s[i][len[i]- 1 ] - 'a' ;
                    for ( int j = 0 ; j < 26 ; j++ ) if ( dp[j][x] != - 1 )
                            dp[j][y] = max ( dp[j][x]+len[i] , dp[j][y] );
                    dp[x][y] = max ( dp[x][y] , len[i] );
                }
                int ans = 0 ;
                for ( int i = 0 ; i < 26 ; i++ ) for ( int j = 0 ; j < 26 ; j++ ) if ( i == j )
                            ans = max ( ans , dp[i][j] );
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1007
        using namespace std; double dp[MAX][MAX]; int w,b, sum ; void calc ( int x ) {
            sum = x+x/ 2 ;
            sum = w+b- sum ;
        }
        int main ( ) {
            while ( ~scanf ( "%d%d" , &w , &b ) ) {
                if ( w == 0 ) {
                    puts ( "0.0000000000" );
                    continue ;
                }
                memset ( dp , 0 ,sizeof ( dp ) );
                dp[ 0 ][b] = 1.0 ;
                for ( int i = 1 ; i <= b; i++ ) {
                    calc ( i- 1 );
                    for ( int j = 0 ; j <= b ; j++ ) {
                        dp[i][j] = 0 ;
                        if ( i& 1 )
                            dp[i][j] = dp[i- 1 ][j+ 1 ]*((j+ 1 )* 1.0 /( sum * 1.0 ));
                        else {
                            double x = (j+ 1 )*(j+ 2 )* 1.0 /( sum *( sum - 1 )* 1.0 );
                            dp[i][j] += dp[i- 1 ][j+ 2 ]*x;
                            x = (j+ 1 )*( sum - 1 -j)* 1.0 /( sum *( sum - 1 )* 1.0 );
                            dp[i][j] += dp[i- 1 ][j+ 1 ]*x;
                        }
                    }
                }
                double ans = 0 ;
                for ( int i = 0 ; i <= b ; i += 2 ) for ( int j = 0 ; j <= b ; j++ ) {
                        calc ( i );
                        if ( sum == 0 || sum < j  ) continue ; //cout << dp[i][j] << " " <<  ans << endl; ans += dp[i][j]*(( sum -j) * 1.0 /( sum * 1.0 ));
                    }
                printf ( "%.10lf\n" , ans );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 5007
        using namespace std ; int n,m; char mp[MAX][MAX]; int lef[MAX]; int h[MAX][MAX]; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &m )) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%s" , mp[i]+ 1 );
                memset ( h , 0 , sizeof ( h ));
                int ans = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    for ( int j = 1 ; j <= m ; j++ ) {
                        if ( mp[i][j] == '0' ) h[i][j] = 0 ;
                        else if ( i == 1 || mp[i- 1 ][j]== '0' )
                            h[i][j] = 1 ;
                        else h[i][j] = h[i- 1 ][j]+ 1 ;
                        if ( j == 1 || h[i][j- 1 ] < h[i][j] )
                            lef[j] = j;
                        else lef[j] = lef[j- 1 ];
                    }
                    for ( int j = 1 ; j <= m ; j++ )
                        ans = max ( ans , (j-lef[j]+ 1 )*h[i][j] );
                }
                printf ( "%d\n" , ans );
            }
        } 那么对于可以行互换的，我们已经记录每个点能够向左延展的距离,定义状态dp[j][i]代表第j列的第i行的元素向左延展的最远距离，然后我们对这个距离排序，从大到小，每个上面的都可以被下面的拓展，那么依旧是枚举每个右下角，取最大的结果。
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 5007
        using namespace std ; int n,m; int dp[MAX][MAX]; char mp[MAX][MAX]; int main () {
            while ( ~ scanf ( "%d%d" , &n , &m )) {
                for ( int i = 1 ; i<= n ; i++ ) scanf ( "%s" , mp[i]+ 1 );
                for ( int i= 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ ) if ( mp[i][j] == '1' )
                            dp[j][i] = dp[j- 1 ][i]+ 1 ;
                        else dp[j][i] = 0 ;
                int ans = 0 ;
                for ( int i = 1 ; i <= m ; i++ ) {
                    sort ( dp[i]+ 1 , dp[i]+n+ 1 );
                    for ( int j = n ; j > 0 ; j-- )
                        ans = max ( ans , dp[i][j]*(n-j+ 1 ) );
                }
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 300007
        using namespace std ; int n,m,q; vector < int > e[MAX]; int fa[MAX]; int ans[MAX]; void clear() {
            for ( int i = 0 ; i < MAX ; i++ )
                e[i].clear();
            for ( int i = 1 ; i < MAX ; i++ )
                fa[i] = i;
        }
        void add ( int u , int v ) {
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        int _find ( int x ) {
            return x == fa[x]?x:fa[x] = _find ( fa[x] );
        }
        void _union ( int x , int y , int f ) {
            x = _find ( x );
            y = _find ( y );
            if ( x > y ) swap ( x , y );
            fa[y] = x;
            if ( f ) return ;
            int xx = ans[x];
            int yy = ans[y];
            ans[x] = max ( max ( xx , yy ) , (xx+ 1 )/ 2 + (yy+ 1 )/ 2 + 1 );
        }
        bool used[MAX]; bool mark[MAX]; int pp,dis; void dfs ( int u , int d , int p ) {
            if ( d > dis ) {
                dis = d;
                pp = u;
            }
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                dfs  ( v , d+ 1 , u );
            }
        }
        int main ( ) {
            while ( ~ scanf ( "%d%d%d" , &n , &m , &q) ) {
                clear();
                int x,y,z;
                for ( int i = 0 ; i < m ; i++ ) {
                    scanf ( "%d%d" , &x, &y);
                    add ( x , y );
                    _union ( x , y , 1 );
                }
                memset ( used , 0 , sizeof ( used ) );
                for ( int i = 1 ; i <= n ; i++ ) {
                    int x = _find ( i );
                    if ( used[x] ) continue ;
                    pp = dis = - 1 ;
                    used[x] = true ;
                    dfs ( x , 1 , - 1 );
                    dis = 0 ;
                    dfs ( pp , 0 , - 1 );
                    ans[x] = dis;
                }
                for ( int i = 0 ; i < q ; i++ ) {
                    scanf ( "%d" , &z );
                    if ( z == 1 ) {
                        scanf ( "%d" , &x );
                        printf ( "%d\n" , ans[_find(x)] );
                    } else {
                        scanf ( "%d%d" , &x , &y );
                        if ( _find(x) == _find(y) ) continue ;
                        _union ( x , y , 0 );
                    }
                }
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX  5007
        using namespace std ; char s[MAX]; int n,q,dp[MAX][MAX]; int isPar[MAX][MAX]; int check ( int l , int r ) {
            if ( l == r ) return 1 ;
            if ( s[l] != s[r] ) return 0 ;
            if ( r-l == 1 ) return 1 ;
            if ( isPar[l+ 1 ][r- 1 ] ) return 1 ;
            return 0 ;
        }
        int main ( ) {
            while ( ~ scanf ( "%s" , s ) ) {
                int n = strlen ( s );
                memset ( isPar , 0 , sizeof ( isPar ) );
                for ( int i = 0 ; i < n ; i++ )
                    dp[i][i] = 1 ;
                for ( int i = 0 ; i < n ; i++ ) for ( int j = 0 ; j+i < n ; j++ ) {
                        int k = j+i;
                        isPar[j][k] = check ( j , k );
                    }
                for ( int i = 1 ; i < n ; i++ ) {
                    for ( int j = 0 ; j+i <n ; j++ ) {
                        int k = j+i;
                        dp[j][k] = dp[j][k- 1 ] + dp[j+ 1 ][k];
                        if ( i > 1 )
                            dp[j][k] -= dp[j+ 1 ][k- 1 ];
                        dp[j][k] += isPar[j][k];
                    }
                }
                scanf ( "%d" , &q );
                while ( q-- ) {
                    int l,r;
                    scanf ( "%d%d" , &l , &r );
                    l--,r--;
                    printf ( "%d\n" , dp[l][r] );
                }
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 3007
        using namespace std ; int n,a[MAX]; int main ( ) {
            while ( ~ scanf ( "%d" , &n ) ) {
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &a[i] );
                int m = 0 ;
                for ( int i = 1 ; i < n; i++ ) for ( int j = 0 ; j < i ; j++ ) if ( a[j] > a[i] )
                            m++;
                int ans = 0 ;
                if ( m& 1 )
                    ans = 1 + m/ 2 * 4 ;
                else ans = m* 2 ;
                printf ( "%.7f\n" , ( double )ans );
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 47
        using namespace std ; int n,m,q; char s[MAX][MAX]; int l[MAX][MAX]; int sum[MAX][MAX][MAX][MAX]; void init ( ) {
            memset ( l , 0 , sizeof ( l ) );
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ ) {
                    if ( s[i][j] == '1' ) continue ;
                    if ( s[i][j- 1 ] == '0' )
                        l[i][j] = l[i][j- 1 ] + 1 ;
                    else l[i][j] = 1 ;
                }
            for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= m ; j++ ) for ( int k = i ; k<= n ; k++ ) for ( int t = j ; t <= m ; t++ ) {
                            int temp,ss;
                            temp = 1 << 29 ;
                            ss = 0 ;
                            for ( int x = k ; x >= i ; x-- ) {
                                int ll = min ( t-j+ 1 , l[x][t] );
                                temp = min ( ll , temp );
                                ss += temp;
                            }
                            sum[i][j][k][t] = ss;
                        }
        }
        int main ( ) {
            while ( ~ scanf ( "%d%d%d" , &n , &m , &q ) ) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%s" , s[i]+ 1 );
                init ( );
                int a,b,c,d;
                while ( q-- ) {
                    scanf ( "%d%d%d%d" , &a , &b , &c , &d );
                    int ans = 0 ;
                    for ( int i = a ; i <= c ; i++ ) for ( int j = b ; j <= d ; j++ )
                            ans += sum[a][b][i][j];
                    printf ( "%d\n" , ans );
                }
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 200007
        using namespace std ; typedef long long LL;
        {
            if ( vis[x][d% 2 ] ) return ;
            vis[x][d% 2 ] = 1 ;
            if ( d& 1 ) {
                int y = x-a[x];
                if ( y <= 0 ) {
                    dp[x][d% 2 ] = a[x];
                    return ;
                }
                dfs ( y , d+ 1 );
                if ( dp[y][(d+ 1 )% 2 ] != - 1 )
                    dp[x][d% 2 ] = dp[y][(d+ 1 )% 2 ] + a[x];
            } else {
                int y = x+a[x];
                if ( y > n ) {
                    dp[x][d% 2 ] = a[x];
                    return ;
                }
                dfs ( y , d+ 1 );
                if ( dp[y][(d+ 1 )% 2 ] != - 1 )
                    dp[x][d% 2 ] = dp[y][(d+ 1 )% 2 ] + a[x];
            }
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &n ) ) {
                for ( int i = 2 ; i <= n ; i++ ) scanf ( "%d" , &a[i] );
                memset ( vis , 0 , sizeof ( vis ) );
                memset ( dp , - 1 , sizeof ( dp ) );
                dp[ 1 ][ 0 ] = - 1 ;
                vis[ 1 ][ 0 ] = 1 ;
                dp[ 1 ][ 1 ] = 0 ;
                vis[ 1 ][ 1 ] = 1 ;
                for ( int i = 2 ; i <= n ; i++ )
                    dfs ( i , 1 );
                for ( int i = 2 ; i <= n ; i++ ) if ( dp[i][ 1 ] != - 1 )
                        dp[i][ 1 ] += i- 1 ;
                for ( int i = 2 ; i <= n ; i++ ) printf ( "%lld\n" , dp[i][ 1 ] );
            }
        }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
#include <cctype>
#include <vector>
#define MAX 207
        using namespace std ; vector < int > e[MAX]; map < string , int > dic; int dp[MAX]; int n,m,b; const string joker = "polycarp" ; void add ( int u , int v ) {
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        void handle ( string &s ) {
            int len = s.length();
            for ( int i = 0 ; i <len ; i++ ) if ( isupper (s[i])) s[i] = ( char )(s[i]+ 32 );
        }
        void init ( ) {
            dic.clear();
            for ( int i = 0 ; i < MAX ; i++ )
                e[i].clear();
            n = 0 ;
        }
        void dfs ( int u , int p ) {
            dp[u] = 1 ;
            for ( int i = 0 ; i < e[u].size() ; i++ ) {
                int v = e[u][i];
                if ( v == p ) continue ;
                dfs ( v , u );
                dp[u] = max ( dp[u] , dp[v]+ 1 );
            }
        }
        int main ( ) {
            while ( ~ scanf ( "%d" , &m )) {
                init ();
                string x,y,s;
                int u,v;
                while ( m-- ) {
                    cin >> x >> s >> y;
                    handle( x );
                    handle( y );
                    if ( !dic[x] ) dic[x] = ++n;
                    if ( !dic[y] ) dic[y] = ++n;
                    add ( dic[x] , dic[y] );
                }
                b = dic[joker];
                dfs ( b , - 1 );
                printf ( "%d\n" , dp[b] );
            }
        }
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
        using namespace std ;
#define LL __int64
#define pi acos(-1.0) const int mod= 100000000 ; const int INF= 0x3f3f3f3f ; const double eqs= 1e-8 ; int dp[ 31000 ][ 300 ], w[ 31000 ], max1, max2; int dfs( int cur, int lenth)
        {
            if (cur>max1) return 0 ;
            if (dp[cur][lenth]!=- 1 ) return dp[cur][lenth];
            if (lenth> 1 ) dp[cur][lenth]=max(dp[cur][lenth],dfs(cur+lenth- 1 ,lenth- 1 )+w[cur]);
            dp[cur][lenth]=max(dp[cur][lenth],dfs(cur+lenth,lenth)+w[cur]);
            dp[cur][lenth]=max(dp[cur][lenth],dfs(cur+lenth+ 1 ,lenth+ 1 )+w[cur]);
            max2=max(max2,dp[cur][lenth]);
            return dp[cur][lenth];
        }
        int main() {
            int n, d, i, j, x, len, pre;
            max1=- 1 ;
            scanf ( "%d%d" ,&n,&d);
            memset (w, 0 , sizeof (w));
            memset (dp,- 1 , sizeof (dp));
            for (i= 0 ; i<n; i++) {
                scanf ( "%d" ,&x);
                w[x]++;
                max1=max(max1,x);
            }
            max2= 0 ;
            dfs(d,d);
            printf ( "%d\n" ,max2);
            return 0 ;
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1007
        using namespace std ; int n,k; int dp[MAX]; int pos[MAX][MAX]; int a[MAX][MAX]; int cnt[MAX]; vector < int > ans; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                ans.clear();
                for ( int i = 1 ; i <= k ; i++ ) for ( int j = 1 ; j <= n ; j++ ) scanf ( "%d" , &a[i][j] );
                for ( int i = 1 ; i <= k ; i++ ) for ( int j = 1 ; j <= n ; j++ )
                        pos[i][a[i][j]] = j;
                memset ( dp , 0 , sizeof ( dp ) );
                memset ( cnt , 0 , sizeof ( cnt ) );
                ans.push_back ( 0 );
                for ( int i = 1 ; i <= n ; i++ ) for ( int j = 1 ; j <= k ; j++ ) {
                        int x = a[j][i];
                        cnt[x]++;
                        if ( cnt[x] == k ) {
                            for ( int t = 0 ; t < ans.size() ; t++ ) {
                                int u = ans[t];
                                bool flag = true ;
                                for ( int v = 1 ; v <= k ; v++ ) if ( pos[v][u] >= pos[v][x] )
                                        flag = false ;
                                if ( flag )
                                    dp[x] = max ( dp[x] , dp[u]+ 1 );
                            }
                            ans.push_back ( x );
                            cnt[x]++;
                        }
                    }
                int pp = 0 ;
                for ( int i = 1 ; i <= n ; i++ )
                    pp = max ( pp , dp[i] );
                printf ( "%d\n" , pp );
            }
        }
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define INF (1<<29)
#define MAX 200007
        using namespace std ; int n; struct Node {
            int w,x; bool operator < ( const Node& a ) const {
                return w+x < a.w+a.x;
            }
        } p[MAX]; int bsearch ( int i ) {
            int l = 0 , r = i- 1 ,mid;
            while ( l != r ) {
                mid = (l+r+ 1 )>> 1 ;
                if ( p[i].x - p[i].w < p[mid].x + p[mid].w ) r = mid- 1 ;
                else l = mid;
            }
            return l;
        }
        struct Tree {
            int l,r,maxn;
        } tree[MAX<< 2 ]; void build ( int u , int l , int r ) {
            tree[u].l = l;
            tree[u].r = r;
            tree[u].maxn = 0 ;
            if ( l == r ) return ;
            int mid = l+r>> 1 ;
            build ( u<< 1 , l , mid );
            build ( u<< 1 | 1 , mid+ 1 , r );
        }
        void push_up ( int u ) {
            tree[u].maxn = max ( tree[u<< 1 ].maxn , tree[u<< 1 | 1 ].maxn );
        }
        void update ( int u , int x , int v ) {
            int l = tree[u].l;
            int r = tree[u].r;
            if ( l == r ) {
                tree[u].maxn = v;
                return ;
            }
            int mid = l+r>> 1 ;
            if ( x > mid ) update ( u<< 1 | 1 , x , v );
            else update ( u<< 1 , x , v );
            push_up ( u );
        }
        int query ( int u , int left , int right ) {
            int l = tree[u].l , r = tree[u].r;
            if ( left <= l && r <= right ) return tree[u].maxn;
            int mid = l+r>> 1 ;
            int ret = 0 ;
            if ( l <= mid && r >= left ) ret = query ( u<< 1 , left , right );
            if ( left <= r && right > mid )
                ret = max ( ret ,query ( u<< 1 | 1 , left , right ) );
            return ret;
        }
        int main () {
            while ( ~ scanf ( "%d" , &n )) {
                for ( int i = 1 ; i <= n ; i++ ) scanf ( "%d%d" , &p[i].x , &p[i].w );
                sort ( p+ 1 , p+n+ 1 );
                build ( 1 , 0 , n );
                update ( 1 , 0 , 0 );
                p[ 0 ].x = - INF;
                p[ 0 ].w = - INF;
                int ans = 0 ;
                for ( int i = 1 ; i <= n ; i++ ) {
                    int x = bsearch ( i ); //dp[i] = dp[x]+1; int v = query ( 1 , 0 , x );
                    update ( 1 , i , v+ 1 );
                    ans = max ( v+ 1 , ans );
                }
                printf ( "%d\n" , ans );
            }
        }
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 107
        using namespace std ; int dp[MAX*MAX],dd[MAX*MAX]; int n,k,a[MAX],b[MAX],c[MAX]; int main ( ) {
            while ( ~ scanf ( "%d%d" , &n , &k ) ) {
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &a[i] );
                for ( int i = 0 ; i < n ; i++ ) scanf ( "%d" , &b[i] );
                for ( int i = 0 ; i < n ; i++ )
                    c[i] = a[i]-b[i]*k;
                memset ( dp , - 0x3f , sizeof ( dp ) );
                memset ( dd , - 0x3f , sizeof ( dd ) );
                dp[ 0 ] = dd[ 0 ] = 0 ;
                for ( int i = 0 ; i < n ; i++ ) if ( c[i] >= 0 ) for ( int j = 10000 ; j >= c[i] ; j-- )
                            dp[j] = max ( dp[j-c[i]]+a[i] , dp[j] );
                for ( int i = 0 ; i < n ; i++ ) if ( c[i] < 0 ) {
                        c[i] = -c[i];
                        for ( int j = 10000 ; j >= c[i] ; j-- )
                            dd[j] = max ( dd[j-c[i]]+a[i] , dd[j] );
                    }
                int ans = - 1 ;
                for ( int i = 0 ; i <= 10000 ; i++ ) {
                    if ( dd[i] == 0 && dp[i] == 0 ) continue ;
                    ans = max ( ans , dp[i]+dd[i] );
                }
                printf ( "%d\n" , ans );
            }
        }
