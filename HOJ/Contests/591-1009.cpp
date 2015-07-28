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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int MAXN = 51000;

int n, l[MAXN], r[MAXN];
int B[MAXN];

int BinarySearch(int *arraya, int value, int nLength)
{
    int begin = 0;
    int end = nLength - 1;
    int mid = begin + (end - begin) / 2;
    while (begin < end)
    {
        mid = begin + (end - begin) / 2;
        if (l[arraya[mid]] == l[value] && r[arraya[mid]] == r[value])
            return mid;
        else if (l[arraya[mid]] > l[value] && r[arraya[mid]] < r[value])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    //cout << begin << endl;
    return mid;
}

int LIS(int *arraya, int *arrayb, int nLength)
{
    int nLISLen = 1;
    B[0] = 0;
    for (int i = 1; i < nLength; i++)
    {
        if (arraya[i] >= arraya[B[nLISLen - 1]] && arrayb[i] <= arrayb[B[nLISLen - 1]])
        {
            B[nLISLen] = i;
            nLISLen++;
            //cout << "st " << i << endl;
        }
        else
        {
            int pos = BinarySearch(B, i, nLISLen);
            B[pos] = i;
            //cout << "er " << i << endl;
        }
    }
    return nLISLen;
}

int main()
{
    while (~scanf("%d", &n))
    {
        memset(B, 0, sizeof(B));
        int tmp[MAXN];
        for (int i = 0; i < n; i++)    scanf("%d", &tmp[i]);
        for (int i = n - 1; i >= 0; i--)    l[n - i - 1] = tmp[i];
        for (int i = 0; i < n; i++)    scanf("%d", &tmp[i]);
        for (int i = n - 1; i >= 0; i--)    r[n - i - 1] = tmp[i];
        int len = LIS(l, r, n);
        printf("%d\n", len);
        printf("%d", B[len] + 1);
        for (int i = len - 1; i > 0 ; i--)  printf(" %d", B[len - i] + 1);
        printf("\n");
    }
    return 0;
}