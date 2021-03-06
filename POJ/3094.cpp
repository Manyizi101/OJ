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

int main(int argc, char const *argv[])
{
    char data[300];
    while (cin.getline(data, 300))
    {
        if (data[0] == '#')
            break;
        int sum = 0;
        for (int i = 0; data[i] != '\0'; i++)
        {
            if (data[i] != ' ')
                sum += (i + 1) * (data[i] - 'A' + 1);
        }
        cout << sum << endl;
    }
    return 0;
}
