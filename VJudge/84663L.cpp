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


char str1[222];
char str2[222];

int main()
{
    int i, j, len1, len2, x1, x2;
    while (cin >> str1 >> str2)
    {
        len1 = strlen(str1);
        len2 = strlen(str2);
        memset(str1 + len1, 0, sizeof(str1) - len1);
        memset(str2 + len2, 0, sizeof(str2) - len2);
        for (i = 0; i < len1; i++)
            str1[i] -= 48;
        for (i = 0; i < len2; i++)
            str2[i] -= 48;
        for (i = 0; i < len1; i++)
        {
            for (j = 0; j < len2; j++)
                if (str1[i + j] + str2[j] > 3)
                    break;
            if (j == len2)
                break;
        }
        x1 = len2 + i;
        for (i = 0; i < len2; i++)
        {
            for (j = 0; j < len1; j++)
                if (str2[i + j] + str1[j] > 3)
                    break;
            if (j == len1)
                break;
        }
        x2 = len1 + i;
        cout << max(max(len1, len2), min(x1, x2)) << endl;
    }
    return 0;
}
