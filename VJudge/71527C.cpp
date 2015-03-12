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

#define MAXN 10000

int n;
int a[MAXN];

void init()
{
	scanf("%d", &n);
	for(int i=1;i<100;i++)
	{
		a[i]=i*(i+1)/2;
	}
}

bool judge(int n)
{
	for(int i=1;i<100;i++)
	{
		if(a[i]==n)	return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	init();
	if(judge(n))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}