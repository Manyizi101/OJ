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


int cal(int x)
{
    if (x == 0) return 1;
    else if (x == 1) return 6;
    else if (x == 2)  return 35;
    else
    {
        return cal(x - 1) * (2 * sqrt(2) + 3) + 0.5;
    }
}
int main(int argc, char const *argv[])
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << cal(n - 1);
        if (t)   cout << endl;
    }
    return 0;
}