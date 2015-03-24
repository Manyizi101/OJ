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

#define MAXN 

int A,B,a,b,n;
const int mod = 5767169;
int x[100000000];

void init()
{
	memset(x,-1,sizeof(x));
	scanf("%d%d%d%d%d", &A,&B,&a,&b,&n);
}

int f(int n)
{
	if(x[n]>=0)	return x[n];
	if(n<0)	return 0;
	else if(n==0)	return 1;
	else 
		{
			return x[n]=(A*f(n-a)+B*f(n-b));
		}
}

int main(int argc, char const *argv[])
{
	init();
	cout<<f(n)%mod<<endl;
	return 0;
}

