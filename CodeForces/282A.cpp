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

#define MAXN 4

int n;
string a;
int x=0;

void judge(string a)
{
	if(a=="++X"||a=="X++")	x++;
	else if(a=="--X"||a=="X--")	x--;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	while(n--)
	{
		cin>>a;
		judge(a);
	}
	cout<<x;
	return 0;
}
