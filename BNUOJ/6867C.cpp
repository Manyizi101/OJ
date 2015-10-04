#include <cstdio>
#include <iostream>
#include <cstring>
#include<vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
const int N = 100005;
double a[N],sum;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        sum  =0;
        for(int i = 0;  i< n ; i++)
        {
            scanf("%lf",&a[i]);
            sum += a[i];
        }
        double ave = sum/n;
        int ans = 0;
        for(int i = 0 ; i < n ;i++)
        {
            if(ave < a[i]) ans ++ ;
        }
        printf("%d\n",ans);
    }
    return 0;
}
