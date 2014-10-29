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

int main(int argc, char const *argv[])
{
    int n;
    while(~scanf("%d", &n))
    {
        int k=(int)floor((sqrt(8.0*n+1)-1)/2-(1e-9))+1;
        int s=k*(k+1)/2;
        if(k%2==0)
            printf("%d/%d\n", k-s+n,s-n+1);
        else
            printf("%d/%d\n", s-n+1,k-s+n);
    }
    return 0;
}
