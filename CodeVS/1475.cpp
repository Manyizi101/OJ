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

#define MAXN 16

int n,m;
char num[MAXN]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char str[MAXN];

void init()
{
    memset(str,0,sizeof(str));
    scanf("%s%d", str,&m);
    n=0;
}

void solve(char str[],int m)
{
    int i=0,len=strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i]<='9')
            n+=(str[i]-'0')*pow(m,len-i-1);
        else
            n+=(str[i]-'A'+10)*pow(m,len-i-1);
    }
}

int main(int argc, char const *argv[])
{
    init();
    solve(str,m);
    printf("%d\n", n);
    return 0;
}
