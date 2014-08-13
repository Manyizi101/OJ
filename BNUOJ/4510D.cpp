#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
typedef long long ll;
#define pi acos(-1)
#define eps 1e-6;
using namespace std;
const int MAX = 1 << 28;

int  n,t;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
    	scanf("%d", &n);
    	printf("%d\n", (n*n*n+5*n+6)/6);
    }
    return 0;
}