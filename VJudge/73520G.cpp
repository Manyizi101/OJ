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

const int MAXN = 100 + 10;
int t;
int n;
int a[MAXN][MAXN];


int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (j & 1||i&1)
				{
					a[j][i] = 1;
					a[j][i] = 0;
				}
				else
				{
					a[j][i] = 0;
					a[j][i] = 1;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[j][i])	cout << 'X';
				else cout << 'O';
			}
			cout << endl;
		}
	}
	return 0;
}