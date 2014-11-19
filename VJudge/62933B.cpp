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

char n[10];
ll a[10],len;
ll ans=0;

int main(int argc, char const *argv[])
{
	scanf("%s", n);
	len=strlen(n);
	for(int i=0;i<len;i++)
    {
        a[i]=n[i]-'0';
    }
    for(int i=0;i<len;i++)
    {
        if(a[i]>1)
        {
            for(int j=i;j<len;j++)
            {
                a[j]=1;
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        ans+=a[len-i-1]*(ll)pow(2,i);
    }
    printf("%I64d\n", ans);
	return 0;
}
