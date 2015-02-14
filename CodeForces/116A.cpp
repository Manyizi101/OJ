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

#define MAXN 1000+10

int n;
int ans = 0;
int tmp = 0;
int a, b;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &a, &b);
        tmp = tmp - a + b;
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
