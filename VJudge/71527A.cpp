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

int n;
int flag=1;
int tmp=0;

void init()
{
	scanf("%d", &n);
}

int main(int argc, char const *argv[])
{
	init();
	tmp=2;
	for(int i=1;i<n;i++)
	{
		cout<<tmp<<' ';
		(tmp+i+1)%n==0?tmp=(tmp+i+1):tmp=(tmp+i+1)%n;
	}
	return 0;
}