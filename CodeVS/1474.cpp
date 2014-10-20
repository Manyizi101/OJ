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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 16

int n,m;

char num[MAXN]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char str[MAXN],ans[MAXN];

void init()
{
    memset(str,0,sizeof(str));
    memset(ans,0,sizeof(ans));
    scanf("%d%d", &n,&m);
}

void solve(int n,int m)
{
    int i=0,tmp=n;
    while(tmp/m!=0)
    {
        str[i++]=num[tmp%m];
        tmp=tmp/m;
    }
    str[i]=tmp%m+'0';
    int len = strlen(str);
    for(int j=0;j<len;j++)
    {
        ans[j]=str[len-j-1];
    }
    ans[len]='\0';
}

int main(int argc, char const *argv[])
{
	init();
	solve(n,m);
	printf("%s\n", ans);
	return 0;
}
