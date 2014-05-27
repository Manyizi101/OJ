#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n,i;
    while(scanf("%d", &n)!=0)
    {
        int prime[n];
        memset(prime, 0, sizeof(prime));
        for(i=4;i<n;i+=2)
        {
            prime[i]=1;
            for(j=i+i;j<n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
