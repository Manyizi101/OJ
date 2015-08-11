#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#define pb push_back
#define debug puts("=====================");
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long ll;
const int N  = 1000005;
const ll mod =  1000000007;
string ans;
char a[60];
int cnt[100];

string gao(ll x)
{
    string t;
    int tot = 0;
    while(x)
    {
        cnt[tot++] = x%10;
        x/=10;
    }
    for(int i=tot-1; i>=0; i--)
    {
        t += cnt[i]+'0';
    }
    return t;
}

int main ()
{
    int t,cs = 0;
    while(~scanf("%s%d",a,&t))
    {
        ans = a;
        int ttmp=t;
        while(t--)
        {
            int n = ans.size();
            ll sum = 0;
            for(int i=0; i<n; i++)
            {
                sum += ans[i] - '0';
            }
            string tmp = gao(sum);
            ans += tmp;
        }
        int n= ans.size();
        int ji = 0,ou = 0;
        for(int i=0; i<n; i++)
        {
            int x = ans[i]-'0';
            if(x%2==0) ou++;
            else ji++;
        }
        cout<<a<<" "<<ttmp<<" ";
        //printf("Case #%d: ",++cs);
        if(abs(ji-ou)%11==0)
        {
            puts("Yes");
        }
        else puts("No");
    }

    return 0;
}
