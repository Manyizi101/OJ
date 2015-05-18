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

int t, n, odd, even, tmp;
map<string, int> mp;


void init()
{
	string s;
	mp.clear();
	tmp = odd = even = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		mp[s]++;
		if (s.length() & 1)	odd++;
		else even++;
	}
}

int gcd(int a , int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		map<string, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
		{
			int v = (*it).second;
			if (v > 1) tmp += v * (v - 1) / 2;
		}
		int up = odd * even + tmp;
		int down = n * (n - 1) / 2;
		up == 0 ? cout << "0/1\n" : cout << up / gcd(up, down) << "/" << down / gcd(up, down) << endl;
	}
	return 0;
}