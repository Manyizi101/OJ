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

#define MAXN 

int t;
char a[100000];

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
	{
		int x=0,y=0;
		int n=0;
		/*
		getchar();
		while(~scanf("%c", &a)&&a!='\n')
		{
			n++;
			if((n%2==1&&a=='-')||(n%2==0&&a=='+'))	x++;
			else y++;	
		}
		**/
		scanf("%s", a);
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if((i%2==1&&a[i]=='-')||(i%2==0&&a[i]=='+'))	x++;
			else y++;	
		}
		cout<<min(x,y)<<endl;
	}
	return 0;
}
