#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

int n,i,endx,endy,s,l;
int visited[310][310];
int direct[8][2]= {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};

struct node
{
    int x;
    int y;
    int s;
};

bool inside(int x, int y)
{
    if ( (x<0) || (x>l-1) || (y<0) || (y>l-1) )
        return false;
    else return true;
}

int main()
{
    int find(node start);
    queue<node> q;
    node start;
    cin>>n;
    while (n--)
    {
        start.s=0;
        cin>>l;
        s=0;
        cin>>start.x>>start.y;
        cin>>endx>>endy;
        memset(visited,0,sizeof(visited));
        visited[start.x][start.y]=1;
        if ( (start.x==endx) && (start.y==endy) )
            cout<<s<<endl;
        else
        {
            s=find(start);
            cout<<s<<endl;
        }
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
        for (i=0; i<8; i++)
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
}
