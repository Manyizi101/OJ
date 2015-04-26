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

const int MAXN = 100 + 10;
char a[MAXN], b[MAXN], c[MAXN];

void init()
{
	scanf("%s%s", a, b);
}

int main(int argc, char const *argv[])
{
	init();
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if ((a[i] - '0') ^ (b[i] - '0'))	c[i] = '1';
		else c[i] = '0';
	}
	c[len] = '\0';
	cout << c;
	return 0;
}