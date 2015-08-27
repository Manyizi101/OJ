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

/*=========================================
    æÿ’Û‘ÀÀ„
    ∏¥‘”∂»£∫O(N^3)
=========================================*/
const int maxn = 10;
const int maxm = 10;
struct Matrix
{
    int n, m;
    double a[maxn][maxm];
    void clear()
    {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator + (const Matrix &b) const
    {
        Matrix tmp;
        tmp.n = n;
        tmp.m = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp.a[i][j] = a[i][j] + b.a[i][j];
        return tmp;
    }
    Matrix operator - (const Matrix &b) const
    {
        Matrix tmp;
        tmp.n = n;
        tmp.m = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp.a[i][j] = a[i][j] - b.a[i][j];
        return tmp;
    }
    Matrix operator * (const Matrix &b) const
    {
        Matrix tmp;
        tmp.clear();
        tmp.n = n;
        tmp.m = b.m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    tmp.a[i][j] += a[i][k] * b.a[k][j];
        return tmp;
    }
};

Matrix x[12],ans;
int t,n;

int main ()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        ans.clear();
        ans.n=ans.m=3;
        for(int i=0; i<3; ++i)
        {
            ans.a[i][i]=1.0;
        }
        for(int i=0; i<n; ++i)
        {
            double tx,ty,tp;
            scanf("%lf%lf%lf",&tx,&ty,&tp);
            x[i].clear();
            x[i].n=x[i].m=3;
            x[i].a[0][0]=x[i].a[1][1]=cos(tp);
            x[i].a[0][1]=-sin(tp);
            x[i].a[1][0]=sin(tp);
            x[i].a[0][2]=tx;
            x[i].a[1][2]=ty;
            x[i].a[2][2]=1;
        }
        for(int i=0; i<n; ++i)
        {
            ans = x[i]*ans;
        }
        printf("%lf %lf %lf", ans.a[0][2],ans.a[1][2],acos(ans.a[0][0]));
    }
    return 0;
}
