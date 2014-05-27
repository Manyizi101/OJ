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
    int m,n,k;
    int i;
    int num[1024];
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &n,&k);
        for(i=0; i<n; i++)    scanf("%d", &num[i]);
        if(next_permutation(num,num+n)==0)
        {
            for(i=0; i<n; i++)
            {
                cout<<num[i]<<' ';
            }
            cout<<endl;
        }
        else
        {
            prev_permutation(num,num+n);
            do
            {
                if(k==0)
                {
                    for(i=0; i<n; i++)
                    {
                        cout<<num[i]<<' ';
                    }
                    cout<<endl;
                    break;
                }
                k--;
            }
            while(next_permutation(num,num+n));
        }

    }
    return 0;
}
**/

/*469ms,168KB*/

#include<cstdio>
#include<algorithm>
using namespace std;

int num[1024];

int main()
{
    int m, n, k;
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", &num[i]);
        while (k--)
            next_permutation(num, num + n);
        printf("%d", num[0]);
        for (int i = 1; i < n; ++i)
            printf(" %d", num[i]);
        putchar('\n');
    }
    return 0;
}
