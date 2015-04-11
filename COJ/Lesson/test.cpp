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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1 << 31;
using namespace std;


int f(int a,int b)

{

if(a<b)

return f((b-a),a);

else if(a ==b)

return 2*a;

else

return f(f(a/2,b),f(b,b%2));

}

int main(int argc, char const *argv[])
{
	cout<<f(3,5);
	return 0;
}

