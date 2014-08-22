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

char str1[110];
char str2[110];

int main(int argc, char const *argv[])
{
    int ii, casenum;
    int count;
    int len1, len2;
    int i, j;
    int flag;

    scanf("%d", &casenum);
    getchar();
    for (ii = 0; ii < casenum; ii++)
    {
        scanf("%s%s", str1, str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        flag = 0;
        for (i = j = count =  0; !flag && j < len1; j++)
        {
            if (str1[j] == str2[i])
            {
                count++;
                i++;
            }
            if (count == len2)
            {
                flag = 1;
            }
        }
        for (count = i = 0, j = len1 - 1; !flag && j >= 0; j--)
        {
            if (str1[j] == str2[i])
            {
                count++;
                i++;
            }
            if (count == len2)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
