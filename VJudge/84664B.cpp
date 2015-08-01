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

const int maxn = 100;
int remain, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch)
{
    int bad = 1;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ch)
        {
            remain--;
            s[i] = ' ';
            bad = 0;
        }
    }
    if (bad) chance--;
    if (!chance) lose = 1;
    if (!remain)   win = 1;
}

int main()
{
    int rnd;
    while (scanf("%d", &rnd) == 1 && rnd != -1)
    {
        scanf("%s%s", s, s2);
        printf("Round %d\n", rnd);
        win = lose = 0;
        remain = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); ++i)
        {
            guess(s2[i]);
            if (win || lose)   break;
        }
        if (win) printf("You win.\n");
        else if (lose)   printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}