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
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
using namespace std;

#define MAXN 1002

int fl,gl;
double fx[MAXN], fy[MAXN], fk[MAXN],gx[MAXN], gy[MAXN], gk[MAXN];

void init()
{
    cin >> fl;
    for (int i = 1; i < fl; i++)    cin >> fx[i] >> fy[i];
    for (int i = 1; i < fl - 1; i++)  fk[i] = (fy[i + 1] - fy[i]) / (fx[i + 1] - fx[i]);
    cin >> gl;
    for (int i = 1; i < gl; i++)    cin >> gx[i] >> gy[i];
    for (int i = 1; i < gl - 1; i++)  gk[i] = (gy[i + 1] - gy[i]) / (gx[i + 1] - gx[i]);
}

double f(double x)
{
	for(int i=1;i<fl;i++)
}

double g(double x)
{

}

int main(int argc, char const *argv[])
{

    return 0;
}