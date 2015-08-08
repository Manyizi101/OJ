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
#define debug puts("-----")

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

int n;
string a[100]= {"0","1","2","3","5","8","12","18","27","40","59","87","128","188","276","405","594","871","1277","1872","2744","4022","5895","8640","12663","18559","27200","39864","58424","85625","125490","183915","269541","395032","578948","848490","1243523","1822472","2670963","3914487","5736960","8407924","12322412","18059373","26467298","38789711","56849085","83316384","122106096","178955182","262271567","384377664","563332847","825604415","1209982080","1773314928","2598919344","3808901425","5582216354","8181135699","11990037125"};;

int main()
{
    while(~scanf("%d", &n))
    {
        cout<<a[n]<<endl;
    }

}
