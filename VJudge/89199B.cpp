#include<iostream>
#include<iomanip>
#include<cstring>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<memory>
using namespace std;

const int e=100006;
struct qq
{
    int maxx,delta;
} tree[4*e]; //线段树要开4倍的点的个数

void updata(int l,int r,int root)//更新数据
{
    if(b<l || r<a)    return;

    if(l>=a && r<=b)//这句是核心，若当前区间包含于修改区间，就不往下传,(未传到叶子节点)；
    {
        tree[root].maxx++;
        tree[root].delta++;
        return;
    }

    int mid=(l+r)/2,delta=tree[root].delta;
    tree[root*2].maxx+=delta;
    tree[root*2].delta+=delta;
    tree[root*2+1].maxx+=delta;
    tree[root*2+1].delta+=delta;
    tree[root].delta=0;//这句很关键，根的偏移量传递到子树后清零
    updata(l,mid,root*2);
    updata(mid+1,r,root*2+1);
    tree[root].maxx=max( tree[root*2].maxx, tree[root*2+1].maxx);
    return;
}

int search(int l,int r,int root)
{
    if(l>b || r<a)    return(-99999999);

    if(l>=a && r<=b)    return(tree[root].maxx);

    int mid=(l+r)/2,delta=tree[root].delta;
    tree[root*2].maxx+=delta;
    tree[root*2].delta+=delta;
    tree[root*2+1].maxx+=delta;
    tree[root*2+1].delta+=delta;
    tree[root].delta=0;      //这句很关键，根的偏移量传递到子树后清零
    return(max( search(l,mid,root*2), search(mid+1,r,root*2+1)));
}

int t,n,x,y;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            updata(x,y,1);
        }
        printf("%d\n", search(1,1e9,1));
    }
    return 0;
}
