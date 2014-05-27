#include  <cstdio>
#include  <algorithm>
#include  <cstring>
#include  <string>
#include  <queue>
#include  <iostream>
using namespace std;

int n,s,bian,i,endx,endy,visited[300][300];
int dir[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

struct node
{
    int x;
    int y;
    int s;
};



int bfs(node start)
{
    queue<node> q;
    q.push(start);
    while(!q.empty())
    {
        node temp= q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            node next;
            next.x=temp.x+dir[i][0];
            next.y=temp.y+dir[i][1];
            if(!visited[next.x][next.y]&&next.x>=0&&next.x<bian&&next.y>=0&&next.y<bian)
            {
                next.s=temp.s+1;
                if((next.x==endx)&&(next.y==endy))
                {
                    return next.s;
                }
                q.push(next);
                visited[next.x][next.y]=1;
            }
        }
    }
    return 0;
}

int main()
{
    queue<node> q;
node start;
    scanf("%d", &n);
    while(n--)
    {
        start.s=0;
        s=0;
        scanf("%d%d%d%d%d", &bian,&start.x,&start.y,&endx,&endy);
        memset(visited,0,sizeof(visited));
        visited[start.x][start.y]=1;
        if((start.x=endx)&&(start.y=endy))
        {
            printf("%d\n", s);
        }
        else
        {
            s=bfs(start);
            printf("%d\n", s);
        }
    }
    return 0;
}
