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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const ll MOD = 1000000007LL;
const int N = 2;
ll fac[2][505];
int cnt, ct;

ll pri[6]= {2,3,7,109,167,500000003};
ll num[6]= {4,2,1,2,1,1};

struct Matrix {
    ll m[N][N];
};

Matrix A;
Matrix I = {1,0,0,1};


Matrix multi(Matrix a, Matrix b)
{
    Matrix c;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; ++j) {
            c.m[i][j]=0;
            for(int k=0; k<2; ++k) {
                c.m[i][j]+=a.m[i][k]*b.m[k][i];
                c.m[i][j]%=MOD;
            }
        }
    }
    return c;
}

Matrix power(Matrix A, ll n)
{
    Matrix ans =I, p = A;
    while(n) {
        if(n&1) {
            ans = multi(ans,p);
            n--;
        }
        n>>=1;
        p=multi(p,p);
    }
    return ans;
}

ll quick_mod(ll a, ll b)
{
    ll ans = 1;
    a %= MOD;
    while(b) {
        if(b&1) {
            ans = ans * a % MOD;
            b--;
        }
        b>>=1;
        a = a* a%MOD;
    }
    return ans;
}

ll Legendre(ll a, ll p)
{
    ll t = quick_mod(a, (p-1)>>1);
    if(t==1)    return 1;
    return -1;
}

void dfs(int dept, ll product = 1)
{
    if(dept==cnt) {
        fac[1][ct++]=product;
        return;
    }
    for(int i=0; i<=num[dept]; ++i) {
        dfs(dept+1, product);
        product *= pri[dept];
    }
}

bool OK(Matrix A, ll n)
{
    Matrix ans = power(A, n);
    return ans.m[0][0]==1&&ans.m[0][1]==0&&ans.m[1][0]==0&&ans.m[1][1]==1;
}

int main()
{
    fac[0][0]=1;
    fac[0][1]=2;
    fac[0][2]=500000003;
    fac[0][3]=1000000006;
    ll a,b,c,d;
    while(cin>>a>>b>>c>>d) {
        ll t = a*a+4*b;
        A.m[0][0]=a;
        A.m[0][1]=b;
        A.m[1][0]=1;
        A.m[1][1]=0;
        if(Legendre(t,MOD)==1) {
            for(int i=0; i<4; ++i) {
                if(OK(A,fac[0][i])) {
                    printf("%I64d\n",fac[0][i]);
                    break;
                }
            }
        } else {
            ct =0;
            cnt = 6;
            dfs(0,1);
            sort(fac[1],fac[1]+ct);
            for(int i=0; i<ct; ++i) {
                if(OK(A,fac[1][i])) {
                    printf("%I64d\n", fac[1][i]);
                    break;
                }
            }
        }
    }
}
