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
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

char a[10];
int sx,sy,ex,ey;
int ans;
int mx,my;

void init()
{
    gets(a);
    sx=a[0]-'a'+1;
    sy=a[1]-'0';
    gets(a);
    ex=a[0]-'a'+1;
    ey=a[1]-'0';
    mx=ex-sx;
    my=ey-sy;
}

int main(int argc, char const *argv[])
{
    init();
    ans=max(abs(mx),abs(my));
    printf("%d\n", ans);
    while(mx*my!=0)
    {
        if(mx>0&&my>0)
        {
            printf("RU\n");
            mx--;
            my--;
        }
        else if(mx>0&&my<0)
        {
            printf("RD\n");
            mx--;
            my++;
        }
        else if(mx<0&&my>0)
        {
            printf("LU\n");
            mx++;
            my--;
        }
        else
        {
            printf("LD\n");
            mx++;
            my++;
        }
    }
    if(mx>0)
    {
        while(mx>0)
        {
            printf("R\n");
            mx--;
        }
    }
    else if(mx<0)
    {
        while(mx<0)
        {
            printf("L\n");
            mx++;
        }
    }
    else if(my>0)
    {
        while(my>0)
        {
            printf("U\n");
            my--;
        }
    }
    else
    {
        while(my<0)
        {
            printf("D\n");
            my++;
        }
    }
	return 0;
}
