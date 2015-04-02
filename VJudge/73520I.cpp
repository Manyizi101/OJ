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

const int MAXN = 256 + 10;

int n;
string a;
string b;
string hello="Hello,world!";
int len;

void init()
{
	getline(cin,a);
	len=a.length();
	for(int i=0;i<len;i++)
	{
		if(a[i]==' ')
		{
			a.erase(i,1);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		init();
		b="\0";
		len=a.length();
		for(int i=0;i<len;i++)
		{
			if(a[i]=='_')
			{
				b+=a;
			}
			else if(a[i]=='!')
			{
				b+=hello;
			}
		}
		if(!a.compare(b))
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}