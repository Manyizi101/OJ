#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int N = 1e5 + 100;
typedef pair<int, int > pii;
int d[N << 2];
int a[N];
pii b[N];
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
void pushup(int rt)
{
    d[rt] = gcd(d[rt << 1], d[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    if (l == r) {d[rt] = a[l]; return;}
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return d[rt];
    int m = (l + r) >> 1;
    int x, y;
    x = y = 0;
    if (L <= m) x = query(L, R, lson);
    if (R > m) y = query(L, R, rson);
    return gcd(x, y);
}

int main()
{
    int n, t;
    int l, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i].first = a[i], b[i].second = i;
    build(root);
    while (~scanf("%d%d", &l, &r))
        cout << query(l, r, root) << endl;

}