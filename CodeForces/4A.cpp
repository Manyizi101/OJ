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

int w;

int main(int argc, char const *argv[])
{
    scanf("%d", &w);
	if(w==2)
        printf("NO\n");
    else
    {
        if(w%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
