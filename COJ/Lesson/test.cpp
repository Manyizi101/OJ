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

int t;
int n;
int tmp;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
	{
		n=0;
		while(scanf("%1d", &tmp))
		{
			n+=tmp;
		}
		n%3==0?puts("YES"):puts("NO");
	}
	return 0;
}
