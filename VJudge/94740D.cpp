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

const int maxn = 10;
double a[maxn][maxn] = {0}, ans[maxn] = {0};
bool l[maxn];
int n;

int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    return x>eps?1:-1;
}

inline int solve(double a[][maxn], bool l[], double ans[], const int& n)
{
    int res = 0, r = 0;
    for (int i = 0; i < n; i++) l[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = r; j < n; j++)
            if (fabs(a[j][i]) > eps) {
                for (int k = i; k <= n; k++) swap(a[j][k], a[r][k]);
                break;
            }
        if (fabs(a[r][i]) < eps) {
            res++;
            continue;
        }
        for (int j = 0; j < n; j++)
            if (j != r && fabs(a[j][i]) > eps) {
                double tmp = a[j][i] / a[r][i];
                for (int k = i; k <= n; k++) a[j][k] -= tmp * a[r][k];
            }
        l[i] = true, r++;
    }
    for (int i = r; i < n; i++) if (fabs(a[i][n]) > eps) return -1;
    for (int i = 0; i < n; i++)
        if (l[i])
            for (int j = 0; j < n; j++)
                if (fabs(a[j][i]) > eps)
                    ans[i] = a[j][n] / a[j][i];
    return res;
}

int t;

int main()
{
    double x1,y1,r1,x2,y2,r2,x3,y3;
    scanf("%d", &t);
    while(t--) {
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3);

        a[0][0]=2*x2-2*x1;
        a[0][1]=2*y2-2*y1;
        a[0][2]=2*r2-2*r1;
        a[0][3]=r1*r1-r2*r2+x2*x2-x1*x1+y2*y2-y1*y1;

        a[1][0]=2*x3-2*x1;
        a[1][1]=2*y3-2*y1;
        a[1][2]=-2*r1;
        a[1][3]=r1*r1+x3*x3-x1*x1+y3*y3-y1*y1;

        a[2][0]=2*x3-2*x2;
        a[2][1]=2*y3-2*y2;
        a[2][2]=-2*r2;
        a[2][3]=r2*r2+x3*x3-x2*x2+y3*y3-y2*y2;

        int x = solve(a,l,ans,3);
        if(sgn(ans[2])==-1) {
            cout<<0<<endl;
            continue;
        }
        if(x==0) {
            cout<<1<<endl;
            printf("%.8f %.8f %.8f\n", ans[0],ans[1],ans[2]);
        } else if(x>0) {
            double r = ans[2];
            double x = ans[0];
            double y = ans[1];
            double cnt;
            if(!l[0]) {
                cout<<2<<endl;
                cnt = sqrt(r*r-(y-y3)*(y-y3));
                printf("%.8f %.8f %.8f\n", cnt+x3,ans[1],ans[2]);
                printf("%.8f %.8f %.8f\n", -cnt+x3,ans[1],ans[2]);
            } else if(!l[1]) {
                cout<<2<<endl;
                cnt = sqrt(r*r-(x-x3)*(x-x3));
                printf("%.8f %.8f %.8f\n", ans[0],cnt+y3,ans[2]);
                printf("%.8f %.8f %.8f\n", ans[0],-cnt+y3,ans[2]);
            } else {
                cout<<1<<endl;
                cnt = sqrt(x*x+y*y);
                printf("%.8f %.8f %.8f\n", ans[0],ans[1],cnt);
            }
        } else {
            cout<<0<<endl;
        }
    }
    return 0;
}
