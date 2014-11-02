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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 1000010

int t,n,a;
int arr[MAXN];
int pos[MAXN];
int cnt,start,maxx;

void init()
{
    memset(pos, -1, sizeof(pos));
    scanf("%d", &n);
    cnt=0,start=0,maxx=0;
    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]);
    arr[n] = arr[n-1];
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        for(int i=0; i<=n; ++i)
        {
            if(pos[arr[i]] >= start)
            {
                int tmp = i - start;
                maxx = max(tmp, maxx);
                start = pos[arr[i]]+1;
                pos[arr[i]] = i;
            }
            else
            {
                pos[arr[i]] = i;
            }

        }
        printf("%d\n", maxx);
    }
    return 0;
}
