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

const int maxn = 100000 + 10;
char str[maxn];
int cnt[28];

ll ans;
int t, st, k, num, len;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        st = ans = 0;
        scanf("%s%d", str, &k);
        len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            num = str[i] - 'a';
            cnt[num]++;
            if (cnt[num] > k)
            {
                while (str[st] != str[i])
                {
                    cnt[str[st] - 'a']--;
                    st++;
                }
                cnt[num]--;
                st++;
            }
            ans += i - st + 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
