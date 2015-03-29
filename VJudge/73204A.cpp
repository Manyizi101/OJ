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

const int MAXN = 30;

string a[MAXN]= {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","0"};
int ans=0;
int n;
string x;

bool check(string x)
{
	for(int i=0;i<29;i++)
	{
		if(!x.compare(a[i])) return true;
	}
	return false;
}

void init()
{
	scanf("%d", &n);
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(check(x))	ans++;
	}
	cout<<ans;
	return 0;
}