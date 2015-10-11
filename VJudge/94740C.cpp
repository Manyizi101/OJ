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

int n,ans;
int a[40][40],b[40][40];

int  cmp(int a[][40], int b[][40])
{
    int ans = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(a[i][j]==b[i][j]) {
                ans++;
            }
        }
    }
    return ans;
}

void rotate(int a[][40])
{
    int b[40][40];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            b[i][j]=a[j][n-i-1];
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            a[i][j]=b[i][j];
        }
    }
}

int main()
{
    while(~scanf("%d", &n)&&n) {
        ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        int Max = -1;
        for(int i=0; i<4; ++i) {
            /*
            for(int j=0;j<n;++j)
            {
                for(int x=0;x<n;++x)
                {
                    printf("%d ",a[j][x]);
                }
                cout<<endl;
            }
            **/
            Max = max(Max,cmp(a,b));
            rotate(a);
        }
        printf("%d\n", Max);
    }
}
