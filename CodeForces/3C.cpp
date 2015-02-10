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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int xcnt;
int ocnt;
char brd[3][3];

bool win(char tmp)
{
    for (int i = 0; i < 3; i++)
    {
        if (brd[i][0] == tmp && brd[i][1] == tmp && brd[i][2] == tmp) return true;
        if (brd[0][i] == tmp && brd[1][i] == tmp && brd[2][i] == tmp) return true;
    }

    if (brd[1][1] != tmp) return false;

    if (brd[0][0] == tmp && brd[2][2] == tmp) return true;
    if (brd[0][2] == tmp && brd[2][0] == tmp) return true;

    return false;
}

bool legal()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            xcnt += brd[i][j] == 'X';
            ocnt += brd[i][j] == '0';
        }
    }

    if (xcnt - ocnt > 1) return false;
    if (xcnt - ocnt < 0) return false;
    if (win('X') && xcnt == ocnt) return false;
    if (win('0') && xcnt - ocnt == 1) return false;

    return true;
}


int main(int argc, char const *argv[])
{
    xcnt = 0;
    ocnt = 0;

    char stmp[4];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", stmp);
        for (int j = 0; j < 3; j++) brd[i][j] = stmp[j];
    }

    do
    {
        if (!legal())
        {
            printf("illegal\n");
            break;
        }
        if (win('X'))
        {
            printf("the first player won\n");
            break;
        }
        if (win('0'))
        {
            printf("the second player won\n");
            break;
        }
        if (xcnt + ocnt == 9)
        {
            printf("draw\n");
            break;
        }
        if (xcnt == ocnt)
        {
            printf("first\n");
            break;
        }
        if (xcnt - ocnt == 1)
        {
            printf("second\n");
            break;
        }
    }
    while (true);
    return 0;
}
