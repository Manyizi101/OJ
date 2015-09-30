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

const int MAXN = 1000000;

int n;
char s[MAXN];

int main()
{
    while(~scanf("%s",s))
    {
        n=strlen(s);
        if (n%3!=0||n<3) cout<<"NO"<<endl;
        else
        {
            int t=n/3;
            if (s[0]==s[t]||s[t]==s[2*t]||s[0]==s[2*t]) cout<<"NO"<<endl;
            else
            {
                bool flag=0;
                for(int i=1; i<=n; ++i)
                {
                    if ((s[i]!=s[i-1]&&i%t!=0))
                    {
                        flag=1;
                        break;
                    }
                }
                if (flag) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
