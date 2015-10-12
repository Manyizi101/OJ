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
#include <unordered_map>
#define debug puts("-----")

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

map<int, vector<int> > mp;
map<int, int> cnt;
int n,m;
int tmp;

int main()
{
    while(~scanf("%d%d", &n,&m)) {
        mp.clear();
        for(int i=0; i<n; ++i) {
            scanf("%d", &tmp);
            mp[tmp].push_back(i+1);
            cnt[tmp]=0;
        }
        for(int i=0; i<m; ++i) {
            scanf("%d", &tmp);
            if(cnt[tmp]<mp[tmp].size()) {
                printf("%d\n", mp[tmp][cnt[tmp]]);
                cnt[tmp]++;
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}
