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

int n;

void init()
{
	scanf("%d", &n);
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)	cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)	cout << "*";
		cout << endl;
	}
	for (int i = 0; i < 2 * n - 1; i++)	cout << "*";
	cout << endl;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)	cout << " ";
		for (int j = 0; j < 2 * (n - i) - 1; j++)	cout << "*";
		cout << endl;
	}
	return 0;
}