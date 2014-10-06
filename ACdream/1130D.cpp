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
//#define LOCAL
using namespace std;

int n,flag,ans;
char x[16];

void init()
{
	scanf("%d", &n);
	flag=(int)pow(2,n);
	ans=0;
}

int main(int argc, char const *argv[])
{
	#ifdef LOCAL
	freopen("monotone.in","r",stdin);
	freopen("monotone.out","w",stdout);
	#endif
	init();
	bitset<17> tmp;
	while(flag--)
	{
		tmp=ans;
		ans++;
		for(int i=0;i<n;i++)	x[i]=tmp.to_string()[16-i];
		printf("%s\n", x);
	}
	return 0;
}