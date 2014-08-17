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

int n, m, i, j, c, k, l, p;
char a[110], b[110];
int flag;

int main(int argc, char const *argv[])
{
    while (~scanf("%s", a))
    {
        p = c = j = 0;
        k = 1;
        for (i = 0; i < 110; i++)
        {
            b[i] = '\0';
        }
        if (a[0] < 'a' || a[0] > 'z')
        {
            p = 1;
        }
        l = strlen(a);
        b[0] = a[0];
        for (i = 1; i < l; i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                b[k] = a[i]; k++;
            }
            else if (a[i] == '_')
            {
                if (j == 1)
                {
                    p = 1;
                    break;
                }
                if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
                {
                    b[k] = a[i + 1] + 'A' - 'a';
                    i++;
                    k++;
                }
                else
                {
                    p = 1;
                    break;
                }
                c = 1;
            }
            else if (a[i] >= 'A' && a[i] <= 'Z')
            {
                if (c == 1)
                {
                    p = 1;
                    break;
                }
                b[k] = '_';
                k++;
                b[k] = a[i] - ('A' - 'a');
                k++;
                j = 1;
            }
            else
            {
                p = 1;
                break;
            }
        }
        if (p == 1)
        {
            printf("Unknown!\n");
        }
        else
        {
            printf("%s\n", b);
        }
    }
    return 0;
}