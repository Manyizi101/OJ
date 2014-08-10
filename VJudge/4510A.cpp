#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n, i, tmp;
char x;

int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        map<char, int> m;
        for (i = 0; i < n; i++)
        {
            cin >> x >> tmp;
            m[x] += tmp;
        }
        if (m['S'] + m['E'] + m['C'] > 24)
        {
            cout << "Each day only has 24 hours!\n";
        }
        else
        {
            if (m['C'] < 8)
            {
                cout << "Clm feels guilty!\n";
            }
            else cout << "It's a nice day!\n";

        }
    }
    return 0;
}