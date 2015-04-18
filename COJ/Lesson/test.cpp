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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1 << 31;
using namespace std;

int t;
string month[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int year1, year2, month1, month2, day1, day2;
int flag=0,ans=0;;

bool judge(int x)
{
    if (x % 4 == 0 && x % 100 != 0)    return true;
    else if (x % 400 == 0)   return true;
    else return false;
}

int cal(string m)
{
    for(int i=1;i<=12;i++)
    {
        if(!m.compare(month[i]))    return i;
    }
    return 0;
}

void init()
{
    ans=0;
    string m;
    cin>>m;
    getchar();
    cin>>day1;
    getchar();
    getchar();
    cin>>year1;
    month1=cal(m);
    cin>>m;
    getchar();
    cin>>day2;
    getchar();
    getchar();
    cin>>year2;
    month2=cal(m);
}

int main(int argc, char const *argv[])
{
    //freopen("test.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        cout<<"Case #"<<++flag<<": ";
        init();
        for(int i=year1;i<=year2;i++)
        {
            if(judge(i))    ans++;
        }
        if(judge(year1)&&month1>2)    ans--;
        if(judge(year2)&&month2<2)    ans--;
        if(judge(year2)&&month2==2&&day2!=29) ans--;
        //if(ans<0)   ans=0;
        cout<<ans<<endl;
    }
    return 0;
}