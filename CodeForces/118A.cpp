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

#define MAXN 100+10

char a[MAXN];
char b[MAXN];
char vow[] = "aoyeuiAOYEUI";

bool judge(char x)
{
	for(int i=0;i<12;i++)
	{
		if(x==vow[i])	return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
    scanf("%s", a);
    int lena = strlen(a);
    int lenb=0;
    for (int i = 0; i < lena; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
        if(!judge(a[i]))	b[lenb++]=a[i];
    }
    for(int i=0;i<lenb;i++)
    {
    	cout<<'.'<<b[i];
    }
    return 0;
}