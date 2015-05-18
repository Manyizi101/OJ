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

const int MAXN = 6;
int t, ans, cnt;
int a[MAXN], b[MAXN], is[15];


void init()
{
	ans = -1;
	char hua;
	int shu;
	for (int i = 1; i <= 5; i++)
	{
		getchar();
		scanf("%c%d", &hua, &shu);
		a[i] = hua - 'A' + 1;
		b[i] = shu;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		for (int i = 1; i < 5; i++)
		{
			memset(is, 0, sizeof(is));
			for (int j = 1; j <= 5; j++)
			{
				if (a[j] == i)
				{
					is[b[j]] = 1;
					if (b[j] == 1)	is[14] = 1;
				}
			}
			//for (int i = 0; i < 15; i++)	cout << is[i] << " ";
			//cout << endl;
			int cnt;
			for (int j = 1; j <= 10; j++)
			{
				/*
				if (is[j])	cnt++;
				else cnt = 0;
				**/
				cnt = 0;
				for (int k = 0; k < 5; k++)
				{
					cnt += is[j + k];
				}
				ans = max(cnt, ans);
			}
		}
		cout << 5 - ans << endl;
	}
	return 0;
}