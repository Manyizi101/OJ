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

int n, k;
char p[MAXN], str[MAXN];
char  ans[MAXN];
int lenp, lenstr;

void init()
{
	memset(ans, 0, sizeof(ans));
	scanf("%d%d", &n, &k);
	cin >> p >> str;
	lenp = strlen(p);
	lenstr = strlen(str);
}

bool judge(char ans[], char p[], int flag)
{
	for (int i = 0; i < lenp; i++)
	{
		if (ans[i + flag] == '\0'||0)	return true;
		if (ans[i + flag] == p[i])	continue;
		else return false;
	}
}

int main(int argc, char const *argv[])
{
	init();

	for (int i = 0; i < lenstr; i++)
	{
		if (str[i] == '1')
		{
			if (judge(ans, p, i))
			{
				strcpy(ans + i, p);
			}
			else
			{
				cout << "No solution";
				return 0;
			}
		}
		else
		{
			int cnt = strlen(ans);
			ans[cnt] = 'a' + k - 1;
			ans[cnt + 1] = '\0';
		}
		if (strlen(ans) > n)
		{
			cout << "No solution";
			return 0;
		}
	}
	cout << ans;
	return 0;
}