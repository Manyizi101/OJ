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

char data[110];
ll a,b;

bool judge(char x[])
{
    bool flag=false;
    ll ans=0;
    int len=strlen(x);
    if(len>=13||len==0) return false;
    else
    {
        if(x[0]=='-')   flag=true;
        else
        {
            if('0'<=x[0]&&x[0]<='9') ans=x[0]-'0';
            else return false;
        }
        for(int i=1; i<len; ++i)
        {
            if('0'<x[i]&&x[i]<='9') ans=ans*10+x[i]-'0';
            else if(x[i]=='0'&&ans!=0)  ans=ans*10;
            else return false;
        }
    }
    if(flag)    ans=ans*(ll)(-1);
    if(a>ans||b<ans)    return false;
    return true;
}

int main()
{
    while(gets(data))
    {
        scanf("%I64d%I64d", &a,&b);
        if(judge(data)) printf("YES\n");
        else printf("NO\n");
        getchar();
        memset(data,0,sizeof(data));
    }
}
