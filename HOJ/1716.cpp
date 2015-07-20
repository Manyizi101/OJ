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

int a[4];
int firstOfLine, fisrtOfCase = 0, firstOfNum;

void print()
{
    for (int i = 0; i < 4; i++)    cout << a[i];
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0] + a[1] + a[2] + a[3]))
    {
        if (fisrtOfCase)    cout << endl;
        firstOfLine = fisrtOfCase = 1;
        do
        {
            if (!a[0]) continue;
            if (firstOfLine)
            {
                print();
                firstOfLine = 0;
                firstOfNum = a[0];
            }
            else if (firstOfNum == a[0])
            {
                cout << " ";
                print();
            }
            else
            {
                cout << endl;
                firstOfNum = a[0];
                print();
            }
        }
        while (next_permutation(a, a + 4));
        cout << endl;
    }
    return 0;
}