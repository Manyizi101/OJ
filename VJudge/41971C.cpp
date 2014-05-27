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

/*
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a=0,e=0,i=0,o=0,u=0;
        char str[100];
        cin.get(str,100);
        cout<<str<<endl;
        //cout<<"a:"<<a<<endl;
        //cout<<"e:"<<e<<endl;
        //cout<<"i:"<<i<<endl;
        //cout<<"o:"<<o<<endl;
        //cout<<"u:"<<u<<endl;
        //if(n!=1)    cout<<endl;
    }

    return 0;
}
**/

int main()
{
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        int a=0,e=0,i=0,o=0,u=0;
        int x;
        char str[110];
        gets(str);
        for(x=0;str[x]!='\0';x++)
        {
            if(str[x]=='a') a++;
            if(str[x]=='e') e++;
            if(str[x]=='i') i++;
            if(str[x]=='o') o++;
            if(str[x]=='u') u++;
        }
        cout<<"a:"<<a<<endl;
        cout<<"e:"<<e<<endl;
        cout<<"i:"<<i<<endl;
        cout<<"o:"<<o<<endl;
        cout<<"u:"<<u<<endl;
        if(n!=0)    cout<<endl;

    }
    return 0;
}

