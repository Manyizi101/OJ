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

int  a[4][4];
int ans[8];
int num1=0,num2=0;
char tmp;
int flag=0;
int ans1=0,ans2=0;

int main(int argc, char const *argv[])
{
    memset(ans,1,sizeof(ans));
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            scanf("%c", &tmp);
            if(tmp=='X')
            {
                a[i][j]=1;
                num1++;
            }
            else if(tmp=='0')
            {
                a[i][j]=2;
                num2++;
            }
            else a[i][j]=0;
        }
        getchar();
    }
    ans[0]=a[1][1]*a[1][2]*a[1][3];
    ans[1]=a[2][1]*a[2][2]*a[2][3];
    ans[2]=a[3][1]*a[3][2]*a[3][3];
    ans[3]=a[1][1]*a[2][1]*a[3][1];
    ans[4]=a[1][2]*a[2][2]*a[3][2];
    ans[5]=a[1][3]*a[2][3]*a[3][3];
    ans[6]=a[1][1]*a[2][2]*a[3][3];
    ans[7]=a[3][1]*a[2][2]*a[1][3];

    for(int i=0; i<8; i++)
    {
        if(ans[i]==1)   ans1++;
        if(ans[i]==8)   ans2++;
    }

    if(num1-num2==1)
    {
        if(ans1>=1)
        {
            printf("the first player won\n");
            return 0;
        }
        else
        {
            printf("second\n");
            return 0;
        }
    }
    else if(num1-num2==0)
    {
        if(ans2>=1)
        {
            printf("the second player won\n");
            return 0;
        }
        else
        {
            printf("first\n");
            return 0;
        }
    }
    else if(num1+num2==9)
    {
        printf("draw\n");
        return 0;
    }
    else
    {
        printf("illegal\n");
        return 0;
    }
    return 0;
}
