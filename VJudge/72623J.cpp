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
#define LOCAL
using namespace std;


ll t;
ll n;
string a[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
ll ans[50] = {0, 1, 4, 6, 4, 3, 1, 0, 1, 1, 4, 2, 1, 6, 0, 1, 2, 5, 1, 5, 1, 0, 1, 4, 1, 4, 4, 6, 0, 1, 1, 3, 2, 6, 1, 0, 1, 2, 2, 1, 2, 6, 0};



int main(int argc, char const *argv[])
{
	freopen("72623J.out", "w", stdout);

	//scanf("%d", &t);
	//while (t--)
	{
		for (n = 1; n < 100; n++)
		{
			ll cnt = n % 42;
			ll tmp = 0;
			for (ll i = 1; i <= cnt; i++)
			{
				tmp += ans[i];
			}
			cout << n << ":" << a[tmp % 7] << endl;
		}
	}
	return 0;
}