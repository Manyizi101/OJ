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

const int MAXN = 1000 + 10;

int n;
int a[MAXN];
int sum = 0;

int main()
{
    while (~scanf("%d", &n))
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        double avg = sum * 1.0 / n;
        double mid = a[(n - 1) / 2] * 1.0;
        //cout << avg << " " << mid << endl;
        if (avg >= mid) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}