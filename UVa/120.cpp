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

string str;

int main(int argc, char const *argv[])
{
    while(getline(cin,str))
    {
        cout<<str<<endl;
        istringstream iss(str);
        deque<int> que;
        for(int tmp; iss>>tmp; que.push_front(tmp));
        for(deque<int>::iterator it=que.begin(); it!=que.end(); ++it)
        {
            deque<int>::iterator Max = max_element(it, que.end());
            if(Max!=it)
            {
                if(Max != que.end()-1)
                {
                    reverse(Max, que.end());
                    cout<<distance(que.begin(), Max)+1<<' ';
                }
                reverse(it,que.end());
                cout<<distance(que.begin(),it)+1<<' ';
            }
        }
        cout<<"0\n";
    }
    return 0;
}
