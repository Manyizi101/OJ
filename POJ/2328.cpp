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

char str[3][20] = {"too high", "too low", "right on"};
int answer[1100];
int getnum[1100];

int getanswer(char ans[])
{
    if (strcmp(str[0], ans) == 0)
    {
        return 1;
    }
    else if (strcmp(str[1], ans) == 0)
    {
        return -1;
    }
    else if (strcmp(str[2], ans) == 0)
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char tmp[20];
    int num, rightnum;
    int i, j;
    int flag;

    while (scanf("%d", &num), num != 0)
    {
        getchar();
        gets(tmp);
        answer[0] = getanswer(tmp);
        getnum[0] = num;
        for (i = 0; answer[i] != 0; )
        {
            i++;
            scanf("%d", &num);
            getchar();
            gets(tmp);
            answer[i] = getanswer(tmp);
            getnum[i] = num;
        }
        rightnum = getnum[i];
        i++;
        for (flag = 1, j = 0; j < i - 1; j++)
        {
            if (getnum[j] - rightnum > 0 && answer[j] == 1 )
            {
                continue;
            }
            else if (getnum[j] - rightnum < 0 && answer[j] == -1)
            {
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("Stan may be honest\n");
        }
        else if (flag == 0)
        {
            printf("Stan is dishonest\n");
        }
    }
    return 0;
}
