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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

int f(int n, int a[], int idx)
{
    if(n==0) return 1;
    if(idx==4)  return 0;
    for(int i=(int)sqrt(n); i>=1; i--)
    {
        a[idx] = i;
        if(i * i == n || f(n - i * i, a, idx + 1))  return 1;
    }
    return 0;
}

int main()
{
    for(;;)
    {
        int number;
        scanf("%d",&number);
        int a[] = {0,0,0,0};
        int r = f(number, a, 0);
        printf("%d: %d %d %d %d\n", r, a[0], a[1], a[2], a[3]);
    }
    return 0;
}
