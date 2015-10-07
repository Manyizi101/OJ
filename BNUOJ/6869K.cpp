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
#include <queue>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
using namespace std;
typedef long long LL;
const int MAX = 110;
const int N = 10010;
const double eps = 1e-8;
int n;
struct node
{
    LL x,y;
} a[6];
double dis(node a,node b)
{
    return sqrt(1.0*(a.x - b.x)*(a.x - b.x) + 1.0*(a.y - b.y)*(a.y - b.y));
}
double len(node a)
{
    return sqrt(1.0*a.x*a.x + 1.0*a.y*a.y);
}
bool is_ping()
{

   node t[5] ;
   t[0].x = a[1].x - a[0].x ,t[0].y = a[1].y - a[0].y;
   t[1].x = a[2].x - a[3].x,t[1].y = a[2].y - a[3].y;
   if(t[0].x*t[1].y - t[1].x*t[0].y==0 && fabs(len(t[0])-len(t[1]))<eps) return true;
   return false;
}
int check()
{
   if(!is_ping()) return 0;///不是平行四边形
   if(a[3].x*a[1].x + a[3].y*a[1].y ==0 )///juxing
   {
       if(fabs(len(a[3])-len(a[1]))<eps) return 2;///zheng fang xing
       return 1; ///juxing
   }
  if(fabs(len(a[3])-len(a[1]))<eps) return 3; /// ling xing
  return 4;/// pingxing

}
int main()
{
    int T,cs = 1;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0; i<4; i++) scanf("%lld%lld",&a[i].x,&a[i].y);
        for(int i = 1; i<4; i++) a[i].x -= a[0].x,a[i].y -= a[0].y;
        a[0].x = 0,a[0].y = 0;

        int flag = check();
        printf("Case #%d: ",cs++);
        if(flag==0) puts("Others");
        else if(flag==1) puts("Rectangle");
        else if(flag==2) puts("Square");
        else if(flag==3) puts("Diamond");
        else puts("Parallelogram");
    }
    return 0;
}

