#include  <stdio.h>
#include  <algorithm>
#include  <iostream>
#include  <string.h>
using namespace std;
int tree[50500];

int main()
{
    int n,k,i,ans=0,sum=0;
    int left,right,mid;

    scanf("%d%d", &n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d", &tree[i]);
        sum+=tree[i];
    }
    left = 0;
    right = sum/k+1;
    mid = right/2;

    while(left<=right)
    {
        ans=0;
        if(mid==0)
        {
            printf("0\n");
            return 0;
        }
        for(i=0; i<n; i++)    ans+=tree[i]/mid;
        if(ans>=k)
        {
            left=mid+1;
            mid=(right+left)/2;
        }
        else
        {
            right=mid-1;
            mid=(right+left)/2;
        }
    }
    printf("%d\n", mid);
    return 0;
}
