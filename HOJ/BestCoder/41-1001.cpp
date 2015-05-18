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

int t;
int ans = -1, ansb = -1;;
struct node
{
	char a;
	int b;
} card[MAXN], cardb[MAXN];

bool cmp(node a, node b)
{
	if (a.a == b.a)	return a.b < b.b;
	return a.a < b.a;
}

void init()
{
	ans = -1;
	ansb = -1;
	memset(card, 0, sizeof(card));
	for (int i = 0; i < 5; i++)
	{
		getchar();
		scanf("%c%d", &card[i].a, &card[i].b);
		cardb[i].a = card[i].a;
		cardb[i].b = card[i].b;
		if (cardb[i].b == 1)	cardb[i].b += 13;
	}
	sort(card, card + 5, cmp);
	sort(cardb, cardb + 5, cmp);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		int tmp = 1;
		for (int i = 1; i < 5; i++)
		{
			if (card[i].a == card[i - 1].a && card[i].b == card[i - 1].b + 1)	tmp++;
			else	tmp = 1;
			ans = max(tmp, ans);
		}
		tmp = 1;
		for (int i = 1; i < 5; i++)
		{
			if (cardb[i].a == cardb[i - 1].a && cardb[i].b == cardb[i - 1].b + 1)	tmp++;
			else	tmp = 1;
			ansb = max(tmp, ansb);
		}
		ans = max(ansb, ans);
		cout << 5 - ans << endl;
	}
	return 0;

}