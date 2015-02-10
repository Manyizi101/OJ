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
#define MAXN 40000

int t;
char str[MAXN],ans[MAXN];

bool judge(char str[])
{
    string tmp=str;
    if(tmp.find('C')>=tmp.size()||tmp.find('R')>=tmp.size()||tmp.find('C')<tmp.find('R'))    return true;
    else
    {
        for(int i=tmp.find('R'); i<=tmp.find('C'); i++)
        {
            if(str[i]<='9') return false;
        }
        return true;
    }
    return false;
}

void exceltorxcy(char str[])
{
    int r=0,c=0;
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            c=c*26+str[i]-'A'+1;
        }
        else
        {
            r=r*10+str[i]-'0';
        }
    }
    printf("R%dC%d\n", r,c);
}

void rxcytoexcel(char str[])
{
    int i,j,c=0,r=0;
    int len=strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i]=='C')    break;
        if(str[i]>='0'&&str[i]<='9')
        {
            r=r*10+str[i]-'0';
        }
    }
    for(j=i; j<len; j++)
    {
        if(str[j]>='0'&&str[j]<='9')
        {
            c=c*10+str[j]-'0';
        }
    }
    i=0;
    while(c/26!=0)
    {
        if(c%26==0)
        {
            ans[i]='Z';
            c-=1;
        }
        else
        {
            ans[i]=c%26+'A'-1;
        }
        c/=26;
        i++;
    }
    ans[i]=c%26+'A'-1;
    for(; i>=0; i--)
    {
        if(ans[i]!='@')
            printf("%c", ans[i]);
    }
    printf("%d\n", r);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        scanf("%s", str);
        if(judge(str))  exceltorxcy(str);
        else    rxcytoexcel(str);
    }
    return 0;
}

/*
R228C494
RZ228
R98C688

**/
