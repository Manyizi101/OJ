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


queue<string>q;
int main(int argc, char const *argv[])
{
    int a, b, n;
    scanf("%d", &n);
    while (n--)
    {
        string tmp;
        cin >> tmp;
        q.push(string(tmp));
    }
    scanf("%d,%d", &a, &b);
    for (int i = 1; i < a; i++)
    {
        q.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        for (int i = 1; i < b; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << endl, q.pop();
    }
}
