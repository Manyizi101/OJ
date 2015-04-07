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

const int MAXN = 10000+10;

int t,n,a[MAXN];
ll b,w;
int ans=0;

struct node
{
	int a;
	char v;
}brick[MAXN];

void init()
{
	b=w=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %c", &brick[i].a,&brick[i].v);
		if(brick[i].v=="B")	b+=brick[i].a;
		else w+=brick[i].a;
	}
}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}