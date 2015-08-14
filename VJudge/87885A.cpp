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

string a,b;

int main()
{
    while(cin>>a>>b)
    {
        string c;
        int j;
        for(int i=0; i<a.size(); ++i)
            if(a[i]=='_')
            {
                j=i+1;
                break;
            }
        for(; j<a.size(); ++j)
        {
            c+=a[j];
        }
        c+="_small_";
        for(int i=0; i<b.size(); ++i)
            if(b[i]=='_')
            {
                j=i+1;
                break;
            }
        for(; j<b.size(); ++j)
        {
            c+=b[j];
        }
        cout<<c<<endl;
    }
}

