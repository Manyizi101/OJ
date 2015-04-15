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
const int inf = 1<<31;
using namespace std;

double p,ans;

void init()
{
	scanf("%lf", &p);
}

int main(int argc, char const *argv[])
{
	init();
	ans=0;
	for(int i=39;i<1000000;i+=2)
	{
		ans+=i*pow(p,i)*pow(1-p,(i-39)/2);
	}
	printf("%.5f", ans);
	return 0;
}