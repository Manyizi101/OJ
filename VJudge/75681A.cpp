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

const int MAXN = 10005;
int n, ans = 0;

struct node
{
	int id, k;
} a[MAXN], m;

void cal(int i)
{
	a[i].k = -a[i].k;
	a[(i - 1 + n) % n].k += a[i].k;
	a[(i + 1) % n].k += a[i].k;
}

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n))
	{
		ans = 0;
		m.k = -40000;
		for (int i = 0; i < n; i++)
		{
			a[i].id = i;
			scanf("%d", &a[i].k);
			if (m.k < a[i].k && a[i].k < 0)
			{
				m.id = a[i].id;
				m.k = a[i].k;
			}
		}
		while (m.k < 0)
		{
			ans++;
			cal(m.id);
			if (a[(m.id - 1 + n) % n].k < 0 && a[(m.id + 1) % n].k >= 0)
			{
				m.id = (m.id - 1 + n) % n;
				m.k = a[(m.id - 1 + n) % n].k;
			}
			else if (a[(m.id - 1 + n) % n].k >= 0 && a[(m.id + 1) % n].k < 0)
			{
				m.id = (m.id + 1) % n;
				m.k = a[(m.id + 1) % n].k;
			}
			      else if (a[(m.id - 1 + n) % n].k < 0 && a[(m.id + 1) % n].k < 0)
			{
				if (a[(m.id - 1 + n) % n].k > a[(m.id + 1) % n].k)
				{
					m.id = (m.id - 1 + n) % n;
					m.k = a[(m.id - 1 + n) % n].k;
				}
				else
				{
					m.id = (m.id + 1) % n;
					m.k = a[(m.id + 1) % n].k;
				}
			}
			else	break;
		}
		cout << ans << endl;
	}
	return 0;
}