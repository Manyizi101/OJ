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

int readchar()
{
    for (;;)
    {
        int ch = getchar();
        if (ch != '\n' && ch != '\r')  return ch;
    }
}

int readint(int c)
{
    int v = 0;
    while (c--)  v = v * 2 + readchar() - '0';
    return v;
}

int code[8][1 << 8];
int readcodes()
{
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    for (int len = 2; len <= 7; ++len)
    {
        for (int i = 0; i < (1 << len) - 1; ++i)
        {
            int ch = getchar();
            if (ch == EOF) return 0;
            if (ch == '\n' || ch == '\r')  return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

int main()
{
    while (readcodes())
    {
        for (;;)
        {
            int len = readint(3);
            if (len == 0)  break;
            for (;;)
            {
                int v = readint(len);
                if (v == (1 << len) - 1)   break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}