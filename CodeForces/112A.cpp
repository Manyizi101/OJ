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

#define MAXN 100+10

char a[MAXN],b[MAXN];
int ans=0;

void cal(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='a')	a[i]-='a'-'A';
	}
}

void init()
{
	scanf("%s", a);
	cal(a);
	scanf("%s", b);
	cal(b);
}

int judge(char a[],char b[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>b[i])	return 1;
		else if(a[i]<b[i])	return -1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	init();
	cout<<judge(a,b);
	return 0;
}