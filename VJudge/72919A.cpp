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
const int inf = 1<<30;
using namespace std;

const int MAXN = 365+10;
int n,k,c;
int hoilday[MAXN];
int ans=0;
int x[MAXN];
int flag=0;

void init()
{
	memset(x,0,sizeof(x));
	scanf("%d%d%d", &n,&k,&c);
	for(int i=0;i<c;i++)
	{
		scanf("%d", &hoilday[i]);
		x[hoilday[i]]=1;
	}
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1)
		{
			flag=0;
		}
		else
		{
			flag++;
			if(flag==k)
			{
				flag=0;
				x[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}