#include   <cstdio>
#include   <cstring>
using namespace std;

int W,H,sum;
char Map[20][20];
int  visited[20][20];

int dfs(int i,int j)
{
    if(!visited[i][j])
    {
        sum++;
        visited[i][j]=1;
        if(j+1<H&&Map[i][j+1]!='#')
            dfs(i,j+1);
        if(i+1<W&&Map[i+1][j]!='#')
            dfs(i+1,j);
        if(i-1>=0&&Map[i-1][j]!='#')
            dfs(i-1,j);
        if(j-1>=0&&Map[i][j-1]!='#')
            dfs(i,j-1);
    }
    return 0;
}

int main()
{
    int i,j;
    while(scanf("%d%d", &H, &W)&&(W!=0&&H!=0))
    {
        sum = 0;
        memset(visited,0,sizeof(visited));
        for(i=0; i<W; i++)    scanf("%s", Map[i]);
        for(i=0; i<W; i++)
        {
            for(j=0; j<H; j++)
            {
                if(Map[i][j]=='@')    dfs(i,j);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
