/*
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double r1, r2;
    cin >> r1 >> r2;
    if (r1 > r2) swap(r1, r2);
    double ans, ans1, ans2;
    ans1 = 2 * r2 * r2 * r2 * ((r1 / r2 * asin(r1 / r2) + sqrt(1 - (r1 / r2) * (r1 / r2)) - 1));
    ans2 = 2.0 / 3 * (r2 * r2 * r2 - pow(r2 * r2 - r1 * r1, 1.5));
    ans = ans1 + ans2;
    printf("%.4f\n", 2 * ans);
    return 0;
}
**/
/*
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
#define inf (1<<28)
using namespace std;

float r1, r2;


int main(int argc, char const *argv[])
{
    freopen("twocyl.in", "r", stdin);
    freopen("twocyl.out", "w", stdout);
    cin >> r1 >> r2;
    if(r1>r2) swap(r1,r2);
    cout<<16.0/3*r1*r1*r2<<endl;
    return 0;
}
**/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<math.h>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define pi acos(-1)
#define eps 1e-8
typedef long long LL;
using namespace std;

double  R, r;

double f(double x)
{
    return 2*R*R*asin(x/R) + 2*x*sqrt(R*R-x*x);
}

double simpson(double a, double b)
{
    double c = a + (b - a) / 2;
    return (f(a) + 4 * f(c) + f(b)) * (b - a) / 6;
}

double asr(double a, double b, double epss, double A)
{
    double c = a + (b - a) / 2;
    double L = simpson(a, c) , R = simpson(c, b);
    if (fabs(L + R - A) <= 15 * epss) return L + R + (L + R - A) / 15;
    return asr(a, c, epss / 2, L) + asr(c, b, epss / 2, R);
}

double solve(double l, double r)
{
    return asr(l, r, eps, simpson(l, r));
}


int main()
{
    //freopen("twocyl.in", "r", stdin);
    //freopen("twocyl.out", "w", stdout);

    cin >> R >> r;

    if (R < r)
        swap(R, r);
    double ans = solve(0, r);
    double re = 3 * ans;
    printf("%.4f\n", re);

    return 0;
}