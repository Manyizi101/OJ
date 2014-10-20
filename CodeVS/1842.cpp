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

#define MAXN 10000

int x;
int n[MAXN];

int f(int x)
{
    if(n[x+30]!=0) return n[x+30];
    if(x>=0)    return n[x+30]=5;
    else
    {
        return n[x+30]=f(x+1)+f(x+2)+1;
    }
}

int main(int argc, char const *argv[])
{
	memset(n,0,sizeof(n));
	scanf("%d", &x);
	printf("%d\n", f(x));
	return 0;
}
