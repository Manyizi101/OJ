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
using namespace std;


int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    int i, j, n, w[355][355], f[355][355];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++) cin >> w[i][j];
    }
    for (i = 0; i < n; i++) f[n - 1][i] = w[n - 1][i];
    for (i = n - 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++) f[i][j] = w[i][j] + max(f[i + 1][j], f[i + 1][j + 1]);
    }
    cout << f[0][0] << endl;
    return 0;
}