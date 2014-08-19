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

int grid[510][110];

int main(int argc, char const *argv[])
{
    int n, d, i, j, ans, tmp;
    bool flag;
    while (cin >> n >> d)
    {
        if (n == 0 && d == 0)  break;
        flag = false;
        for (i = 0; i < d; i++)
            for (j = 0; j < n; j++)
                cin >> grid[i][j];

        for (i = 0; i < n; i++)
        {
            tmp = 0;
            for (j = 0; j < d; j++)
            {
                if (grid[j][i] == 1)
                    tmp++;
            }
            if (tmp == d)
            {
                cout << "yes" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "no" << endl;
    }
    return 0;
}
