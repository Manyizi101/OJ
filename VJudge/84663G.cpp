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

int n, m, count = 1;

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        scanf("%d", &m);
        char puzzle[n][m];
        for (int i = 0; i < n; i++) scanf("%s", puzzle[i]);
        int num[n][m];
        memset(num, 0, sizeof(num));
        int count1 = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if ((i - 1 < 0 || j - 1 < 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*') && puzzle[i][j] != '*') {
                    num[i][j] = count1++;
                }
                else {
                    num[i][j] = 0;
                }
            }
        if (count - 1) printf("\n");
        printf("puzzle #%d:\n", count++);

        //Across deal.
        printf("Across\n");
        for (int i = 0; i < n; i++)
            for (int j = 0, key = 1; j < m; j++)
            {
                if (num[i][j])
                {
                    while (1)
                    {
                        if (j + key < m && puzzle[i][j + key] != '*') key++;
                        else break;
                    }
                    printf("%3d.", num[i][j]);
                    for (int ii = j; j < ii + key; j++) printf("%c", puzzle[i][j]);
                    printf("\n");
                }
                key = 1;
            }

        //Down deal.
        char ans[count1][n + 1];
        memset(ans, '\0', sizeof(ans));
        printf("Down\n");
        for (int i = 0; i < m; i++)
            for (int j = 0, key = 1; j < n; j++)
            {
                if (num[j][i])
                {
                    while (1)
                    {
                        if (j + key < n && puzzle[j + key][i] != '*') key++;
                        else break;
                    }
                    for (int ii = j, kk = 0, gg = num[j][i]; j < ii + key; j++, kk++)
                    {
                        ans[gg][kk] = puzzle[j][i];
                    }
                }
                key = 1;
            }
        for (int jj = 1; jj < count1; jj++)
        {
            if (ans[jj][0] != '\0')
            {
                printf("%3d.", jj);
                printf("%s\n", ans[jj]);
            }
        }
    }
    return 0;
}