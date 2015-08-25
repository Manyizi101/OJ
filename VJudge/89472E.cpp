#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 100005
using namespace std;

int num[N];
struct Tree
{
    int l;
    int r;
    int sum;
}tree[N * 4];

void build(int root,int l,int r)///rootΪ�ڵ� �˴�Ϊ���ڵ� 1 l��rΪ�߶ε���˵���Ҷ˵�
{
    tree[root].l = l;
    tree[root].r = r;
    if(tree[root].l == tree[root].r)
    {
        tree[root].sum = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(root << 1,l ,mid);
    build(root << 1|1,mid+1,r);
    tree[root].sum = tree[root << 1].sum + tree[root << 1|1].sum;///�˴����Ӧ�ø������ⲻͬ
}
void update(int root,int pos,int val)///�о��˴����ƻ��� ���ҵ���Ͳ� ������Ҫ���ֵȻ��һ��һ��ĵݹ�����
{
    if(tree[root].l == tree[root].r)///�ҵ���ײ����ֵ ����
    {
        tree[root].sum = val;
        return ;
    }
    int mid=(tree[root].l + tree[root].r) / 2;
    if(pos <= mid)
       update(root << 1,pos,val);
    else
        update(root << 1|1,pos,val);
    tree[root].sum = tree[root << 1].sum + tree[root << 1|1].sum;///����
}
int query(int root,int L,int R)///������ݹ�ͺ�
{
    if(L <= tree[root].l && R >= tree[root].r)
       return tree[root].sum;

    int mid = (tree[root].l + tree[root].r) / 2,ret = 0;

    if(L <= mid ) ret += query(root << 1,L,R);
    if(R > mid) ret += query(root << 1|1,L,R);
    return ret;
}
int main()
{
    int ca,cas = 1,n,Q,a,b;
    char str[10];
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i ++)
            scanf("%d",&num[i]);
        build(1,1,N);
        printf("Case %d:\n",cas++);
        while(scanf("%s",str),strcmp(str,"End"))
        {
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Query") == 0)
            {
                if(a > b) swap(a , b);
                printf("%d\n",query(1,a,b));
            }
            else if(strcmp(str,"Add") == 0)
            {
                num[a] = num[a] + b;
                update(1,a,num[a]);
            }
            else if(strcmp(str,"Sub") == 0)
            {
                num[a] = num[a] - b;
                update(1,a,num[a]);
            }
        }
    }
    return 0;
}
