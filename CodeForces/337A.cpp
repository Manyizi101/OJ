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

#define MAXN 100+10

int n;
char a[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while (n--)
    {
        memset(a, 0, sizeof(a));
        scanf("%s", a);
        int len = strlen(a);
        if (len <= 10) cout << a << endl;
        else cout << a[0] << len - 2 << a[len - 1] << endl;
    }
    return 0;
}