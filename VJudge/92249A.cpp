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

const int maxn = 1000+10;

int n,B;
char a[maxn][1010];
int b[maxn];

int main()
{
    while(~scanf("%d%d", &n,&B))
    {
        int len=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%s", a[i]);
            char tmp[1010];
            int tlen = strlen(a[i]);
            for(int j=tlen-1; j>=0; --j)
            {
                tmp[tlen-j-1]=a[i][j];
            }
            for(int j=0; j<tlen; ++j)
            {
                a[i][j]=tmp[j];
            }
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
        }
        int flag=0;
        for(flag=len-1; flag>=0; --flag)
        {
            if(b[flag]%B!=0)   break;
        }
        if(b[flag]==0) printf("0");
        else
            for(; flag>=0; --flag)    printf("%d", b[flag]%B);
        printf("\n");
    }

}
