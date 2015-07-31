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

int main()
{
    double M[10][31], a, c, x;
    long long int E[10][31], b, d;
    int i, j;
    for (i = 0; i <= 9; i++)
        for (j = 1; j <= 30; j++)
        {
            a = 1 - pow(2, -(i + 1));
            b = pow(2, j) - 1;
            x = log10(a) + b * log10(2);
            d = floor(x);
            c = pow(10, x - d);
            M[i][j] = c;
            E[i][j] = d;
        }

    char s[30];
    double p;
    int q;
    while (cin >> s) {
        s[17] = ' ';
        sscanf(s, "%lf %d", &p, &q);
        for (i = 0; i < 10; i++)
            for (j = 1; j <= 30; j++)
                if (fabs(M[i][j] - p) < 1e-4 && E[i][j] == q)
                    cout << i << ' ' << j << endl;
    }
    return 0;
}
