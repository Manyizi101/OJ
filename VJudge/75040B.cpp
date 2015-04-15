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


int n;

void init()
{
	scanf("%d", &n);
}

int main(int argc, char const *argv[])
{
	init();
	cout<<n<<" ";
	for(int i=2;i<1000001;i++)
	{
		while(n%i==0)
		{
			n=(int)(n/i);
			cout<<n<<" ";
		}
	}
	return 0;
}