/*#include   <cstdio>
#include   <cstring>
using namespace std;

int  m,n,sum;
int  Map[500][500];
int  visited[500][500];

int dfs(int i,int j)
{
    if(!visited[i][j])
    {
        sum++;
        visited[i][j]=1;
        if(j+1<n)
            dfs(i,j+1);
        if(i+1<m)
            dfs(i+1,j);
        if(i-1>=0)
            dfs(i-1,j);
        if(j-1>=0)
            dfs(i,j-1);
    }
    return 0;
}

int main()
{
    sum=1;
    int i,j;
    scanf("%d%d", &m, &n);
    memset(visited,0,sizeof(visited));
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            scanf("%d", &Map[i][j]);
            if(Map[i][j]==0)    visited[i][j]=1;
        }
    }
    dfs(0,0);
    if(sum==m+n)
    {
        printf("Bingo");
        return 0;
    }
    printf("No way");
    return 0;
}**/

#include   <cstdio>
#include   <cstring>
using namespace std;

int  m,n;
int  Map[500][500];

int dfs(int i,int j)
{
    if(i == m - 1 && j == n - 1 )
    {
        Map[m-1][n-1] = 0 ;
        return 0;
    }
    if(Map[i][j])
    {
        Map[i][j]=0;
        if(j+1<n&&Map[i][j+1])
            dfs(i,j+1);
        if(i+1<m&&Map[i+1][j])
            dfs(i+1,j);
        if(i-1>=0&&Map[i-1][j])
            dfs(i-1,j);
        if(j-1>=0&&Map[i][j-1])
            dfs(i,j-1);
    }
    return 0;
}

int main()
{
    int i,j;
    scanf("%d%d", &m, &n);
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            scanf("%d", &Map[i][j]);
        }
    }
    dfs(0,0);
    if(!Map[m-1][n-1])
    {
        printf("Bingo");
        return 0;
    }
    printf("No way");
    return 0;
}
