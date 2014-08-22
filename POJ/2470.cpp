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


int arr[110000];
int end[110000];

int change(int arr[], int n)
{
    int i, j;
    int flag = 1;

    for (i = 1; i <= n; i++)
    {
        end[arr[i]] = i;
    }
    for (i = 1; i <= n; i++)
    {
        if (end[i] != arr[i])
        {
            flag = 0;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    int n, i;

    while (scanf("%d", &n), n != 0)
    {
        memset(arr, 0, sizeof(arr));
        memset(end, 0, sizeof(end));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (change(arr, n))
        {
            printf("ambiguous\n");
        }
        else
        {
            printf("not ambiguous\n");
        }
    }
    return 0;
}
