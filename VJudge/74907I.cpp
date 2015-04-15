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

int a,b,c,d;

void init()
{
	cin>>a>>b>>c>>d;
}

double cal(int p, int t)
{
	return max(3*p/1.0/10,p-p/250.0*t);
}

int main(int argc, char const *argv[])
{
	init();
	if(cal(a,c)<cal(b,d))	cout<<"Vasya";
	else if(cal(a,c)==cal(b,d))	cout<<"Tie";
	else cout<<"Misha";
	return 0;
}