#include  <stdio.h>

int jisuan(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    int T=0,n[21],x[21][101],y[21][101];
    int i=0,j=0,l=0,s=0,ans=0,bian[3],key=0,a=0,b=0;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &n[i]);
        for(j=0; j<n[i]; j++) scanf("%d%d", &x[i][j],&y[i][j]);
    }
    for(i=0; i<T; i++)
    {
        ans = 0;
        for(j=0; j<n[i]-2; j++)
        {
            for(l=j+1; l<n[i]-1; l++)
            {
                for(s=l+1; s<n[i]; s++)
                {
                    bian[0] = jisuan(x[i][j],y[i][j],x[i][l],y[i][l]);
                    bian[1] = jisuan(x[i][j],y[i][j],x[i][s],y[i][s]);
                    bian[2] = jisuan(x[i][l],y[i][l],x[i][s],y[i][s]);
                    for(a=0; a<3; a++)
                    {
                        for(b=2; b>a; b--)
                        {
                            if(bian[a]<bian[b])
                            {
                                key=bian[a];
                                bian[a]=bian[b];
                                bian[b]=key;
                            }
                        }
                    }
                    if(bian[1]+bian[2]>bian[0]) ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
