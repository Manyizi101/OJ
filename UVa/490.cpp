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

char a[MAXN][MAXN];
int i=0;
int Max=0,tmp=0;;

int main(int argc, char const *argv[])
{
    memset(a,0,sizeof(a));
    while(gets(a[i++]))
    {
        tmp=strlen(a[i-1]);
        if(Max<tmp) Max=tmp;
    }
    for(int j=0; j<Max; j++)
    {
        for(int k=i-1; k>=0; k--)
        {
            if(!a[k][j])    a[k][j]=' ';
        }
    }
    for(int j=0; j<Max; j++)
    {
        for(int k=i-2; k>=0; k--)
        {
            printf("%c", a[k][j]);
        }
        printf("\n");
    }
    return 0;
}
