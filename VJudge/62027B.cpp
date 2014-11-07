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
#define eps (1e-4)
#define inf (1<<28)
#define ll long long int
using namespace std;
string tmp,a;
queue<string> word;
int Max,n=0;
int len,num=0;;
int main()
{
    while(getline(cin,tmp))
    {
        n++;
        if(Max<tmp.size())  Max=tmp.size();
        word.push(tmp);
    }
    for(int i=0; i<Max+2; i++)  printf("*");
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("*");
        a=word.front();
        word.pop();
        int l=Max-a.size();
        int s=l/2;
        if(l%2!=0)
        {
            num++;
            if(num%2!=0)
            {
                for(int j=0; j<s; j++)   printf(" ");
                cout<<a;
                for(int j=0; j<l-s; j++)   printf(" ");
                printf("*\n");
            }
            else
            {
                for(int j=0; j<l-s; j++)   printf(" ");
                cout<<a;
                for(int j=0; j<s; j++)   printf(" ");
                printf("*\n");
            }
        }
        else
        {
            for(int j=0; j<s; j++)   printf(" ");
            cout<<a;
            for(int j=0; j<l-s; j++)   printf(" ");
            printf("*\n");
        }
    }
    for(int i=0; i<Max+2; i++)  printf("*");
    return 0;
}
