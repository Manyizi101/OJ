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

vector<vector<string> > a;
int Max[10000] = {0};

void read()
{
    a.clear();
    string tmp;
    int num = 0;
    while (getline(cin, tmp))
    {
        num = 0;
        stringstream ss(tmp);
        vector<string> x;
        string tt;
        while (ss >> tt)
        {
            Max[num] = max((int)tt.size(), Max[num]);
            num++;
            x.push_back(tt);
        }
        a.push_back(x);
    }
}

int main()
{
    //freopen("85925A.out", "w", stdout);
    read();
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        for (auto j = (*i).begin(); j != (*i).end(); ++j)
        {
            cout << (*j);
            if (j != (*i).end() - 1)
                for (int x = 0; x < (Max[j - (*i).begin()] - (int)(*j).size()) + 1; ++x)
                {
                    cout << " ";
                }
        }
        cout << endl;
    }
    return 0;
}