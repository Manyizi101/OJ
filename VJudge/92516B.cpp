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

    const int maxn = 200000+10;

    int n,w,H;
    int sum;
    int h[maxn];

    int main()
    {
        while(~scanf("%d%d%d", &n,&w,&H))
        {
            memset(h,0,sizeof(h));
            sum=0;
            for(int i=w; i<w+n; ++i)
            {
                scanf("%d", &h[i]);
                sum+=h[i];
            }
            if(sum<w*H)
            {
                puts("-1");
                continue;
            }
            int ans = inf;
            int high=0,low=0;
            for(int i=0; i<w; ++i)
            {
                if(h[i]>H)  high+=h[i]-H;
                else low+=H-h[i];
            }
            ans = max(high,low);
            for(int i=w; i<n+2*w; ++i)
            {
                if(h[i-w]>H)    high-=h[i-w]-H;
                else low-=H-h[i-w];
                if(h[i]>H)  high+=h[i]-H;
                else low+=H-h[i];
                ans =min(ans, max(high,low));
            }
            printf("%d\n", ans);
        }
    }
