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

string str;
int n, m, l, r, ans;
int len, num;
char flag;

void init()
{
	cin >> n >> m;
	l = 0, r = n + 1, ans = 0;
	getchar();
	for (int i = 0; i < m; i++)
	{
		getline(cin, str);
		len = str.length() - 1;
		num = 0;
		flag = str[7];
		int tmp = len;
		while (str[tmp] != ' ')		tmp--;
		for (int j = 1; j + tmp <= len; tmp++)
		{
			num = num * 10 + str[tmp + j] - '0';
		}
		if (flag == 'l')
		{
			r = min(r, num);
			if (num < l || num == 1) ans = -1;
		}
		else
		{
			l = max(l, num);
			if (num > r || num == n)  ans = -1;
		}
		if (r < l || ans == -1)		break;
	}
}

int main(int argc, char const *argv[])
{
	init();
	if (ans == -1 || r - l == 1)
	{
		cout << "-1";
	}
	else
	{
		ans = r - l - 1;
		cout << ans;
	}
	return 0;
}