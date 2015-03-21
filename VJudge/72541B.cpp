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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 100+10

string a[MAXN];
int n;
string str;

void init()
{
	cin >> str;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
}

int jduge()
{
	for (int i = 1; i <= n; i++)
	{
		if (str.compare(a[i].substr(0, str.length()))==0)
		{
			return i;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	init();
	int flag = jduge();
	//cout<<flag<<"fuck you"<<endl;
	if (flag)	cout << a[flag] << endl;
	else cout << str << endl;
	return 0;
}