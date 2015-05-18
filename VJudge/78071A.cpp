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
const int inf = 1 << 31;
using namespace std;

double a[6];
double b[3];
double ans;

void init()
{
	ans = 1;
	for (int i = 0; i < 6; i++)
	{
		scanf("%lf", &a[i]);
	}
}

int main(int argc, char const *argv[])
{
	init();
	if (a[0]*a[2]*a[4] < a[1]*a[3]*a[5])	ans = 2;
	if (a[4] == 0 && a[5] > 0 && a[1] > 0 && a[3] > 0)	ans = 2;
	if (a[0] == 0 && a[1] > 0 && a[3] > 0)	ans = 2;
	if (a[2] == 0 && a[3] != 0)	ans = 2;
	ans > 1 ? puts("Ron") : puts("Hermione");
	return 0;
}