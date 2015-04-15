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

int a, b, n;
int l, t, m;

void init()
{
	scanf("%d%d%d", &l, &t, &m);
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &a, &b, &n);
	while (n--)
	{
		init();
		int r=(t-a)/b+1;
		if(t<a+(l-1)*b)
		{
			cout<<-1<<endl;
			continue;
		}
		int ans=max(r-l+1,m);
		cout<<l+ans-1<<endl;
	}
	return 0;
}