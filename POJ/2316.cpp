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
    int a[11] = {0}, i;
    char b[11];
    while (cin >> b)
    {
        for (i = 0; i < strlen(b); i++)
            a[i] += b[i] - '0';
    }
    for (i = 0; i < strlen(b); i++)
    {
        a[i] %= 10;
        cout << a[i];
    }
    cout << endl;
    return 0;
}
