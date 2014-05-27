#include  <cstdio>
#include  <algorithm>
#include  <cstring>
#include  <string>
#include  <queue>
#include  <iostream>
using namespace std;

int i,endx,endy,s,m,n;
int visited[500][500];
int direct[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

struct node
{
    int x;
    int y;
    int s;
};

bool inside(int x, int y)
{
    if ( (x<0) || (x>m-1) || (y<0) || (y>n-1) )
        return false;
    else return true;
}

int main()
{
    int find(node start);
    queue<node> q;
    node start;
    start.s=0;
    scanf("%d%d", &m,&n);
    s=0;
    start.x=start.y=0;
    cin>>endx>>endy;
    memset(visited,0,sizeof(visited));
    visited[start.x][start.y]=1;
    if ( (start.x==endx) && (start.y==endy) )
        printf("Bingo\n");
    else
    {
        s=find(start);
        if(s!=-1)   printf("Bingo\n");
        if(s==-1)   printf("No way\n");
    }
    return 0;
}

int find(node start)
{
    queue<node> q;

    q.push(start);
    while (!q.empty())
    {
        node temp=q.front();
        q.pop();
        for (i=0; i<4; i++)
        {
            node next;
            next.x=temp.x+direct[i][0];
            next.y=temp.y+direct[i][1];
            if ( (inside(next.x, next.y)) && (visited[next.x][next.y]==0) )
            {
                next.s=temp.s+1;
                if ( (next.x==endx) && (next.y==endy) )
                {
                    return next.s;
                }
                q.push(next);
                visited[next.x][next.y]=1;
            }
        }
    }
    return -1;
}
