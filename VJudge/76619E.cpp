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

int al, ar, bl, br;

void init()
{
	scanf("%d%d%d%d", &al, &ar, &bl, &br);
}

bool judge(int g, int b)
{
	if (b < g - 1)    return false;
	else if (b > 2 * g + 2) 	return false;
	else return true;
}

int main(int argc, char const *argv[])
{
	init();
	if (judge(al, br) || judge(ar, bl))    cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}