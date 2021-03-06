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

#define MAXN 100+10

int n,a[MAXN];
int m,b[MAXN];
int j;

void init()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)	scanf("%d", &a[i]);
	j=0;
}

int main(int argc, char const *argv[])
{
	init();
	sort(a,a+n);
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]==b[j])	continue;
		else 
		{
			b[++j]=a[i];
		}
	}
	printf("%d\n", j+1);
	printf("%d", b[0]);
	for(int i=1;i<=j;i++)	printf(" %d",b[i]);
	return 0;
}