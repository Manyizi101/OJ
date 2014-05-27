#include  <cstdio>
#include  <cstring>
using namespace std;

int x,y,i,j,ans;
char Map[100][100];
int visited[100][100];

int dfs(int i, int j)
{
    if(!visited[i][j]&&Map[i][j]=='W')
    {
        visited[i][j]=1;
        if(j+1<y&&Map[i][j+1]=='W')     dfs(i,j+1);
        if(j+1<y&&i-1>=0&&Map[i-1][j+1]=='W')    dfs(i-1,j+1);
        if(i-1>=0&&Map[i-1][j]=='W')    dfs(i-1,j);
        if(i-1>=0&&j-1>=0&&Map[i-1][j-1]=='W')   dfs(i-1,j-1);
        if(j-1>=0&&Map[i][j-1]=='W')     dfs(i,j-1);
        if(j-1>=0&&i+1<x&&Map[i+1][j-1]=='W')     dfs(i+1,j-1);
        if(i+1<x&&Map[i+1][j]=='W')      dfs(i+1,j);
        if(i+1<x&&j+1<y&&Map[i+1][j+1]=='W')     dfs(i+1,j+1);
    }
    return 0;
}

int main()
{
    scanf("%d%d", &x, &y);

    ans=0;
    memset(visited, 0, sizeof(visited));
    for(i=0; i<x; i++)    scanf("%s", Map[i]);
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            if(Map[i][j] == 'W' && !visited[i][j])
            {
                dfs(i,j);
                ans ++ ;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
