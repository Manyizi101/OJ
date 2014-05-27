/*
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

int bin[30002];
int data[30002];

int getfather(int v)
{
    if (bin[v]==v)
      return v;
    else
    {
        bin[v]=getfather(bin[v]);
        return bin[v];
     }
}

void merge(int x, int y)
{
    int fx,fy;
    fx=getfather(x);
    fy=getfather(y);
    if(fx!=fy)
    {
        bin[fy]=fx;
    }
}

int main()
{
    int n,m,i,num,count;
    while(scanf("%d", &n))
    {
        for(i=1; i<=n; i++)
        {
            bin[i]=i;
        }
        scanf("%d",&m);
        if(n==0&&m==0)  break;
        for(; m>0; m--)
        {
            scanf("%d", &num);
            for(i=0; i<num; i++)
            {
                scanf("%d", &data[i]);
            }
            sort(data,data+num);
            for(i=1; i<num; i++)
            {
                merge(data[0],data[i]);
            }
        }
        for(count=1,i=1; i<=n; i++)
        {
            if(bin[i]==0)   count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
**/


#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

int bin[30002];
int data[30002];

int find(int x)
{
    int r=x;
    while(bin[r]!=r)
    {
        r=bin[r];
    }
    return r;
}


void merge(int x, int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if(fx!=fy)
    {
        bin[fy]=fx;
    }
}

int main()
{
    int n,m,i,num,count;
    while(scanf("%d", &n))
    {
        for(i=1; i<=n; i++)
        {
            bin[i]=i;
        }
        scanf("%d",&m);
        if(n==0&&m==0)  break;
        for(; m>0; m--)
        {
            scanf("%d", &num);
            for(i=0; i<num; i++)
            {
                scanf("%d", &data[i]);
            }
            sort(data,data+num);
            for(i=1; i<num; i++)
            {
                merge(data[0],data[i]);
            }
        }
        for(count=1,i=1; i<=n; i++)
        {
            if(find(0)==find(i))   count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
