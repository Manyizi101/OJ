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

int n;
string a[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	if (n > 5)
	{
		int x = ceil(log2(double(n) / 5.0));
		int y = n - 5 * (int)pow(2, x - 1);
		int tmp1 = y / (int)pow(2, x);
		int tmp2 = y % (int)pow(2, x);
		if (tmp2 == 0)
			cout << a[tmp1 - 1];
		else
			cout << a[tmp1];
	}
	else
	{
		cout << a[n - 1];
	}
	return 0;
}