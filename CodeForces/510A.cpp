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

#define MAXN 50+10

int m,n;
char a[MAXN][MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n,&m);
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			if(i%4==2)
			{
				for(int j=1;j<m;j++)
					a[i][j]='.';
				a[i][m]='#';
			}
			else
			{
				for(int j=2;j<=m;j++)
					a[i][j]='.';
				a[i][1]='#';
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]='#';
			}
		}
		cout<<a[i]+1<<endl;
	}
	return 0;
}