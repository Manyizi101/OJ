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
using namespace std;

int main()
{
	//freopen("1130H.in","r",stdin);
	//freopen("1130H.out","w",stdout);
    map<string,int> m;
    string ch;
    string sub[10000];
    cin>>ch;
    int ci=0;
    for(int i=0;i<ch.size();i++)
    {
        for(int j=i;j<ch.size();j++)
        {
            string temp=ch.substr(i,j-i+1);
            if(m[temp]==0)
            {
                sub[ci++]=temp;
            }
            m[temp]=1;
        }
    }
    int sum=0;
    for(int i=0;i<ci;i++)
    {
        if(ch.find(sub[i])!=ch.npos)
        {
           // cout<<sub[i]<<endl;
            int w=ch.find(sub[i]);
            if(ch.find(sub[i],w+sub[i].size())!=ch.npos)
            {
            //    cout<<sub[i]<<endl;
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}