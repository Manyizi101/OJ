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

#define MAXN 20000+10

int t, n, l;
int ans = 0;
int x[MAXN];
int flag;
int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		x[ans++] = ti[0].rank;
		for (int i = 1; i < n; i++)
		{
			if (cal(ti[i], ti[flag]) < l)
			{
				continue;
			}
			else
			{
				flag = i;
				x[ans++] = ti[flag].rank;
			}
		}
		sort(x, x + ans);
		cout << ans << endl;
		for (int i = 0; i < ans - 1; i++)
		{
			cout << x[i] << " ";
		}
		cout << x[ans - 1];
		cout << endl;
	}
	return 0;
}