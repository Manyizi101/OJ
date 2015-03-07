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

int n;
char a[MAXN];
int ans;

void init()
{
	scanf("%d", &n);
	scanf("%s", a);
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])	ans++;
	}
	cout<<ans;
	return 0;
}