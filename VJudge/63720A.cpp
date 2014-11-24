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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

char a[3][3];

void init()
{
    scanf("%s", a[0]);
    scanf("%s", a[1]);
    scanf("%s", a[2]);
}

int main(int argc, char const *argv[])
{
	init();
	if(a[0][0]==a[2][2]&&a[0][1]==a[2][1]&&a[0][2]==a[2][0]&&a[1][0]==a[1][2])  printf("YES\n");
	else printf("NO\n");
	return 0;
}

