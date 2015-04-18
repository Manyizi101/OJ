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

const int MAXA = 101;

int n, m, sum = 0, a;

void init()
{
	a = MAXA;
	cin >> n;
	while (n--)
	{
		cin >> m;
		sum += m;
		if (m & 1 && m < a) a = m;
	}
}

int main(int argc, char const *argv[])
{
	init();
	if (sum & 1)
	{
		cout << sum << endl;
	}
	else
	{
		if (a == MAXA)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << sum - a << endl;
		}
	}
	return 0;
}