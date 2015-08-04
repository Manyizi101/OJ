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

float x[100] = {0, 1312.0, 2372.3, 520.2, 899.5, 800.6, 1086.5, 1402.3, 1313.9, 1681.0, 2080.7, 495.8, 737.7, 577.5, 786.5, 1011.8, 999.6, 1251.2, 1520.6, 418.8, 589.8, 633.1, 658.8, 650.9, 652.9, 717.3, 762.5, 760.4, 737.1, 745.5, 906.4, 578.8, 762, 947.0, 941.0, 1139.9, 1350.8};
int u, v;

int main()
{
    x[53] = 1008.4;
    x[54] = 1170.4;
    x[85] = 890;
    x[86] = 1037;
    while (~scanf("%d%d", &u, &v))
    {
        if (x[u] > x[v])   printf("FIRST BIGGER\n");
        else printf("SECOND BIGGER\n");
    }
    return 0;
}