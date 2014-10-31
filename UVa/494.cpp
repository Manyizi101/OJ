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

#define MAXN 1<<10

string a;
int ans=0,is=0;

int main(int argc, char const *argv[])
{
	while(getline(cin, a))
    {
        ans=0;is=0;
        for(int i=0;i<=a.length();i++)
        {
            if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z'))
            {
                is=1;
            }
            else
            {
                ans+=is;
                is=0;
            }
        }
        printf("%d\n", ans+is);
    }
	return 0;
}
