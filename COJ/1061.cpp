/*#include<cstdio>
#include<cstring>
using namespace std;

int x,y,sum;
int visited[50][50];
char Map[50][50];

int dfs(int i,int j)
{
	if(!visited[i][j])
	{
		sum++;
		visited[i][j]=1;
		if(j+1<y&&Map[i][j+1]==Map[i][j])
			dfs(i,j+1);
		if(i+1<x&&Map[i+1][j]==Map[i][j])
			dfs(i+1,j);
		if(i-1>=0&&Map[i-1][j]==Map[i][j])
			dfs(i-1,j);
		if(j-1>=0&&Map[i][j-1]==Map[i][j])
			dfs(i,j-1);
	}
	return 0;
}

int main()
{
	int i,j,Max;
	sum=Max=0;
	memset(visited,0,sizeof(visited));
	scanf("%d%d",&x,&y);
	for(i=0;i<x;i++)
		scanf("%s",Map[i]);
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			dfs(i,j);
			if(sum>Max)
				Max=sum;
			sum=0;
		}
	printf("%d\n",Max);
	return 0;
}**/


#include   <cstdio>
#include   <cstring>
using namespace std;

int x,y,sum;
char Map[50][50];
int visited[50][50];

int dfs(int i,int j)
{
    if(!visited[i][j])
    {
        sum++;
        visited[i][j]=1;
        if(j+1<y&&Map[i][j]==Map[i][j+1])   dfs(i,j+1);
        if(i-1>=0&&Map[i][j]==Map[i-1][j])  dfs(i-1,j);
        if(j-1>=0&&Map[i][j]==Map[i][j-1])  dfs(i,j-1);
        if(i+1<x&&Map[i][j]==Map[i+1][j])    dfs(i+1,j);
    }
    return 0;
}

int main()
{
    int i,j,Max;
    Max=sum=0;
    memset(visited,0,sizeof(visited));
    scanf("%d%d", &x,&y);
    for(i=0;i<x;i++)    scanf("%s", Map[i]);
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            dfs(i,j);
            if(sum>Max) Max=sum;
            sum=0;
        }
    }
    printf("%d\n", Max);
    return 0;
}

