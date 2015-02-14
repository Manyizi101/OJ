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

int t;
ll n;
ll s;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &s);
		ll sum=n*(n+1)/2;
		ll i=0,ans=sum-s;
		while(ans>i)
		{
			ans-=i;
			i++;
		}
		cout<<i<<endl;
	}
	return 0;
}