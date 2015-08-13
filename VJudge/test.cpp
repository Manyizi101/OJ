#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 2000100
#define Smaxn 26
using namespace std;
struct node
{
    node *par, *go[Smaxn];
    int flag;
    int num;
    int val;
}*root, *tail, que[maxn], *top[maxn];
int tot;
char str[maxn];
void add(int c, int l)
{
    node *p = tail, *np = &que[tot++];
    np->val = l;
    while (p && p->go[c] == NULL)
        p->go[c] = np, p = p->par;
    if (p == NULL) np->par = root;
    else
    {
        node *q = p->go[c];
        if (p->val + 1 == q->val) np->par = q;
        else
        {
            node *nq = &que[tot++];
            *nq = *q;
            nq->val = p->val + 1;
            np->par = q->par = nq;
            while (p && p->go[c] == q) p->go[c] = nq, p = p->par;
        }
    }
    tail = np;
}
int c[maxn], len;
void init()
{
    len = 1;
    tot = 0;
    memset(que, 0, sizeof(que));
    root = tail = &que[tot++];
}
char st[2000100];
void solve(int n)
{
    int i, j;
    memset(c, 0, sizeof(c));
    for (i = 0; i < tot; i++)
        c[que[i].val]++;
    for (i = 1; i < len; i++)
        c[i] += c[i - 1];
    for (i = 0; i < tot; i++)
        top[--c[que[i].val]] = &que[i];
    for (node *p = root;; p = p->go[str[p->val] - 'a'])
    {
        p->num = 1;
        if (p->val == len - 1)break;
    }
    for (i = tot - 1; i >= 0; i--)
    {
        node *p = top[i];
        if (p->par)
        {
            p->par->num += p->num;
        }
    }
    int tmp = 0;
    node *p = root;
    for (i = 1; i <= n; i++)
    {
        long long ans = 0;
        scanf("%s", st);
        int l = strlen(st);
        for (j = 0; j < l; j++)
        {
            int x = st[j] - 'a';
            if (p->go[x])
            {
                tmp++;
                p = p->go[x];
            }
            else
            {
                while (p && p->go[x] == NULL)
                    p = p->par;
                if (p)
                {
                    tmp = p->val + 1;
                    p = p->go[x];
                }
                else
                {
                    tmp = 0;
                    p = root;
                }
            }
            if (j >= l - 1 && tmp >= l)
            {
                node *q = p;
                while (1)
                {
                    if (l >= q->par->val + 1 && l <= q->val)
                        break;
                    q = q->par;
                }
                if (q->flag != i)
                {
                    ans += q->num;
                    q->flag = i;
                }
            }
        }
        printf("%I64d\n", ans);
    }
}

int main()
{
    //freopen("dd.txt", "r", stdin);
    scanf("%s", str);
    init();
    int i, l = strlen(str);
    for (i = 0; i < l; i++)
    {
        add(str[i] - 'a', len++);
    }
    int n;
    //scanf("%d", &n);
    solve(1);
    return 0;
}
