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

const int MAXN = 10;

char a[MAXN];
int b[MAXN];
int n;
int k, len;

void init()
{
	scanf("%s", a);
	len = strlen(a);
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < len; i++)	n = n * 10 + a[i] - '0';
	while (n != 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (a[i] != '0')
			{
				b[k] = b[k] * 10 + 1;
				a[i] -= 1;
			}
			else b[k] = b[k] * 10;
		}
		n -= b[k];
		k++;
	}
	cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}