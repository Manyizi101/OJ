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

using namespace std;

/*
int main()
{
    int n;
    cin>>n;
    string can[n],party[n];
    for(int i=0;i<n;i++)
    {
        getline(cin,can[i]);
        getline(cin,party[i]);
    }
    int m;
    cin>>m;

    return 0;
}
**/




int main()
{
    map<string,string>m;
    map<string,int>mm;
    string sa,sb,sc;
    int i,n,t;
    cin>>n;
    getline(cin,sa);
    for(i=0;i<n;i++)
    {
           getline(cin,sa);
           getline(cin,sb);
           m[sa]=sb;
           mm[sa]=0;
    }
     cin>>t;
    getline(cin,sa);
    for(i=0;i<t;i++)
    {
            getline(cin,sa);
            if(m[sa].size()!=0)
              mm[sa]++;
    }
     map<string,int>::iterator it=mm.begin();
     sc=(*it).first;
    for(it++;it!=mm.end();it++)
    {
           if((*it).second>mm[sc])
              sc=(*it).first;
    }
    for(it=mm.begin();it!=mm.end();it++)
    {
          if((*it).second==mm[sc]&&(*it).first!=sc)
          {
             cout<<"tie"<<endl;
             return 0;
          }
    }
    //cout<<m[sc]<<endl;
    return 0;
}
