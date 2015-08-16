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
#define debug puts("-----")

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

using std::sort;
using std::vector;

//using namespace std;

const int NW = 1, NE = 2, SW=3, SE =4;
const int WHITE = 0, BLACK = 1;
const int NONE = -1;

const int T_MAXSIZE = 2*1e7;
const int T_NEXTSIZE = 4;

int node[T_MAXSIZE];
int next[T_MAXSIZE][T_NEXTSIZE];
int size = 0;

inline void init_node()
{
    size = 0;
}
inline int newnode()
{
    return size++;
}

int n;
char G_t[100][100];
int G[100][100],sum[100][100];

inline void init_G()    {}
inline void calG()
{
    for(int i=1; i<=n; ++i)
        for(int j=n; j>0; --j)    G[i][j]=G_t[i][j-1] -'0';
}
inline void calsum()
{
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)   sum[i][j] = G[i][j] + sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
}

bool same(const int &i1, const int &j1,const  int &i2, const int &j2)
{
    int d = sum[i2][j2]-sum[i1-1][j2]-sum[i2][j1-1]+sum[i1-1][j1-1];
    return d==0||d==(i2-i1+1)*(j2-j1+1);
}

int S[10000],S_t[10000],S_size;
vector<vector<int> > S_5;

inline void init_S()
{
    S_size = 0;
}
inline void push_back(const int &d)
{
    S[S_size++]=d;
}

inline void init(const bool &set0=false)
{
    init_node(),init_G(),init_S();
    if(set0)
    {
        n*=-1;
        memset(G,0,sizeof(G));
        S_5.clear();
    }
}

inline void build(const int &i1, const int &j1,const int i2,  const int &j2,const int &pt)
{
    if(same(i1,j1,i2,j2))   node[pt]=G[i1][j1];
    else
    {
        node[pt]=-1;
        int i_mid = (i1+i2)/2,j_mid = (j1+j2)/2;
        build(i1,j1,i_mid,j_mid,next[pt][0]=newnode());
        build(i1,j_mid+1,i_mid,j2,next[pt][1]=newnode());
        build(i_mid+1,j1,i2,j_mid,next[pt][2]=newnode());
        build(i_mid+1,j_mid+1,i2,j2,next[pt][3]=newnode());
    }
}

inline void dfs(const int &pt, const int &depth, const int &num)
{
    S_t[depth] = num;
    if(node[pt]==BLACK)
    {
        int d = 0;
        for(int i=depth; i>0; --i)    d= d*5+S_t[i];
        push_back(d);
    }
    else if(node[pt]==NONE)
    {
        dfs(next[pt][0],depth+1,NW);
        dfs(next[pt][1],depth+1,NE);
        dfs(next[pt][2],depth+1,SW);
        dfs(next[pt][3],depth+1,SE);
    }
}

inline void mode_G()
{
    init();
    for(int i=1; i<=n; ++i)   scanf("%s", G_t[i]);
    calG(),calsum();

    build(1,1,n,n,newnode());
    dfs(0,0,0);
    sort(S,S+S_size);

    if(S_size)
    {
        bool first = true;
        for(int i=0; i<S_size; ++i)
        {
            if(!(i%12)&&i!=0)
            {
                printf("\n");
                first = true;
            }
            if(first)   first = false;
            else printf(" ");
            printf("%d", S[i]);
        }
        printf("\n");
    }
    printf("Total number of black nodes = %d\n",S_size);
}

inline void paint(const int &i1, const int &j1, const int &i2, const int &j2)
{
    for(int i=i1; i<=i2; ++i)
        for(int j=j1; j<=j2; ++j) G[i][j]=1;
}

inline void mode_S()
{
    init(true);

    int d;
    while(~scanf("%d", &d)&&d!=-1)  push_back(d);

    for(int i=0; i!=S_size; ++i)
    {
        S_5.push_back(vector<int> ());
        while(S[i]>0)
        {
            S_5[i].push_back(S[i]%5);
            S[i]/=5;
        }
    }

    sort(S_5.begin(),S_5.end());

    for(int i=0; i!=S_size; ++i)
    {
        int i1=1,j1=1,i2=n,j2=n;

        for(int j=0; j!=S_5[i].size(); ++j)
        {
            int i_mid = (i1+i2)/2,j_mid = (j1+j2)/2;
            if(S_5[i][j]==1)    i2 = i_mid, j2=j_mid;
            if(S_5[i][j]==2)    i2 = i_mid, j1=j_mid +1;
            if(S_5[i][j]==3)    i1=i_mid +1, j2=j_mid;
            if(S_5[i][j]==4)    i1=i_mid+1,j1=j_mid +1;
        }

        paint(i1,j1,i2,j2);
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)   printf("%c", G[i][j]?'*':'.');
        printf("\n");
    }
}

int main()
{
    int T=0;
    while(~scanf("%d", &n)&&n)
    {
        if(T)   printf("\n");
        printf("Image %d\n", ++T);
        if(n>0) mode_G();
        else mode_S();
    }
}

