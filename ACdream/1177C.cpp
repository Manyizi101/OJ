#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
using namespace std;

const int MAXN = 2005 ;
const int MAXQ = 1000005 ;
const int MAXE = 1000005 ;
const int INF = 0x3f3f3f3f ;


int m, n, k;
int H[MAXN] , cntE ;
int d[MAXN] , cur[MAXN] , cap[MAXN] ;
int vis[MAXN] , Time ;
int Q[MAXQ] , head , tail ;
int ss , tt ;
int s , t ;
int flow, cost ;
int a[17][105] ;
int i, j;

struct Edge
{
    int v , c , w , n ;
    Edge () {}
    Edge ( int v , int c , int w , int n ) : v ( v ) , c ( c ) , w ( w ) , n ( n ) {}
} E[MAXE] ;

void clear ()
{
    cntE = 0 ;
    memset(H, -1, sizeof(H));
}

void addedge ( int u , int v , int c , int w )
{
    E[cntE] = Edge ( v , c , +w , H[u] ) ;
    H[u] = cntE ++ ;
    E[cntE] = Edge ( u , 0 , -w , H[v] ) ;
    H[v] = cntE ++ ;
}

int spfa ()
{
    head = tail = 0 ;
    memset(d, INF, sizeof(d));
    ++ Time ;
    d[ss] = 0 ;
    cap[ss] = INF ;
    cur[ss] = -1 ;
    Q[tail ++] = ss ;
    while ( head != tail )
    {
        int u = Q[head ++] ;
        vis[u] = Time - 1 ;
        for ( int i = H[u] ; ~i ; i = E[i].n )
        {
            int v = E[i].v , c = E[i].c , w = E[i].w ;
            if ( c && d[v] > d[u] + w )
            {
                d[v] = d[u] + w ;
                cap[v] = min ( cap[u] , c ) ;
                cur[v] = i ;
                if ( vis[v] != Time )
                {
                    vis[v] = Time ;
                    Q[tail ++] = v ;
                }
            }
        }
    }
    if ( d[tt] == INF ) return 0 ;
    cost += d[tt] * cap[tt] ;
    flow += cap[tt] ;
    for ( int i = cur[tt] ; ~i ; i = cur[E[i ^ 1].v] )
    {
        E[i].c -= cap[tt] ;
        E[i ^ 1].c += cap[tt] ;
    }
    return 1 ;
}

int mcmf ()
{
    flow = cost = 0 ;
    while ( spfa () ) ;
    return cost ;
}

void solve ()
{
    clear () ;
    s = n * m ;
    t = s + 1 ;
    ss = t + 1 ;
    tt = ss + 1 ;
    addedge ( ss , s , k , 0 ) ;
    addedge ( t , tt , k , 0 ) ;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
        {
            int ij = i * m + j ;
            if ( ( i + j ) & 1 )
            {
                addedge ( s , ij , 1 , 0 ) ;
                if ( i < n - 1 ) addedge ( ij , ij + m , 1 , -a[i][j] * a[i + 1][j] ) ;
                if ( j < m - 1 ) addedge ( ij , ij + 1 , 1 , -a[i][j] * a[i][j + 1] ) ;
                if ( i ) addedge ( ij , ij - m , 1 , -a[i][j] * a[i - 1][j] ) ;
                if ( j ) addedge ( ij , ij - 1 , 1 , -a[i][j] * a[i][j - 1] ) ;
            }
            else addedge ( ij , t , 1 , 0 ) ;
        }
    printf ( "%d\n" , -mcmf () ) ;
}

int main(int argc, char const *argv[])
{
    memset(vis, 0, sizeof(vis));
    Time = 0;
    while ( ~scanf ( "%d%d%d" , &n , &m , &k ) ) solve () ;
    return 0;
}













