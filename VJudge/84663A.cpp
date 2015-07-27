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

const int N = 100 + 10;

int t;
char tmp[N];
string a[N];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < N; i++)    a[i].clear();
        scanf("%s", tmp);
        int len = strlen(tmp);
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)    a[i] += tmp[(j + i) % len];
        }
        cout << *min_element(a, a + len) << endl;
    }
    return 0;
}