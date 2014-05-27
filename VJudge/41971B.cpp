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



int main()
{
    int t,n;
    int i,j;
    cin>>t;

    while(t--)
    {
        cin>>n;
        string a[n];
        bool flag = true;
        for(i=0; i<n; i++)    cin>>a[i];
        for(i=0; i<n-1; i++)
        {
            for(j=i+1;j<n;j++)
            if(a[j].find(a[i])==0||a[i].find(a[j])==0)
            {
                flag = false;
                break;
            }
        }
        if(flag)    cout<<"YES\n";
        else    cout<<"NO"<<endl;
    }
    return 0;
}


/*
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<string> v;
        string s;

        cin>>n;
        v.clear();
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());

        bool flag = true;
        for(int i=0;i<n-1;i++)
        {
            if(v[i+1].find(v[i])==0)
            {
                flag=false;
                break;
            }
        }
        if(flag)    cout<<"YES\n";
        else    cout<<"NO"<<endl;
    }
    return 0;
}
**/
