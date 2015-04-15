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

const int MAXN = 1000 + 10;

int n;
int ans;
map<string, string> people;
map<string, string>::iterator it;

void init()
{
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		people[s2] = s1;
		if (people.count(s1) != 0)
		{
			ans++;
			people[s2] = people[s1];
			people.erase(s1);
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	cout << n - ans << endl;
	for (it = people.begin(); it != people.end(); it++)
	{
		cout << ((*it).second) << " " << ((*it).first) << endl;
	}
	return 0;
}