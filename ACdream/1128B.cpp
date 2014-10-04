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

float x11, y11, x12, y12, x21, y21, x22, y22;
float x, y, r;
float l1, l2;
float small;

float dis(float a, float b, float c, float d)
{
    return sqrt((a - b) * (a - b) + (c - d) * (c - d));
}

int main(int argc, char const *argv[])
{
    while (cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x21 >> y22 && (x11 || x12 || y11 || y12 || x21 || x22 || y21 || y22))
    {
        l1 = dis(x11, x21, y11, y21);
        l2 = dis(x12, x22, y12, y22);
        cout<<l1<<' '<<l2<<' '<<endl;
        if (l1 <= l2)
        {
            r = 1;
            while (r <= l1) r *= 2;
            cout << (x11 + x21) / 2 << ' ' << (y11 + y21) / 2 << ' ' << r << endl;
        }
        else
        {
            r = 1;
            while (r <= l2) r *= 2;
            cout << (x12 + x22) / 2 << ' ' << (y12 + y22) / 2 << ' ' << r << endl;
        }
    }
    return 0;
}