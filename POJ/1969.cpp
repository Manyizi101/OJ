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
#define inf (1<<30)
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    int temp_a, temp_b;
    int i, n;
    int num;
    while (cin >> num)
    {
        temp_a = 0;
        temp_b = 0;
        for (n = 1 ; temp_a != num ; n ++)
        {
            if (n % 2 == 0)
                for (i = 1 ; i <= n && temp_a != num ; i ++)
                {
                    a = i;
                    temp_a ++;
                }
            else
                for (i = n ; i > 0 && temp_a != num ; i --)
                {
                    a = i;
                    temp_a ++;
                }
        }
        for (n = 1; temp_b != num ; n ++)
        {
            if (n % 2 == 0)
                for (i = n; i > 0 && temp_b != num; i -- )
                {
                    b = i;
                    temp_b ++;
                }
            else
                for (i = 1; i <= n && temp_b != num; i++)
                {
                    b = i;
                    temp_b ++;
                }
        }
        cout << "TERM " << num << " IS " << a << "/" << b << endl;
    }
}