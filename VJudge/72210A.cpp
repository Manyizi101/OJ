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

#define MAXN 100000+10

char a[MAXN];
int n;
ll b[MAXN];
int flag=0;

void init()
{
	memset(b,0,sizeof(b));
	scanf("%s", a);
	n = strlen(a);
	sort(a,a+n);
	b[0]=1;
	flag=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])
		{
			b[++flag]=1;
		}
		else
		{
			b[flag]++;
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	ll ans = 0;
	for(int i=0;i<=flag;i++)
	{
		ans+=b[i]*b[i];
	}
	cout << ans;
	return 0;
}
