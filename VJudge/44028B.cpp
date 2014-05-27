#include <cstdio>
#include <iostream>
#include <string.h>
#define MaxInt 1<<29

using namespace std;

int visited[101];
int low[101];
int map[101][101];
int n,m;

int prim()
{
    int i,j,pos,min,result=0;
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    pos=1;
    for(i=1;i<=n;i++)
        if(i!=pos) low[i]=map[pos][i];

    for(i=1;i<n;i++)
    {
        min=MaxInt;
        for(j=1;j<=n;j++)
            if(visited[j]==0&&min>low[j])
        {
            min=low[j];
            pos=j;
        }

        result+=min;
        visited[pos]=1;
        for(j=1;j<=n;j++)
        {
            if(visited[j]==0&&low[j]>map[pos][j])
                low[j]=map[pos][j];
        }
        return result;
    }
}

int main()
{

}
