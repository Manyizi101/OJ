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

const int MAXN = 100+10;

char a[MAXN];
char b[]="CODEFORCES";
int len=0;
int ans=0;

void init()
{
	scanf("%s", a);
	len=strlen(a);
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=0;i<len;i++)
	{
		if(a[i]==b[i])	ans++;
		else break;
	}
	for(int i=len-1;i>=0;i--)
	{
		if(a[i]==b[i-len+10])	ans++;
	}
	ans>=10?puts("YES"):puts("NO");
	return 0;
}