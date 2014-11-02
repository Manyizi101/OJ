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

#define MAXN 30+10

int sum,d,Max[MAXN],Min[MAXN];

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&d,&sum))
	{
		int Maxt=0,Mint=0;
		for(int i=0;i<d;i++)
		{
			scanf("%d %d",Min+i,Max+i);
			Mint+=Min[i];
			Maxt+=Max[i];
		}
		if(sum>=Mint&&sum<=Maxt)
		{
			puts("YES");
			int tem=Maxt-sum;
			for(int i=0;i<d;i++)
			{
				if(Max[i]-Min[i]<tem)
				{
					tem-=(Max[i]-Min[i]);
					Max[i]=Min[i];
				}
				else
				{
					Max[i]-=tem;
					break;
				}
			}
			for(int i=0;i<d;i++)
				if(i!=d-1)
				printf("%d ",Max[i]);
			    else
				printf("%d\n",Max[i]);
		}
		else
		{
			puts("NO");
		}
	}
}
