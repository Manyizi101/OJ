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
#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 100+10

char tmp[MAXN],word[MAXN];
int n=0,ans=0;

int main()
{
    while(cin.getline(tmp,MAXN))
    {
        if(tmp[0]=='+') n++;
        else if(tmp[0]=='-')    n--;
        else
        {
            for(int i=0;i<strlen(tmp);i++)
            {
                if(tmp[i]==':')
                {
                    for(int j=i+1;j<strlen(tmp);j++)
                    {
                        word[j-i-1]=tmp[j];
                    }
                }
            }
        }
        ans+=strlen(word)*n;
        memset(word,0,sizeof(word));
        //cout<<debug<<word<<endl;
    }
    printf("%d\n", ans);
    return 0;
}
