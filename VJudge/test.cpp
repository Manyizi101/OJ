#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
int a[110000];
int vis[110000];
int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        ll sum = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum % n)
        {
            printf("NO\n");
            continue;
        }
        int flag = 1;
        ll ed = sum / n;
        for (int i = 0; i < n; i++)
        {
            if (abs(a[i] - ed) > 2)
                flag  = 0 ;
        }
        if (!flag)
        {
            printf("NO\n");
            continue;
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ed)
                continue;
            if (a[i] < ed)
            {
                if (a[i] + 1 == ed)
                {
                    if (a[(i - 1 + n) % n] > a[(i + 1 + n) % n])
                    {
                        if (!vis[(i - 1 + n) % n])
                        {
                            vis[(i - 1 + n) % n] = 1;
                            a[i] = ed;
                            a[(i - 1 + n) % n]--;
                        }
                        else if (! vis[i])
                        {
                            vis[i] = -1;
                            a[i] = ed;
                            a[(i + 1 + n) % n]--;
                        }
                    }
                    else
                    {
                        if (!vis[i])
                        {
                            vis[i] = -1;
                            a[i] = ed;
                            a[(i + 1 + n) % n]--;
                        }
                        else if (!vis[(i - 1 + n) % n])
                        {
                            vis[(i - 1 + n) % n] = 1;
                            a[i] = ed;
                            a[(i - 1 + n) % n]--;
                        }
                    }
                }
                else if (a[i] + 2 == ed)
                {
                    if (!vis[(i - 1 + n) % n] && !vis[i])
                    {
                        a[i] = ed;
                        a[(i + 1 + n) % n]--;
                        a[(i - 1 + n) % n]--;
                        vis[(i - 1 + n) % n] = 1;
                        vis[i] = -1;
                    }
                }
            }
            else
            {
                if (a[i] - 1 == ed)
                {
                    if (a[(i - 1 + n) % n] >= a[(i + 1 + n) % n])
                    {
                        if (!vis[i])
                        {
                            a[(i + 1 + n) % n]++;
                            vis[i] = 1;
                            a[i] = ed;
                        }
                        else if (!vis[(i - 1 + n) % n])
                        {
                            a[(i - 1 + n) % n]++;
                            vis[(i - 1 + n) % n] = -1;
                            a[i] = ed;
                        }
                    }
                    else
                    {
                        if (!vis[(i - 1 + n) % n])
                        {
                            a[(i - 1 + n) % n]++;
                            vis[(i - 1 + n) % n] = -1;
                            a[i] = ed;
                        }
                        else if (!vis[i])
                        {
                            a[(i + 1 + n) % n]++;
                            vis[i] = 1;
                            a[i] = ed;
                        }
                    }
                }
                else  if (a[i] - 2 == ed)
                {
                    if (!vis[i] && !vis[(i - 1 + n) % n])
                    {
                        a[(i - 1 + n) % n]++;
                        a[(i + 1 + n) % n]++;
                        vis[i] = 1;
                        vis[(i - 1 + n) % n] = -1;
                        a[i] = ed;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            //  cout<<a[i]<<" ";
            if (a[i] != ed)
                flag = 0;
        }
        //  cout<<endl;
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (vis[i]) ans++;
        cout << ans << endl;
        int xx, yy;
        for (int i = 0; i < n; i++)
        {
//            if(vis[i])
//                cout<<i+1<<" "<<vis[i]<<endl;
            xx = i + 1;
            yy = i + 2;
            if (yy == n + 1)
                yy = 1;
            if (vis[i] == 1)

                printf("%d %d\n", xx, yy);
            else if (vis[i] == -1)
                printf("%d %d\n", yy, xx);
        }
    }
    return 0;
}