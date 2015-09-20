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

int cal(int arr[],int n)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(arr[i] > arr[j])
            {
                ++sum;
            }
        }
    }
    return sum;
}

const int maxn = 100;

int t,n,v[maxn];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)    scanf("%d", &v[i]);
        int cnt = cal(v,n);
        if(cnt==0)
        {
            printf("0\n");
        }
        else
        {
            if(n==2)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", 4*(2*cnt-1));
            }
        }
    }
}
