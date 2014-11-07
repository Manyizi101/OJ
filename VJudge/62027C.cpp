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

int n,w,h;
int ans=0;
int a[MAXN];
int tmpw,tmph;

struct node
{
    int w,h,id;
}envelop[MAXN];

void init()
{
    scanf("%d%d%d", &n,&w,&h);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&envelop[i].w,&envelop[i].h);
        envelop[i].id=i;
    }
    tmpw=w,tmph=h;
}

bool cmp(node a, node b)
{
    if(a.w!=b.w)    return a.w<b.w;
    else return a.h<b.h;
}

int main(int argc, char const *argv[])
{
    init();
    sort(envelop,envelop+n,cmp);
    stack<int> que;
    for(int i=n-1;i>=0;i--)
    {
        ans=0;
    }
	return 0;
}
