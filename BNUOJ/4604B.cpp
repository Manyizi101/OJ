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
#define inf (1<<30)
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, n, i;
    int judge;
    while (cin >> a >> b >> n && a && b && n)
    {
        judge = 0;
        for (i = 0; i <= b; i++)
        {
            if ((n - a * i) % b == 0)
            {
                judge = 1;
                break;
            }
        }
        if (judge) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}