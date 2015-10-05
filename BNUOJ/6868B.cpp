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


int n, i, j, k;
char c;

char intTochar(int x)
{
    if(x>26)  return x-27+'A';
    return x-1+'a';
}

int main(int argc, char const *argv[])
{

    while(~scanf("%d",&n))s
    {
        printf("2 %d %d\n",n,n);
        for(i=1; i<=n; i++)
        {
            c=intTochar(i);
            for(j=1; j<=n; j++)
            {
                printf("%c",c);
            }
            printf("\n");
        }
        printf("\n");
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                c=intTochar(j);
                printf("%c",c);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
