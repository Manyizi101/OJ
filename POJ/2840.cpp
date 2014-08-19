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

int main(int argc, char const *argv[])
{
    int ii, casenum;
    int h, m;

    scanf("%d", &casenum);
    for (ii = 0; ii < casenum; ii++)
    {
        scanf("%d:%d", &h, &m);
        if (m == 0)
        {
            if (h == 12)
            {
                printf("24\n");
            }
            else
            {
                printf("%d\n", (12 + h) % 24);
            }
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
