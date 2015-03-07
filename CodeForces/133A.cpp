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

#define MAXN 110

char a[MAXN];

bool judge(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if(a[i]=='H'||a[i]=='Q'||a[i]=='9')	return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%s", a);
	if(judge(a))	cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}