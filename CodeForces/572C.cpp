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

struct cmps
{
    bool operator() (const int P1, const int P2)
    {
        return P1 > P2;
    }
};

struct cmpb
{
    bool operator() (const int P1, const int P2)
    {
        return P1 < P2;
    }
};

int n,s;
char d;
int p,q;

int main()
{
    map<int, int, cmpb> mps;
    map<int, int, cmps> mpb;
    while(~scanf("%d%d", &n,&s))
    {
        mps.clear();
        mpb.clear();
        for(int i=0; i<n; ++i)
        {
            getchar();
            scanf("%c %d %d", &d, &p, &q);
            if(d=='S')  mps[p]+=q;
            else if(d=='B') mpb[p]+=q;
        }
        auto it = mps.begin();
        int tmp = s;
        stack<pair<int ,int > > st;
        while(it!=mps.end()&&tmp)
        {
            st.push(make_pair((*it).first,(*it).second));
            tmp--;
            ++it;
        }
        while(!st.empty())
        {
            auto x = st.top();
            st.pop();
            cout<<'S' <<" "<<x.first<<" "<<x.second<<endl;
        }
        it = mpb.begin();
        tmp = s;
        while(it!=mpb.end()&&tmp)
        {
            cout<<'B'<<" "<<(*it).first<<" "<<(*it).second<<endl;
            tmp--;
            ++it;
        }
    }
}
