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
char x[17];
char y[17];

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
	bitset<17> tmp1;
	bitset<17> tmp2;
	bitset<17> tmp3;
	while(flag--)
	{
		tmp1=ans;
		tmp2=(ans&1)>>1;
		tmp3=tmp1^tmp2;
		ans++;
		for(int i=0;i<n;i++)	x[i]=tmp3.to_string()[16-i];
			for(int i=0;i<n;i++)	y[i]=x[n-i-1];
		printf("%s\n", y);
	}
	return 0;
}