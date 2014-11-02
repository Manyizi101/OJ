/*
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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int num[10]= {0,1,2,3,4,5,6,7,8,9};
int a[100][100],b[100][100];
int ans[100];
int n,x,y,tmp;

void init()
{
    memset(ans,0,sizeof(ans));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    do
    {
        x=num[0]*10000+num[1]*1000+num[2]*100+num[3]*10+num[4];
        y=num[5]*10000+num[6]*1000+num[7]*100+num[8]*10+num[9];
        if(x%y==0)
        {
            tmp=x/y;
            a[tmp][ans[tmp]]=x;
            b[tmp][ans[tmp]]=y;
            ans[tmp]++;
        }
    }
    while(next_permutation(num,num+10));
}

int main(int argc, char const *argv[])
{
    init();
    while(~scanf("%d", &n),n)
    {
        if(ans[n]==0)
            printf("There are no solutions for %d.\n\n", n);
        else
        {
            for(int i=0; i<ans[n]; i++)
            {
                printf("%05d / %05d =%d \n", a[n][i], b[n][i], n);
            }
            printf("\n");
        }
    }
    return 0;
}
**/


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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int x,y,n;

int main()
{
    while(scanf("%d", &n),n)
    {

    }
}
