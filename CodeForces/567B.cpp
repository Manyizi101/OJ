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
vector<int> v;
char x;
int tmp;
int ans;

int main()
{
    while (~scanf("%d", &n))
    {
        ans = 0;
        v.clear();
        for (int i = 0; i < n; i++)
        {
            getchar();
            scanf("%c%d", &x, &tmp);
            if (x == '+')
            {
                v.push_back(tmp);
                ans = max(ans, (int)v.size());
            }
            else if (x == '-')
            {
                int flag = 0;
                for (auto it = v.begin(); it != v.end(); ++it)
                {
                    if (*it == tmp)
                    {
                        flag = 1;
                        v.erase(it);
                        break;
                    }
                }
                if (flag == 0) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}