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
#define inf (1<<30)
using namespace std;


int main(int argc, char const *argv[])
{
    int ii, casenum;
    int sum, substract;
    float one, two;

    scanf("%d", &casenum);
    for (ii = 0; ii < casenum; ii++)
    {
        scanf("%d%d", &sum, &substract);
        one = (sum + substract) / 2.0;
        two = (sum - substract) / 2.0;
        if (one >= 0 && two >= 0 && one - (int)one == 0 && two - (int)two == 0)
        {
            printf("%d %d\n", (int)one, (int)two);
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
