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
#define ll long long int
using namespace std;

#define MAXN 100+10

char a[MAXN];
int b[MAXN];

void init()
{
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++)
    {
        b[i] = a[i] - '0';
    }
}

bool judge(char a[])
{
    if (strlen(a) < 7) return false;
    for (int i = 0; i < strlen(a) - 6; i++)
    {
        int tmp = 0;
        for (int j = 0; j < 7; j++)
        {
            tmp += b[i + j];
        }
        if (tmp == 7 || tmp == 0)  return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    init();
    judge(a) ? puts("YES") : puts("NO");
    return 0;
}
