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

const int MAXN = 300000 + 10;
const int MAX = MAXN * 2;
int n, m, len,ans;
int vis[MAXN];
struct  node
{
	int rank;
	int val;
} num[MAXN];

void init()
{
	ans=-1;
	memset(vis,0,sizeof(vis));
	memset(num,-1,sizeof(num));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &num[i].rank, &num[i].val);
	}
}

int dfs(int i)
{
	if(num[i].val==-1&&!vis[num[i].rank])	return len;
	else
	{
		len++;
		vis[num[i].rank]=1;
		dfs(num[i].val);
	}
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &n, &m))
	{
		init();
		for(int i=0;i<n;i++)
		{
			len=1;
			ans=max(ans,dfs(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}