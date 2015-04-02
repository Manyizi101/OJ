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

const int MAXN = 20 + 10;

string a, b;
int ans = 0;
int xa[MAXN], xb[MAXN];

void init()
{
	memset(xa,0,sizeof(xa));
	memset(xb,0,sizeof(xb));
	ans=0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i += 2)
	{
		if (a[i] == '[')	xa[i / 2] = 2;
		else if (a[i] == '(')	xa[i / 2] = 1;
		else if (a[i] == '8')	xa[i / 2] = 3;

		if (b[i] == '[')	xb[i / 2] = 2;
		else if (b[i] == '(')	xb[i / 2] = 1;
		else if (b[i] == '8')	xb[i / 2] = 3;
	}
}

int  win(int a, int b)
{
	if (a == b)	return 0;
	else if (a == 1 && b == 2)	return -1;
	else if (a == 1 && b == 3)	return 1;
	else if (a == 2 && b == 1)	return 1;
	else if (a == 2 && b == 3)	return -1;
	else if (a == 3 && b == 1)	return -1;
	else if (a == 3 && b == 2)	return 1;

}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < a.length(); i+=2)
	{
		ans += win(xa[i/2], xb[i/2]);
	}
	if (ans > 0)	cout << "TEAM 1 WINS";
	else if (ans == 0)	cout << "TIE";
	else cout << "TEAM 2 WINS";
	return 0;
}