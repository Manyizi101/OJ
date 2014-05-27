/*
#include <iostream>
#include <vector>
using namespace std;

const int N = 101;
int a[N][N], p[N][N];

int MaxRecSum(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        p[i][0] = 0;
        p[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
    }

    int max = -100000000;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            int sum = 0;
            for (int k = 1; k <= n; ++k)
            {
                int temp = p[j][k] - p[j][k-1] - p[i-1][k] + p[i-1][k-1];
                if (sum > 0)
                    sum += temp;
                else
                    sum = temp;
                if (sum > max)
                    max = sum;
            }
        }
    }
    return max;
}

int main()
{
    int n = 4;
    int num;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> num;
            a[i][j] = num;
        }
    }

    cout << MaxRecSum(n) << endl;
    return 0;
}
**/


#include <iostream>
#include <stdio.h>
using namespace std;
int map[105][105];
int main()
{
    int n,i,j,k,sum,x,max;
    scanf("%d",&n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",&x);
            map[i][j]=map[i-1][j]+x;
        }
    max=-0x4f4f4f4f;
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            sum=0;
            for(k=0; k<n; k++)
            {
                sum+=map[j][k]-map[i][k];
                if(sum<0)
                    sum=0;
                if(sum>max)
                    max=sum;


            }
        }
    printf("%d\n",max);


    return 0;
}
