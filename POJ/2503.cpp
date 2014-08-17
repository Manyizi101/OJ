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
    char str[20], s1[20], s2[20];
    map<string, string>mymap;
    while (gets(str))
    {
        if (strlen(str) == 0) break;
        sscanf(str, "%s %s", s1, s2);
        mymap[s2] = s1;
    }
    while (gets(str))
    {
        if (mymap[str].length() == 0)
            puts("eh");
        else
            cout << mymap[str] << endl;
    }
    return 0;
}