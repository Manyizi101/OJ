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
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----\n")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

#define MAXN 18+10

int n,flag=0;
int a[MAXN];
long long int ans;
long long int tmp;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
        }
        ans=a[0];
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=i;j--)
            {
                tmp=1;
                for(int x=i;x<=j;x++)
                {
                    tmp*=a[x];
                }
                if(ans<tmp) ans=tmp;
            }
        }
        if(ans<0)   ans=0;
        printf("Case #%d: The maximum product is %lld.\n\n", ++flag, ans);
    }

}

/*
3
2 4 -3

5
2 5 -1 2 -1

**/
