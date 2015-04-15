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

const int MAXN = 12;

char a[MAXN];
int ans=0;

int main(int argc, char const *argv[])
{
	scanf("%s", a);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]=='7')	ans=ans*2+2;
		else ans=ans*2+1;
	}
	cout<<ans;
	return 0;
}