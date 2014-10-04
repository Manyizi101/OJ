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

long long int a, b, c;

int main(int argc, char const *argv[])
{
    while (cin >> a >> b >> c&&(a||b||c))
    {
        long long int d = (a + 1 ) ^ (b + 1) ^ (c + 1);
        if (d != 0)  cout << "Alice wins the game.\n";
        else cout << "Bob wins the game.\n";
    }
    return 0;
}