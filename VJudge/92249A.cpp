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

int n,B;
char a[maxn][210];
int b[210];

int main()
{
    while(~scanf("%d%d", &n,&B))
    {
        memset(a,0,sizeof(a));
        int len=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%s", a[i]);
            int tlen = strlen(a[i]);
            for(int j=0; j<=(tlen-1)/2; ++j)
                swap(a[i][j],a[i][tlen-j-1]);
            len=max(len,(int)strlen(a[i]));
        }
        memset(b,0,sizeof(b));
        for(int i=0; i<len; ++i)
        {
            b[i]=0;
            for(int j=0; j<n; ++j)
            {
                if(i>=(int)strlen(a[j]))  continue;
                if(a[j][i]>='0'&&a[j][i]<='9')
                {
                    b[i]+=a[j][i]-'0';
                }
                else if(a[j][i]>='a'&&a[j][i]<='z')
                {
                    b[i]+=a[j][i]-'a'+10;
                }
            }
            b[i]%=B;
        }
        int flag=len-1;
        for(flag=len-1; flag>=0; --flag)
        {
            if(b[flag]!=0)   break;
        }
        if(b[flag]==0) printf("0");
        else
            for(; flag>=0; --flag)
            {
                if(b[flag]<=9&&b[flag]>=0)
                    printf("%d", b[flag]);
                else
                    printf("%c",b[flag]-10+'a');
            }
        printf("\n");
    }

}
