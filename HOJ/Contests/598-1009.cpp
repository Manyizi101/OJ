#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;

int t;
char a[110000];
char b[110000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        //  cout<<a<<" "<<b<<endl;
        if(a[0]!=b[0])
        {
            printf("No\n");
            continue;
        }
        if(strlen(a)==strlen(b))
        {
            if(strcmp(a,b)==0)
            {
                printf("Yes\n");

            }
            else
            {
                printf("No\n");
            }
            continue;
        }
        int visa = 1;
        int visb = 0;

        int lena = strlen(a);
        int lenb = strlen(b);
        int j = lenb-1;
        for(int i  = lena-1; i>=1&&j>=1 ; )
        {
            if(a[i]==b[j])
            {
                if(j==1)
                    visb = 1;
                visa++;
                j--;
                i--;
            }
            else
                j--;
        }
        if(visa!=lena)
        {
            printf("No\n");
            continue;
        }
        if(visb==0)
        {
            if(b[0]==b[1])
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
            printf("Yes\n");
    }
    return 0;
}
