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
const int inf = 1 << 31;
using namespace std;

const int MAXN = 1010;

int n;
int ans[MAXN];

void init()
{
	memset(ans,0,sizeof(ans));
	for(int i=0;i<10;i++)
	{
		ans[2<<i]=1;
	}
	scanf("%d", &n);
}

int main(int argc, char const *argv[])
{
	init();
	if(ans[n]||n==1)	cout<<"YES";
	else cout<<"NO";
	return 0;
}