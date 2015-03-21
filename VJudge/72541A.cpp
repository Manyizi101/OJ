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

#define MAXN 100000+10

int n;
int a;
int a1,a2,a3;

void init()
{
	a1=a2=a3=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a);
		if(a==1)	a1++;
		else if(a==2)	a2++;
		else a3++;
	}
}

int main(int argc, char const *argv[])
{
	init();
	cout<<a1+a2+a3-max(a1,max(a2,a3))<<endl;
	return 0;
}