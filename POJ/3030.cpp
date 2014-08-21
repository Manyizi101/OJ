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

int main(int argc, char const *argv[])
{
    int n, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        if (a > b - c)cout << "do not advertise" << endl;
        else if (a == b - c)cout << "does not matter" << endl;
        else cout << "advertise" << endl;
    }
    return 0;
}
