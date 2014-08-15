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
    int i, n;
    int counts = 0;
    scanf("%d", &n);
    for (i = 1; i <= n / 2; i += 2) 
        if (n % i == 0)
            counts++;
    if (n % 2 != 0)
        counts++;
    printf("%d\n", counts);
    return 0;
}