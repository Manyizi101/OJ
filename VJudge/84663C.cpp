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

char str[85];
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(str, 'S', sizeof(str));
        scanf("%s", str);
        double M, sum = 0.0;
        for (int i = 0; i < strlen(str); i++)
        {
            int n = 1;
            if (str[i] <= '9') continue;
            if (str[i] == 'C') M = 12.01;
            if (str[i] == 'H') M = 1.008;
            if (str[i] == 'O') M = 16.00;
            if (str[i] == 'N') M = 14.01;
            if (str[i + 1] <= '9' && str[i + 1] >= '0')
            {
                n = str[i + 1] - '0';
                if (str[i + 2] <= '9' && str[i + 2] >= '0') n = n * 10 + str[i + 2] - '0';
            }
            sum += M * n;
        }
        printf("%.3f\n", sum);
    }
    return 0;
}