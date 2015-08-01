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

int n;

int cal(int x)
{
    int ans = 0;
    int flag = 0;
    while (x > 0)
    {
        flag++;
        if (flag & 1)
            ans += (x % 10);
        else
            ans -= (x % 10);
        x /= 10;
    }
    if (flag & 1)
        return ans;
    else
        return -ans;
}

int main()
{
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        ans += cal(i);
        cout << ans << " " << cal(i) << endl;
    }
    return 0;
}