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
int n;
struct node
{
	int id;
	string name;
	string kind;
	int rank;
} p[MAXN];

bool cmp(node a, node b)
{
	if (a.rank < b.rank)	return true;
	else return false;
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].name >> p[i].kind;
		p[i].id=i;
		if (p[i].kind == "captain")	p[i].rank = 3;
		else if (p[i].kind == "man")	p[i].rank = 2;
		else if (p[i].kind == "rat")	p[i].rank = 0;
		else p[i].rank = 1;
	}
	stable_sort(p, p + n,cmp);
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		cout << p[i].name << endl;
	}
	return 0;
}