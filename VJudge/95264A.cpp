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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 110;
int t;
char a[maxn];

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%s", a);
        int len = strlen(a);
        for(int i=0; i<len; i+=2) printf("%c", a[i]);
        printf("\n");
        for(int i=len-1; i>=0; i-=2)  printf("%c", a[i]);
        printf("\n");
    }
}
