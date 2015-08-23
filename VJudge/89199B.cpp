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
} tree[4*e]; //�߶���Ҫ��4���ĵ�ĸ���

void updata(int l,int r,int root)//��������
{
    if(b<l || r<a)    return;

    if(l>=a && r<=b)//����Ǻ��ģ�����ǰ����������޸����䣬�Ͳ����´�,(δ����Ҷ�ӽڵ�)��
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
    tree[root].delta=0;//���ܹؼ�������ƫ�������ݵ�����������
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
    tree[root].delta=0;      //���ܹؼ�������ƫ�������ݵ�����������
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
