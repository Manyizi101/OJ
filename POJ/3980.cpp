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

int mod(int n, int m)
{
    return n % m;
}

int main(int argc, char const *argv[])
{
    int N, M;
    while ((scanf("%d%d", &N, &M)) != EOF)
    {
        printf("%d\n", mod(N, M));
    }
    //system("pause");
    return 0;
}