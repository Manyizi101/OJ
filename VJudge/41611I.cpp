#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main()
{
    int n, k, m;
    int i,j,x,y;
    scanf("%d%d%d", &n, &k, &m);
    int A[n][n];
    int B[n][n];
    memset(B,0,sizeof(B));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(x=0;x<n;x++)
            {
                for(y=0;y<n;y++)
                {
                    B[i][j]+=A[i][x]*B[j][y];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
