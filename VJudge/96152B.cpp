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

const int MAXN = 5e6+10;
const ll mod = 998244353;

struct Trie {
    int ch[MAXN][2],val[MAXN],cnt;
    ll ans;
    void init()
    {
        ans = cnt = val[0] = ch[0][0] = ch[0][1] = 0;
    }
    void insert(int v)
    {
        val[0]++;
        int deep = 0,num = val[0],next = 0;
        for(int i = 0; i < 30; i++) {
            int c = v & 1;
            if(!ch[next][c]) {
                ch[next][c] = ++cnt;
                val[cnt] = ch[cnt][0] = ch[cnt][1] = 0;
            }
            val[ch[next][c]]++;
            deep++;
            ans += ((num - val[ch[next][c]]) << deep);
            ans %= mod;
            next = ch[next][c];
            v >>= 1;
            num = val[next];

        }
    }
} trie;

int t,n,cs=1;
int a;

int main()
{
    scanf("%d", &t);
    while(t--) {
        trie.init();
        scanf("%d", &n);
        for(int i=0; i<n; ++i) {
            scanf("%d", &a);
            trie.insert(a);
        }
        printf("Case #%d: %I64d\n", cs++, trie.ans);
    }
}
