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
    int n;
    int k;
    int sum = 0;
    while (cin >> n >> k)
    {
        sum = n;
        while (n / k)
        {
            sum += (n / k);
            n = n % k + n / k;
        }
        cout << sum << endl;
    }
    return 0;
}