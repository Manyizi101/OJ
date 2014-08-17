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
    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if (a <= 168)
        {
            printf("CRASH %d\n", a);
        }
        else if (b <= 168)
        {
            printf("CRASH %d\n", b);
        }
        else if (c <= 168)
        {
            printf("CRASH %d\n", c);
        }
        else
        {
            printf("NO CRASH\n");
        }
    }
    return 0;
}
