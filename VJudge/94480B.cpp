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

const int maxn = 2e4+10;

int t,n;
string a[maxn];
int shang,xia;
int ji,ou,same;

int main()
{
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        shang=ji=ou=same=0;
        xia=n*(n-1)/2;
        for(int i=0; i<n; ++i) {
            cin>>a[i];
            if(a[i].size()&1)   ji++;
            else ou++;
        }
        sort(a,a+n);
        for(int i=1; i<n; ++i) {
            if(a[i]==a[i-1])    same++;
        }
        shang=ji*ou+same*(same-1)/2;
        if(shang==0) {
            printf("0/1\n");
            continue;
        }
        int g = __gcd(shang,xia);
        shang/=g,xia/=g;
        if(shang==xia&&xia==1) printf("1/1\n");
        else printf("%d/%d\n", shang,xia);
    }
}
