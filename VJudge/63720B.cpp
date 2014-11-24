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

#define MAXN 100+10

int n,m;
int price[MAXN];
string x[MAXN];
string y[MAXN];
int flag[MAXN];
int tmp;
int ansMin,ansMax;

struct node
{
    string s;
    int flag;
}str[MAXN];

bool cmp(node a, node b)
{
    return a.flag>b.flag;
}

void init()
{
    tmp=0;
    memset(flag,0,sizeof(flag));
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &price[i]);
    }
    sort(price, price+n);
    for(int i=0; i<m; i++)
    {
        cin>>x[i];
    }
    sort(x,x+m);
    y[tmp]=x[0];
    flag[0]=1;
    for(int i=1;i<m;i++)
    {
        if(x[i].compare(y[tmp])==0)
        {
            flag[tmp]++;
        }
        else
        {
            tmp++;
            y[tmp]=x[i];
            flag[tmp]=1;
        }
    }
    tmp++;
    for(int i=0;i<tmp;i++)
    {
        str[i].s=y[i];
        str[i].flag=flag[i];
    }
    sort(str,str+tmp,cmp);
}

int main(int argc, char const *argv[])
{
    init();
    for(int i=0;i<tmp;i++)
    {
        ansMin+=str[i].flag*price[i];
        ansMax+=str[i].flag*price[n-i-1];
    }
    printf("%d %d\n", ansMin, ansMax);
    return 0;
}
