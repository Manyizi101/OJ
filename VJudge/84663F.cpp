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

string str;
char q;
char a[1000][1000];
int x, y, flag = 0, judge;

bool run(char q)
{
    if (q == 'L')
    {
        if (x <= 1)   return false;
        else
        {
            swap(a[y][x], a[y][x - 1]);
            x--;
            return true;
        }
    }
    else if (q == 'R')
    {
        if (x >= 5)   return false;
        else
        {
            swap(a[y][x], a[y][x + 1]);
            x++;
            return true;
        }
    }
    else if (q == 'A')
    {
        if (y <= 1)   return false;
        else
        {
            swap(a[y][x], a[y - 1][x]);
            y--;
            return true;
        }
    }
    else if (q == 'B')
    {
        if (y >= 5)   return false;
        else
        {
            swap(a[y][x], a[y + 1][x]);
            y++;
            return true;
        }
    }
}

int main()
{
    while (gets(a[1] + 1) && a[1][1] != 'Z')
    {
        str.clear();
        //getchar();
        //for (int i = 2; i <= 5; i++)   scanf("%c", &a[1][i]);
        //cout << a[1] + 1 << endl;
        judge = 1;
        for (int i = 2; i <= 5; ++i)
        {
            gets(a[i] + 1);
            //cout << a[i] + 1 << endl;
            //getchar();
        }
        //for (int i = 1; i <= 5; ++i)   printf("%s\n", a[i]+1);
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (a[i][j] == ' ')    x = j, y = i;
            }
        }
        while (scanf("%c", &q))
        {
            if (q == '\n') continue;
            if (q == '0')  break;
            str += q;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (!run(str[i]))
            {
                judge = 0;
                break;
            }
        }
        if (flag)
        {
            printf("\n");
        }
        printf("Puzzle #%d:\n", ++flag);
        if (!judge)    printf("This puzzle has no final configuration.\n");
        else
        {
            for (int i = 1; i <= 5; ++i)
            {
                printf("%c", a[i][1]);
                for (int j = 2; j <= 5; ++j)
                {
                    printf(" %c", a[i][j]);
                }
                printf("\n");
            }
        }
        getchar();
        memset(a, 0, sizeof(a));
    }
    return 0;
}