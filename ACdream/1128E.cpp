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

long long int n, k;

char str[50];

int main(int argc, char const *argv[])
{
    while (scanf("%lld%lld", &n, &k) && (n != 0 && k != 0))
    {
        long long i, tmp;
        if (k == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            string min = "999999999999999999";
            for (i = k; i <= n; i += k)
            {
                string now;
                tmp = i;
                int cnt = 0;
                while (tmp != 0)
                {
                    str[cnt] = (tmp % 10) + '0';
                    tmp /= 10;
                    cnt++;
                }
                while (cnt--)
                {
                    now += str[cnt];
                }
                if (min > now) min = now;
            }
            for (i = 0; i < min.size(); i++)
            {
                str[i] = min[i];
            }
            str[min.size()] = '\0';
            printf("%s\n", str);
        }
    }
    return 0;
}
*/

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

long long int n, k;
int lenn, lenk, lenans;
long long int ans;
long long  int i, j, small;

int get_weishu(long long int x)
{
    int cnt = 0;
    while (x != 0)
    {
        x /= 10;
        cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    while (cin >> n >> k && (n || k))
    {
        lenn = get_weishu(n);
        lenk = get_weishu(k);
        ans = pow(10, lenk);
        small = k;
        if (lenn - lenk == 0 || k == 1)
        {
            small = k;
        }
        else if (lenn - lenk == 1)
        {
            int temp = lenk;
            for (j = k; j <= n; j += k)
            {
                if (get_weishu(j) == temp + 1)
                {
                    small = j;
                    break;
                }
            }
        }
        else
        {
            for (j = lenk; j <= lenn && ans <= n; j++)
            {
                if (ans % k == 0)    small = ans;
                for (i = 0; i < k && ans+i <= n; i++)
                {
                    if ((ans + i) % k == 0)    small = ans + i;
                }
                ans = ans * 10;
            }
        }
        while (small % 10 == 0 && small >= k * 10) small /= 10;
        cout << small << endl;
    }
    return 0;
}