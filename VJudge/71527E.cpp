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

int n;
int b[MAXN];
int flag=0;
struct node
{
	int val;
	int rank;
	int to;
}a[MAXN];

bool cmp(node a, node b)
{
	return a.val<b.val;
}

bool cmp2(node a, node b)
{
	return a.rank<b.rank;
}

void init()
{
	memset(b,0,sizeof(b));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i].val);
		a[i].rank=i;
		b[a[i].val]++;
	}
	sort(a,a+n,cmp);
}

bool judge(int b[])
{
	for(int i=2;i<=a[n-1].val;i++)
	{
		if(b[i]>b[i-1])	return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	init();
	if(judge(b))
	{
		for(int i=1;i<=a[n-1].val;i++)
		{
			for(int j=1;j<=b[i];j++)
			{
				a[flag].to=j;
				flag++;
			}
		}
		sort(a,a+n,cmp2);
		cout<<b[1]<<endl;
		for(int i=0;i<n;i++) cout<<a[i].to<<' ';
	}
	else
	{
		cout<<-1;
	}
	return 0;
}