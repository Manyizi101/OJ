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

const int maxn = 100+10;

int t,n;
char a[maxn][maxn];
char brush[3]= {'Y','G','B'};

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d", &n);
        if(n>5)
        {
            for(int i=0; i<n; ++i)
            {
                a[i][n-1]='R';
                a[i][n]='\0';
            }
            int cnt=0;
            for(int i=0; i<n/2+1; ++i)
            {
                for(int j=0; j<n-1; ++j)
                {
                    a[i][j]=brush[(cnt/n)%3];
                    cnt++;
                }
            }
            int k=1;
            for(int i=n/2+1; i<n; ++i)
            {
                k=!k;
                for(int j=0; j<n-1; ++j)
                {
                    if(k)
                        a[i][j]=brush[(cnt/n)%3];
                    else
                        a[i][n-2-j]=brush[(cnt/n)%3];
                    cnt++;
                }
            }
            swap(a[0][n-2],a[2][0]);
            for(int i=0; i<n; ++i)
            {
                for(int j=0; j<n; ++j)    cout<<a[i][j];
                cout<<endl;
            }
        }
        else if(n==1)
        {
            puts("Y");
        }
        else if(n==5)
        {
            puts("YYYGR");
            puts("YGGGR");
            puts("YGYYR");
            puts("BYYYR");
            puts("BBBBR");
        }
        else
        {
            puts("No solution!");
        }
    }
}
