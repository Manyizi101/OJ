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

int n;
string str;

bool judge(string str, string a)
{
    for (int i = 0; i < str.size(); i += a.size())
    {
        if (str.substr(i, a.size()) != a)   return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        cin >> str;
        for (int i = 1; i <= str.size(); i++)
        {
            string a = str.substr(0, i);
            if (judge(str, a))
            {
                cout << i << endl;
                break;
            }
        }
        if (n != 0)    cout << endl;
    }
    return 0;
}