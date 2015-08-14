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

int flag;

string number1(int a)
{
    string tmp="";
    while(a!=0)
    {
        tmp+=a%2+'0';
        a/=2;
    }
    while(tmp.size()<5) tmp+='0';
    string ans="";
    for(int i=tmp.size()-1; i>=0; --i)    ans+=tmp[i];
    return ans;
}

int number2(string a)
{
    int ans=0;
    for(int i=0; i<a.size(); ++i)
    {
        ans=ans*2+a[i]-'0';
    }
    return ans;
}

string command1(string com)
{
    if(com=="ADD")  return "000001";
    else if(com=="SUB") return "000010";
    else if(com=="DIV") return "000011";
    else if(com=="MUL") return "000100";
    else if(com=="MOVE")    return "000101";
    else return "000110";
}

string command2(string com)
{
    if(com=="000001")  return "ADD";
    else if(com=="000010") return "SUB";
    else if(com=="000011") return "DIV";
    else if(com=="000100") return "MUL";
    else if(com=="000101")    return "MOVE";
    else return "SET";
}

bool judge(string com)
{
    int x = number2(com.substr(0,6));
    if(!(x==1||x==2||x==3||x==4||x==5||x==6))   return false;
    x  = number2(com.substr(6,5));
    if(!(1<=x&&x<=31))  return false;
    if(command2(com.substr(0,6))=="SET")
    {
        x = number2(com.substr(11,5));
        if(x>0)  return false;
    }
    else
    {
        x = number2(com.substr(11,5));
        if(!(1<=x&&x<=31))  return false;
    }
    return true;
}

void ctob()
{
    string com,ans="";
    int a,b;
    cin>>com;
    if(com=="SET")
    {
        char x;
        getchar();
        scanf("%c%d", &x,&a);
        ans+=command1(com);
        ans+=number1(a);
        ans+="00000";
        cout<<ans<<endl;
    }
    else
    {
        char x;
        getchar();
        scanf("%c%d%c%c%d", &x,&a,&x,&x,&b);
        ans+=command1(com);
        ans+=number1(a);
        ans+=number1(b);
        cout<<ans<<endl;
    }
}

void btoc()
{
    string com,ans="";
    cin>>com;
    if(judge(com))
    {
        ans+=command2(com.substr(0,6));
        if(ans=="SET")
        {
            ans+=" R";
            cout<<ans;
            cout<<number2(com.substr(6,5))<<endl;
        }
        else
        {
            cout<<ans<<" R";
            cout<<number2(com.substr(6,5));
            cout<<",R";
            cout<<number2(com.substr(11,5));
            cout<<endl;
        }
    }
    else
    {
        cout<<"Error!"<<endl;
    }
}

int main()
{
    while(~scanf("%d", &flag))
    {
        if(flag)
        {
            ctob();
        }
        else
        {
            btoc();
        }
    }
}

