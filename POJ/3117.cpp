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
    int T, N;
    int i;
    char name[20];
    int num, sum;

    while (scanf("%d%d", &T, &N), T != 0 || N != 0)
    {
        getchar();
        for (i = sum = 0; i < T; i++)
        {
            scanf("%s%d", name, &num);
            getchar();
            sum += num;
        }
        printf("%d\n", 3 * N - sum);
    }
    return 0;
}
