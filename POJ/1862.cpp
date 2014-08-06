#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int a[110];

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    double ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = 2 * sqrt(ans * a[i]);
    }
    printf("%.3f\n", ans);
    return 0;
}
