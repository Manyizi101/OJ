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

const int maxn = 60;

struct node
{
    int id;
    char dot,color;
} a[maxn];

int right[maxn],left[maxn];

void link(int L, int R)
{
    right[L]=R,left[R]=L;
}

int main()
{
    string tmp;
    while(cin>>tmp)
    {
        if(tmp=="#")    break;
        for(int i=0; i<=26; ++i)
        {
            scanf("%c%c", &a[i].dot, &a[i].color);
            getchar();
            a[i].id=i+1;
        }
    }
}

