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
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

int t,a,f;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while(t--)
    {
        scanf("%d%d", &a,&f);
        while(f--)
        {
            for(int i=1;i<=a;i++)
            {
                for(int j=1;j<=i;j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            for(int i=a-1;i>=1;i--)
            {
                for(int j=a-1;j>=a-i;j--)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
	return 0;
}
