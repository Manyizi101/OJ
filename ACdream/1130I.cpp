/*
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

#define MAXN 50001

int t, n, a[MAXN];
int left;
void init()
{
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)    scanf("%d", &a[i]);
}

int main(int argc, char const *argv[])
{
    freopen("2479.in", "r", stdin);
    freopen("2479.out", "w", stdout);
    scanf(" % d", &t);
    while (t--)
    {
        init();
    }
    cout<<"Hello,world!!!!";
    return 0;
}
**/
/*
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
int n, ans = 0;
void dfs(int cur, int x, int now_sum, int now_multi)
{
    if (cur == n)
    {
        if (now_sum == now_multi)
            ans++;
        return;
    }
    else
    {
        for (int i = x; i >= 1; i--)
        {
            dfs(cur + 1, i, now_sum + i, now_multi * i);
        }
    }

}
int main()
{
    freopen("2479.in", "r", stdin);
    freopen("2479.out", "w", stdout);
    while (cin >> n)
    {
        dfs(0, n, 0, 1);
        cout << ans << endl;
        ans = 0;
    }
}
**/

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

int num[501]={0,1,1,1,1,3,1,2,2,2,2,3,2,4,2,2,2,4,2,4,2,4,2,4,1,5,4,3,3,5,2,4,3,5,2,3,2,6,3,3,4,7,2,5,2,4,4,5,2,5,4,4,3,7,2,5,4,5,4,4,2,9,3,4,4,7,2,5,5,4,3,6,3,9,4,3,3,6,3,5,2,7,4,5,2,10,5,4,5,8,2,6,3,6,3,6,5,6,5,4,5,8,3,6,3,5,5,5,3,9,4,6,2,11,1,6,6,7,6,4,3,10,4,4,4,6,2,8,6,5,5,9,4,10,5,4,5,8,4,6,4,7,2,5,3,11,5,5,4,10,4,10,3,7,4,6,3,8,6,3,4,10,5,8,3,6,8,4,3,9,4,5,5,10,1,5,8,9,4,6,4,15,6,8,5,8,3,5,6,6,5,7,2,11,5,4,5,8,3,7,6,9,4,10,5,11,6,5,6,8,2,9,4,9,3,7,3,10,5,4,3,12,6,7,4,8,8,5,7,11,5,4,5,11,2,9,7,7,6,9,3,12,6,6,5,7,5,8,9,8,5,8,2,13,4,4,5,11,2,6,5,10,4,9,3,10,7,7,5,6,5,13,4,9,7,9,5,12,6,5,7,14,4,7,6,6,5,6,5,11,4,6,5,12,3,9,4,6,8,5,3,12,7,6,4,13,8,8,6,10,6,9,4,14,6,5,9,10,5,7,6,8,4,8,3,12,8,5,3,8,2,10,5,10,6,5,6,14,9,4,7,15,4,9,6,10,5,8,5,10,2,7,5,12,2,8,6,6,7,7,3,16,5,7,5,13,4,7,9,10,9,13,5,14,5,8,8,7,4,10,7,9,4,10,5,13,8,7,6,8,3,9,6,11,4,4,4,14,7,4,8,13,5,8,7,6,7,7,5,10,8,8,4,12,5,11,8,11,8,11,3,17,4,5,6,12,6,5,9,9,7,11,6,18,4,7,8,10,6,5,2,9,5,10,1,10,10,5,5,12,4,12,7,9,4,6,7,12,8,7,7,13,6,14,5,9,7,8,5,16,6,6,4,16,3,8,6,10,8,7,4,18,6,6,6,14,4,13,10,8,6,13,4,9,6,7,8,10,5,8,7};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<num[n]<<endl;
}