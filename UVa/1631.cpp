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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 1000+10

char a[MAXN],b[MAXN];
int path[MAXN],len;
int ans;

int main(int argc, char const *argv[])
{
	while(~scanf("%s%s", a,b))
    {
        len=strlen(a);
        for(int i=0;i<len;i++)
        {
            path[i]=b[i]-a[i];
        }
        for(int i=0;i<len;i++)
        cout<<path[i]<<endl;
    }
	return 0;
}
