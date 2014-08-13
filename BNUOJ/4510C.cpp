#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
typedef long long ll;
#define pi acos(-1)
#define eps 1e-6;
using namespace std;
const int MAX = 1 << 28;

int  i, j;

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &i, &j)!=EOF)
    {
        printf("%d\n", 1 + (i - j) * (j - 1));
    }
    return 0;
}