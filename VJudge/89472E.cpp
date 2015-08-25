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
}tree[N * 4 *2];

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
    int ca,n,a,b,m;
    int sum=0,flag;
    char str[10];
    char tmp[N];
    scanf("%d",&ca);
    while(ca--)
    {
        sum=0;
        scanf("%s",tmp);
        int n = strlen(tmp);
        for(int i = 1;i <= n;i++)
        {
            num[i]=tmp[i-1]-'0';
            if(i&1) sum+=num[i];
            else sum-=num[i];
        }
        for(int i=n+1;i<=2*n;i++)
        {
            num[i]=num[i-n];
        }
        sum*=2;
        build(1,1,2*N);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",str);
            scanf("%d%d",&a,&b);
            if(strcmp(str,"2") == 0)
            {
                if(a > b) swap(a , b);
                int len = b-a;
                int x = len/(2*n);
                b = b - x*2*n;
                int k = a/n;
                a -= k*n;
                b -= k*n;
                if(b<a) b+=n;
                int ans =query(1,a,b);
                if(((a+k*n)&1)!=(a&1))  ans=-ans;
                ans+=x*sum;
                printf("%d\n",ans);
            }
            else if(strcmp(str,"1") == 0)
            {
                if(a&1) sum=sum-num[a]+b;
                else sum=sum+num[a]-b;
                num[a] = b;
                update(1,a,num[a]);
            }
        }
    }
    return 0;
}
