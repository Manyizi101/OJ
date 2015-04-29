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

string ini[3], ans;
int n;

string down(string s)
{
	string str;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'Z') str += s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z') str += s[i] - 'A' + 'a';
	}
	return str;
}

void init()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> ini[i];
		ini[i] = down(ini[i]);
	}
	cin >> n;
}

bool equal(string k)
{
	do
	{
		if (k != ini[0] + ini[1] + ini[2])	return false;
		cout<<ini[0]<<' '<<ini[1]<<' '<<ini[2]<<endl;
	} while(next_permutation(ini, ini + 2));
	return true;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		string k;
		cin >> k;
		k = down(k);
		equal(k) ? puts("ACC") : puts("WA");
	}
	return 0;
}