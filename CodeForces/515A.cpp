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
int a,b,s;

void init()
{
	scanf("%d%d%d", &a,&b,&s);
}

int main(int argc, char const *argv[])
{
	init();
	if(abs(a)+abs(b)>s)	cout<<"NO"<<endl;
	else if(abs(a)+abs(b)==s)	cout<<"YES"<<endl;
	else
	{
		if(abs(abs(a)+abs(b)-s)%2==0)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}