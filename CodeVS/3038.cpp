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

int t,n;

int func(int n)
{
    int step=0;
    while(n!=1)
    {
        if(n%2==0)  n=n/2;
        else    n=3*n+1;
        step++;
    }
    return step;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", func(n));
    }

}
