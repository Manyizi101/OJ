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

#define MAX_N 2000

int n, i;
char s[MAX_N + 1];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &s[i]);
    }
    int a = 0, b = n - 1;
    int flag = 0;
    while (a <= b)
    {
        bool left = false;
        for (i = 0; a + i <= b; i++)
        {
            if (s[a + i] < s[b - i])
            {
                left = true;
                break;
            }
            else if (s[a + i] > s[b - i])
            {
                left = false;
                break;
            }
        }
        ++flag;
        cout << (left ? s[a++] : s[b--]) << (flag % 80 ? "" : "\n");
    }
    return 0;
}