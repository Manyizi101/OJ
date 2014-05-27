#include  <stdio.h>
#include  <stdlib.h>
#include  <algorithm>
#include  <iostream>

using namespace std;

int main()
{
    int n,m,a[10001];
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)  scanf("%d", &a[i]);
        while(m--)  next_permutation(a,a+n);
        for(int i=0;i<n;i++)
        {
            printf("%d", a[i]);
            if(i!=n-1)  printf(" ");
        }
        printf("\n");
    }
    return 0;
}
