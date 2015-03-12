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

#define MAXN 

string m[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

string a;
int n;
int x;

int main(int argc, char const *argv[])
{
	cin>>a;
	scanf("%d", &n);
	for(int i=0;i<12;i++)
	{
		if(m[i]==a)	
			{
				x=i;
				break;
			}
	}
	cout<<m[(x+n)%12];
	return 0;
}