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

#define MAXN  100+10

char a[MAXN];

bool rule(char a[])
{
    for (int i = 1; i < strlen(a); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')    return false;
    }
    return true;
}

bool judge(char a[])
{
    if (rule(a)) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    scanf("%s", a);
    if (judge(a))
    {
        if (a[0] >= 'a' && a[0] <= 'z')
            a[0] = a[0] - 'a' + 'A';
        else
            a[0] = a[0] - 'A' + 'a';
        for (int i = 1; i < strlen(a); i++)
        {
            a[i] = a[i] - 'A' + 'a';
        }
        cout << a;
    }
    else
    {
        cout << a;
    }
    return 0;
}
