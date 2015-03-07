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

#define MAXN 15+10

int n;
char a[MAXN];
int n2, n3, n5, n7;

void init()
{
    n2 = n3 = n5 = n7 = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &a[i]);
        if (a[i] == '2')
        {
            n2++;
        }
        else if (a[i] == '3')
        {
            n3++;
        }
        else if (a[i] == '4')
        {
            n3++;
            n2 += 2;
        }
        else if (a[i] == '5')
        {
            n5++;
        }
        else if (a[i] == '6')
        {
            n3 ++;
            n5++;
        }
        else if (a[i] == '7')
        {
            n7++;
        }
        else if (a[i] == '8')
        {
            n2 += 3;
            n7++;
        }
        else if (a[i] == '9')
        {
            n3 += 2;
            n2 += 1;
            n7++;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    for (int i = 1; i <= n7; i++)  cout << '7';
    for (int i = 1; i <= n5; i++)  cout << '5';
    for (int i = 1; i <= n3; i++)  cout << '3';
    for (int i = 1; i <= n2; i++)  cout << '2';
    return 0;
}