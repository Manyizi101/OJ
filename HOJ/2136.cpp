#include <stdio.h>
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

const int N = 1000010;
int prime[N];
int IsPrime[N];
int cnt = 0;

void init()
{
	int i, j ;
	for (i = 1 ; i <= 1000000 ; i++) IsPrime[i] = 1 ;
	for (i = 2 ; i <= 1000 ; i++)
		if (IsPrime[i])
		{
			for (j = i * i ; j <= 1000000 ; j += i)
				IsPrime[j] = 0 ;
		}
	for (i = 1 ; i <= 1000000 ; i++)
		if (IsPrime[i])
		{
			IsPrime[i] = cnt ;
			prime[cnt++] = i ;
		}
}

int calc(int n)
{
	int i, lim = sqrt(n) + 1, rtn = 0 ;
	for (i = 1 ; prime[i] <= lim && n != 1; i++)
	{
		while (n % prime[i] == 0)
		{
			n /= prime[i] ;
			rtn = i ;
		}
	}
	if (n == 1) return rtn ;
	return IsPrime[n] ;
}

int main(int argc, char const *argv[])
{
	int n;
	init();
	while (~scanf("%d", &n))
	{
		printf("%d\n", calc(n));
	}
	return 0;
}