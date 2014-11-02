#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 16100000

int a[4][4444],n,t;
int num1[MAXN],num2[MAXN],c;
int i,j,ans,casen=0;


int bin(int left,int right,int k)
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        int num=0;
        if(num2[mid]==k)
        {
            num=1;
            for(i=mid-1; i>=0&&num2[i]==k; i--)  num++;
            for(i=mid+1; i<n*n&&num2[i]==k; i++)  num++;
            return num;
        }
        else if(num2[mid]>k)
            right=mid-1;
        else left=mid+1;
    }
    return 0;
}

void init()
{
    scanf("%d",&n);
    ans=0;
    c=0;
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d %d",&a[0][i],&a[1][i],&a[2][i],&a[3][i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            num1[c]=a[2][i]+a[3][j];
            num2[c++]=-(a[0][i]+a[1][j]);
        }
    }
    sort(num2,num2+c);
}

int main(int argc, char const *argv[])
{
    int i,j;
    scanf("%d", &t);
    while(t--)
    {
        casen++;
        if(casen>1) printf("\n");
        init();
        for(i=0; i<c; i++)
        {
            ans+=bin(0,n*n-1,num1[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
