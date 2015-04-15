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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1<<31;
using namespace std;

const int MAXN = 2*100000+10;

int ans[MAXN];
int n,flag=0;

struct node 
{
	int s,r;
	int rank;
}c[MAXN];

bool cmp1(node a, node b)
{
	if(a.s==b.s)	return a.r>b.r;
	else return a.s>b.s;
}

bool cmp2(int a, int b)
{
	return c[a].rank<c[b].rank;
}

void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d", &c[i].s,&c[i].r);
		c[i].rank=i+1;
	}
	sort(c,c+n,cmp1);
}

int main(int argc, char const *argv[])
{
	init();
	ans[flag++]=0;
	int st=c[0].s,rt=c[0].r;
	for(int i=1;i<n;i++)
	{
		if(c[i].s<=st&&c[i].r>=rt)
		{
			ans[flag++]=i;
			rt=c[i].r;
		}
	}
	sort(ans,ans+flag,cmp2);
	for(int i=0;i<flag;i++)
	{
		cout<<c[ans[i]].rank<<" ";
	}
	return 0;
}