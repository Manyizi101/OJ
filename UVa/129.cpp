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
#define inf (1<<28)
#define ll long long int
using namespace std;

void Sequence(string &str, int &n, int L)
{
    int nLen = str.length(), nHalf = (str.length() + 1) / 2;
    for (char i = 'A', iEnd = L + 'A', m = 1; i < iEnd; ++i)
    {
        str.push_back(i);
        for (m = 1; m <= nHalf; ++m)
        {
            if (equal(str.end() - m, str.end(), str.end() - m * 2))
            {
                m = 0;
                break;
            }
        }
        if (m != 0)
        {
            if (--n == 0) return;
            Sequence(str, n, L);
            if (n == 0) return;
        }
        str.erase(nLen);
    }
}

int main(int argc, char const *argv[])
{
    for (int n, L; cin >> n >> L && n != 0; )
    {
        string str;
        Sequence(str, n, L);
        int nLen = str.length();
        for (size_t i = 4; i < str.length(); i += 5)
        {
            str.insert(str.begin() + i, i == 79 ? '\n' : ' ');
        }
        cout << str << '\n' << nLen << endl;
    }
    return 0;
}
