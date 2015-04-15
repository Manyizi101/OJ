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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

const int MAXN = 3000 + 10;

int n, m;
string que1[MAXN], que2[MAXN];
int len1[MAXN], len2[MAXN];
string a[MAXN], tmp1, tmp2;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        cin >> que1[i] >> que2[i];
        len1[i] = que1[i].length();
        len2[i] = que2[i].length();
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!a[i].compare(que1[j]))
            {
                cout << ((len1[j] > len2[j]) ? que2[j] : que1[j]);
                break;
            }
        }
        cout << " ";
    }
    return 0;
}