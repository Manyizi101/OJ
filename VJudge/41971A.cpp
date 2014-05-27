#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define sca(a) scanf("%d",&a)
#define pri(a) printf("%d\n",a)
#define MM 100005
#define MN 1005
#define INF 10000007

using namespace std;

typedef long long ll;


int main()
{
    char stick[400];
    memset(stick,'\0',sizeof(stick));
    int a=0,b=0,c=0,flag=0;
    int i=0;

    cin>>stick;

    for(i=0; i<400; i++)
    {
        if(stick[i]=='|')
        {
            a++;
        }
        if(stick[i]=='+')
        {
            flag=i;
            break;
        }
    }
    for(i=flag; i<400; i++)
    {
        if(stick[i]=='|')
        {
            b++;
        }
        if(stick[i]=='=')
        {
            flag=i;
            break;
        }
    }
    for(i=flag; i<400; i++)
    {
        if(stick[i]=='|')
        {
            c++;
        }
        if(stick[i]=='\0')
        {
            break;
        }
    }
    if(a+b-2==c)
    {
        if(a==1)
        {
            for(i=0; i<a; i++)    cout<<'|';
            cout<<'+';
            for(i=0; i<b-1; i++)    cout<<'|';
            cout<<'=';
            for(i=0; i<c+1; i++)    cout<<'|';
            cout<<endl;
        }
        else
        {
            for(i=0; i<a-1; i++)    cout<<'|';
            cout<<'+';
            for(i=0; i<b; i++)    cout<<'|';
            cout<<'=';
            for(i=0; i<c+1; i++)    cout<<'|';
            cout<<endl;
        }
    }
    else if(a+b+2==c)
    {
        for(i=0; i<a+1; i++)    cout<<'|';
        cout<<'+';
        for(i=0; i<b; i++)    cout<<'|';
        cout<<'=';
        for(i=0; i<c-1; i++)    cout<<'|';
        cout<<endl;
    }
    else if(a+b==c)
    {
        for(i=0; i<a; i++)    cout<<'|';
        cout<<'+';
        for(i=0; i<b; i++)    cout<<'|';
        cout<<'=';
        for(i=0; i<c; i++)    cout<<'|';
        cout<<endl;
    }
    else    cout<<"Impossible"<<endl;
    return 0;
}

/*
int main()
{
    string stick,str1,str2,str3;
    int a,b,c;

    cin>>stick;

    a=stick.find('+');
    str1=stick.substr(0,a);
    b=stick.find('=');
    str2=stick.substr(a+1,b);
    c=sizeof(stick);
    str3=stick.substr(b+1,c);
}
**/
