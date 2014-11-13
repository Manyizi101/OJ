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

#define MAXN 8

char chess[MAXN][MAXN];
int i,j;
int c=0,r=0;
int tmp=0;
int ans;

void init()
{
    for(int i=0; i<=7; i++)
            scanf("%s", &chess[i]);
}

int main(int argc, char const *argv[])
{
    init();
    for(int i=0; i<=7; i++)
    {
        tmp=0;
        for(j=0; j<=7; j++)
        {
            if(chess[i][j]=='B')
                tmp++;
        }
        if(tmp==MAXN)
        {
            c++;
        }
        else
            r=tmp;
    }
    ans=c+r;
    printf("%d\n", ans);
    return 0;
}
