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

int s[25000];
int stmp[25000];
int o[25000];
int main()
{
    s[0]=0;
    for(int i=1; i<=17000; i++)
        s[i]=s[i-1]+i;
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int tmp=upper_bound(s,s+17000,n)-s-1;
    	//cout<<tmp<<endl;
    	int ans=inf;
    	for(int i=0;i<=tmp;i++)
    	{
    		int a,b;
    		a=n-s[i];
    		int yu=upper_bound(s,s+tmp+1,a)-s-1;
    		b=a-s[yu];
    		int sheng=upper_bound(s,s+tmp+1,b)-s-1;
    		if(b==s[sheng])
    		{
    			int tt=3;
    			if(i==0)
    				tt--;
    			if(yu==0)
    				tt--;
    			if(sheng==0)
    				tt--;
    			if(tt<ans)
    			{
    				ans=tt;
    				o[0]=i;
    				o[1]=yu;
    				o[2]=sheng;
    			}
    		}
    	}
    	for(int i=0;i<3;i++)
    	{
    		if(o[i])
    			cout<<o[i]<<" ";
    	}
    	cout<<endl;
    }
    
    return 0;
}
