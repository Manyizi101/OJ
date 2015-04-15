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

int main(int argc, char const *argv[])
{
	ll r, x1, y1, x2, y2, a, b;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	a = x1 - x2;
	b = y2 - y1;
	double d = sqrt(a * a + b * b);
	r *= 2;
	d==0 ? cout << 0 : cout << ceil(d / r);
	return 0;
}