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

bool check(int n)
{
	int tmp = n;
	if(n==1)	return false;
	while (tmp != 1)
	{
		if (tmp % 2 == 0)	{tmp /= 2;}
		else if (tmp % 3 == 0)	{tmp /= 3;}
		else if (tmp % 5 == 0)	{tmp /= 5;}
		else return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	while (cin >> n)
	{
		check(n) ? cout << "True\n" : cout << "False\n";
	}
	return 0;
}