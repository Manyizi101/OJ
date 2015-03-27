#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<vector>
using namespace std;

__int64 gcd(__int64 m, __int64 n)
{
	if (n == 0)return m;
	return gcd(n, m % n);
}
int main()
{
	__int64 a, b,c;
	scanf("%I64d%I64d", &a, &b, &c);
	printf("%I64d\n", gcd(a, b));
}
