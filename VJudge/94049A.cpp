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

int main() {
    set<int> s;
    int n, k;
    while (cin >> n) {
        s.clear ();
        int x;
        for (int i=1; i<=n; ++i) {
            cin >> x;
            s.insert (x);
        }
        cin >> k;
        cout << ((n-s.size () <= k) ? n - k : s.size ()) << endl;
    }
    return 0;
}
