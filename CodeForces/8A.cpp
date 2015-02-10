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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 100000+10
#define MAXM 100+10

char s[MAXN],sa[MAXM],sb[MAXM];
int l,la,lb;
int i,j,k,n,ans=0,ans1,ans2;
char temp;

void init()
{
    scanf("%s",&s);
    scanf("%s",&sa);
    scanf("%s",&sb);
    la=strlen(sa);
    lb=strlen(sb);
    ans=0;
    k=0;
}

int Find(char str[MAXM],int start)
{
    int len=strlen(s),len1=strlen(str);
    int i,j,flag;
    for(i=start; i<=len-len1; i++)
    {
        flag=1;
        for(j=i; j<=i+len1-1; j++)
        {
            if(s[j]!=str[j-i])
            {
                flag=0;
                break;
            }
            if(flag)
                return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    init();
    ans1=Find(sa,0);
    if(ans1!=-1)
        k+=1;
    ans2=Find(sb,ans1+la);
    if(ans2!=-1)
        k+=1;
    if(k==2)
        ans+=1;
    l=strlen(s);
    for(i=0; i<=(l-1)/2; i++)
    {
        temp=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=temp;
    }
    k=0;
    ans1=Find(sa,0);
    if(ans1!=-1)
        k+=1;
    ans2=Find(sb,ans1+la);
    if(ans2!=-1)
        k+=1;
    if(k==2)
        ans+=2;
    switch(ans)
    {
    case 0:
        printf("fantasy\n");
        break;
    case 1:
        printf("forward\n");
        break;
    case 2:
        printf("backward\n");
        break;
    case 3:
        printf("both\n");
        break;
    default:
        break;
    }
    return 0;
}
