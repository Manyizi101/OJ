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

int main(int argc, char const *argv[])
{
    int pot;
    int bet;
    int fpot;
    while (scanf("%d%d%d", &pot, &bet, &fpot) != -1, pot + bet + fpot)
    {
        if (pot > fpot)pot -= fpot;
        else pot = fpot - pot;
        if (pot % bet != 0)
            printf("No accounting tablet\n");
        else
        {
            pot = pot / bet;
            int ans;
            ans = 0;
            ans += pot / 3; pot %= 3;
            ans += pot / 2, pot %= 2;
            ans += pot;
            printf("%d\n", ans);
        }
    }
    return 0;
}
