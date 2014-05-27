
/*
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long int box[3],cost[3],aox[3],n;

int main()
{
    string ham;
    cin>>ham;
    memset(box,0,sizeof(box));
    memset(cost,0,sizeof(cost));
    memset(aox,0,sizeof(aox));
    for(int i=0; i<3; i++)    scanf("%I64d", &box[i]);
    for(int i=0; i<3; i++)    scanf("%I64d", &cost[i]);
    scanf("%I64d", &n);
    for(int i=0; i<(int)ham.size(); i++)
    {
        if(ham[i]=='B')   aox[0]++;
        else if(ham[i]=='S')   aox[1]++;
        else if(ham[i]=='C')   aox[2]++;
    }



    long long int ans=0;
    long long int right=10000000000000ll,left=0,mid;
    long long int d=0;
    while(left<=right)
    {
        mid=(right+left)/2;
        d=0;
        for(int i=0; i<3; i++)
        {
            if(mid*aox[i]>box[i])
            {
                d+=(mid*aox[i]-box[i])*cost[i];
            }
        }
        if(d>n)  right=mid-1;
        else
        {
            ans=mid;
            if(left!=mid) left=mid;
            else left=mid+1;
        }
    }
    printf("%I64d\n", ans);

    return 0;
}
**/


#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long int h[3],n[3],p[3],money;

int main()
{
    string ham;
    cin>>ham;
    memset(h,0,sizeof(h));
    memset(n,0,sizeof(n));
    memset(p,0,sizeof(p));
    for(int i=0; i<3; i++)    scanf("%I64d", &n[i]);
    for(int i=0; i<3; i++)    scanf("%I64d", &p[i]);
    scanf("%I64d", &money);
    for(int i=0; i<(int)ham.size(); i++)
    {
        if(ham[i]=='B')   h[0]++;
        else if(ham[i]=='S')   h[1]++;
        else if(ham[i]=='C')   h[2]++;
    }

    long long int ans=0;
    long long int right=10000000000000ll,left=0,mid=0;
    long long int cost=0;
    while(left<=right)
    {
        mid=(right+left)/2;
        cost=0;
        for(int i=0; i<3; i++)
        {
            if(mid*h[i]>n[i])
            {
                cost+=(mid*h[i]-n[i])*p[i];
            }
        }
        if(cost>money)  right=mid-1;
        else
        {
            ans=mid;
            if(left!=mid) left=mid;
            else left=mid+1;
        }
    }
    printf("%I64d\n", ans);

    return 0;
}
