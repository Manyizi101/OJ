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
using namespace std;
typedef long long ll;
const int inf = 100000000;
const int N = 205;
char mp[N][N];
int n,m ,cnt;
int vis[N][N];
int id[N][N];
int x[N],y[N];
int dx1[] = {-1,1,-1,0};
int dy1[] = {0,0,0,-1};
int dx2[] = {0,0,0,1};
int dy2[] = {1,1,-1,0};
bool check()
{
    for(int i = 0; i<cnt; i++) {
        int tx = x[i],ty = y[i];
        if(!vis[tx][ty]) return false;
    }
    return true;
}
bool in(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&n+m!=0) {
        for(int i = 0 ;  i< n ; i++) scanf("%s",mp[i]);
        cnt = 0;
        for(int i = 0 ;  i< n ; i ++) {
            for(int j = 0; j<m; j++) {
                if(mp[i][j]=='.') {
                    id[i][j] = cnt;
                    x[cnt] = i,y[cnt++] = j;
                }
            }
        }
        int ans = inf;
        if(cnt==0) ans = 0;
        for(int i = 0 ; i<(1<<cnt); i++) {
            for(int j = 0; j<cnt; j++) {
                int num = 0;
                if( !(i & (1<<j)) ) continue;
                bool can = 1;
                memset(vis,0,sizeof(vis));
                num++;
                for(int k = 0; k<cnt; k++) {
                    if(k==j) continue;
                    if(i & (1<<k)) {
                        num ++ ;
                        int tx = x[k],ty = y[k];
                        vis[tx][ty] = 1;
                        if(tx-1>=0) {
                            if(mp[tx-1][ty]=='#') {
                                can = 0;
                                break;
                            } else vis[tx-1][ty] = 1;
                        }
                        if(ty+1<m) {
                            if(mp[tx][ty+1] =='#') {
                                can = 0;
                                break;
                            } else vis[tx][ty+1] = 1;
                        }
                    }
                }
                if(!can) continue;
                int tx = x[j],ty = y[j];
                vis[tx][ty] = 1;
                for(int k = 0; k<4; k++) {

                    int tx1 = dx1[k] + tx;
                    int ty1 = dy1[k] + ty;
                    int tx2 = dx2[k] + tx;
                    int ty2 = dy2[k] + ty;
                    int flag1 = 0,flag2= 0;
                    if(in(tx1,ty1)) {
                        if(!vis[tx1][ty1]) flag1 = 1;
                        if(mp[tx1][ty1]=='#') continue;
                        vis[tx1][ty1] = 1;
                    }
                    if(in(tx2,ty2)) {
                        if(!vis[tx2][ty2]) flag2 = 1;
                        if(mp[tx2][ty2]=='#') {
                            if(flag1) vis[tx1][ty1] = 0;
                            continue;
                        }
                        vis[tx2][ty2] = 1;
                    }
                    /*
                    for(int i = 0 ; i<n; i++) {
                        for(int j = 0; j<m; j++) {
                            cout<<vis[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                    **/
                    if(check()) ans = min(ans,num);
                    if(flag1) vis[tx1][ty1] = 0;
                    if(flag2) vis[tx2][ty2] = 0;
                }
            }
        }
        if(ans >= inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
