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
#define inf (1<<12)
#define ll long long int
using namespace std;

#define MAXN 1000+10

map<string, int> player;
vector<string> info_s;
vector<int> info_p;

#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;

int main()
{
    int n, m;
    vector<string> info_s;
    vector<int> info_p;
    map<string, int> pt, round;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        char s[40];
        int p;
        scanf("%s%d", s, &p);
        info_s.push_back(s);
        info_p.push_back(p);
        pt[s] += p;
    }
    m = -1;
    for(map<string, int>::iterator it=pt.begin(); it!=pt.end(); ++it)
        m = max(m, it->second);
    pt.clear();
    for(int i=0; i<n; ++i)
    {
        pt[info_s[i]] += info_p[i];
        if(pt[info_s[i]] >= m && round.find(info_s[i]) == round.end())
            round[info_s[i]] = i;
    }
    string sol;
    int k = n;
    for(map<string, int>::iterator it=round.begin(); it!=round.end(); ++it)
        if(pt[it->first]==m && k>it->second) k=it->second, sol=it->first;
    puts(sol.c_str());
    return 0;
}