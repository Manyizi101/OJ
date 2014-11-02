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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int n;
int total, cost ;

int main(int argc, char const *argv[])
{
    while (scanf("%d", &n), n)
    {
        total = 0, cost = 0;
        priority_queue<int, vector<int>, greater<int> > q;
        while (n--)
        {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        while (q.size() > 1)
        {
            total = q.top();
            q.pop();
            total += q.top();
            q.pop();
            cost += total;
            q.push(total);
        }
        printf("%d\n", cost);
    }

    return 0;
}
