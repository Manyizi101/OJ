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
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 5010

int n;
int i,j;

struct Node
{
    int l, r, id;
    friend bool operator<(const Node& a, const Node&b)
    {
        if(a.l != b.l) return a.l > b.l;
        return a.r > b.r;
    }
} arr1[MAXN], arr2[MAXN];
int ans[MAXN][2];

bool check(Node* arr, int pos)
{
    priority_queue<Node>Q;
    for(int i=0; i<n; ++i) Q.push(arr[i]);
    int maxx=0;
    while(!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        if(tmp.r < maxx) return false;
        if(tmp.l < maxx)
        {
            tmp.l=maxx;
            Q.push(tmp);
            continue;
        }
        int cur = max(maxx, tmp.l);
        ans[tmp.id][pos] = cur;
        maxx = cur+1;
    }
    return true;
}

int main(int argc, char const *argv[])
{

    while(scanf("%d", &n) && n)
    {
        for(i=0; i<n; ++i)
        {
            scanf("%d%d%d%d",&arr1[i].l,&arr2[i].l,&arr1[i].r,&arr2[i].r);
            arr1[i].id = arr2[i].id = i;
        }

        if(check(arr1,0) && check(arr2,1))
        {
            for(i=0; i<n; ++i)
                printf("%d %d\n", ans[i][0], ans[i][1]);
        }
        else
        {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
