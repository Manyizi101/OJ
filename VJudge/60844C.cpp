#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <cctype>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

#define LL long long int
#define MAXN 10000+10

LL xbuf[MAXN];
LL ybuf[MAXN];

int main()
{
    LL k;
    while(~scanf("%lld",&k))
    {
        LL y = 1;
        LL cnt = 0;

        memset(xbuf, 0, sizeof(xbuf));
        memset(ybuf, 0, sizeof(ybuf));

        for(y=1; y<=2*k; y++)
        {
            double x = 1.0 / (1.0/k - 1.0/y);
            LL xInt = (LL)(x+0.5);

            if(x>0 && fabs(x-xInt)<1e-4)
            {
                xbuf[cnt] = xInt;
                ybuf[cnt] = y;
                cnt++;
            }
        }
        printf("%lld\n", cnt);
        for(int i=0; i<cnt; i++)
        {
            printf("1/%lld = 1/%lld + 1/%lld\n", k, xbuf[i], ybuf[i]);
        }
    }
}
