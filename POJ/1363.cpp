#include <cstdio>
#include <stack>
using namespace std;
const int maxn=1000+5;
int a[maxn];

int main(int argc, char const *argv[])
{
    int n,i,k;
    while(scanf("%d",&n)&&n)
    {
        stack<int>s;
        while(scanf("%d",&a[0])&&a[0])
        {
            for(i=1;i<n;i++)
                scanf("%d",&a[i]);
            for(i=1,k=0;i<=n;i++)
            {
                s.push(i);
                while(s.top()==a[k])
                {
                    if(!s.empty()) s.pop();
                    k++;
                    if(s.empty()) break;
                }
            }
            if(k==n) printf("Yes\n");
           else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
