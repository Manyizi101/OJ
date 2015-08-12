#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = int(2e5) + 10;
typedef long long LL;

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
int wa[N], wb[N], ws[N], wv[N];
int height[N], rank[N];

void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb;
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < m; i++) ws[i] = 0;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < n; i++) ws[wv[i]]++;
        for (i = 1; i < m; i++) ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for (swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}
void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for (i = 1; i <= n; i++) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k )
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[j + k] == r[i + k]; k++);
}

int n, n1, n2, K;
int sa[N], r[N];
char s1[N], s2[N];

int h[N], na[N], nb[N], S[N];

void solve() {
    for (int i = 2; i <= n; i++)
        h[i] = max(0, height[i] - K + 1);
    LL ans = 0, w1 = 0, w2 = 0;
    int top = 0;
    for (int i = 2; i <= n; i++)
    {
        S[++top] = h[i];
        if ( sa[i - 1] <= n1 ) na[top] = 1, nb[top] = 0, w1 += h[i];
        else na[top] = 0, nb[top] = 1, w2 += h[i];
        while ( (top > 1) && (S[top] <= S[top - 1]) ) {
            w1 -= na[top - 1] * (S[top - 1] - S[top]);
            w2 -= nb[top - 1] * (S[top - 1] - S[top]);
            na[top - 1] += na[top]; nb[top - 1] += nb[top];
            S[top - 1] = S[top];
            top--;
        }
        if ( sa[i] <= n1 ) ans += w2;
        else ans += w1;
    }
    printf("%lld\n", ans);
}
int main() {
    while ( scanf("%d", &K), K)
    {
        scanf("%s%s", s1, s2);
        n1 = strlen(s1); n2 = strlen(s2);
        for (int i =  0; i < n1; i++)
            r[i] = (int)s1[i];
        r[n1] = 1;
        for (int i = 0; i < n2; i++)
            r[n1 + 1 + i] = (int)s2[i];
        r[n = n1 + n2 + 1] = 0;

        da(r, sa, n + 1, 128);
        calheight(r, sa, n);
        solve();
    }
    return 0;
}