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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 100001+10

int t,n,a[MAXN],b[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        for(int i=0;i<n;i++)    scanf("%d", &a[i]);
        for(int i=0;i<n;i++)    scanf("%d", &b[i]);
    }
	return 0;
}
