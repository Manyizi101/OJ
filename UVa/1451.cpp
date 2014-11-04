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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 100000+10

int t,n,L;
char str[MAXN];
int sum[MAXN], qu[MAXN];
double ans;
int i;

double getK(int i, int j)
{
    return (sum[j]-sum[i])*1.0/(j-i);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d%s", &n, &L, str+1);
        memset(sum,0,sizeof(int)*(n+5));
        memset(qu,0,sizeof(int)*(n+5));
        for(i=1; i<=n; ++i)
            sum[i]=sum[i-1]+str[i]-'0';
        int len=L;
        ans=getK(0,L);
        int st=0,ed=L;
        int front=0,rear=-1;
        for(i=L; i<=n; ++i)
        {
            int temp=i-L;
            while(front<rear&&getK(qu[rear],temp)<=getK(qu[rear-1], qu[rear]))
                rear--;
            qu[++rear]=temp;
            while(front<rear&&getK(qu[front],i)<=getK(qu[front+1],i))
                front++;
            double t=getK(qu[front],i);
            if(t==ans&&len>i-qu[front])
            {
                len=i-qu[front];
                st=qu[front];
                ed=i;
            }
            else if(t>ans)
            {
                ans=t;
                len=i-qu[front];
                st=qu[front];
                ed=i;
            }
            cout<<debug<<getK(qu[front], i)<<endl;
        }
        printf("%d %d\n", st+1,ed);
    }
    return 0;
}
