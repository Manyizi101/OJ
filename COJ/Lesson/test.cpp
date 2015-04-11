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

const int MAXN = 100;
ll a[MAXN],n;

ll f(int n)
{
	if(a[n]!=-1)	return a[n];
	if(n==0||n==1)	return a[n]=1;
	else return a[n]=f(n-1)+f(n-2);
}

int main(int argc, char const *argv[])
{
	memset(a,-1,sizeof(a));
	while(~scanf("%lld",&n))
	{
		cout<<f(n)<<endl;
	}
	return 0;
}