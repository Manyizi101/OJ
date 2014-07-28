#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b)
{
    if (tolower(a) == tolower(b))
        return a < b;
    else
        return tolower(a) < tolower(b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end(), cmp);
        do
        {
            cout << str << endl;
        }
        while (next_permutation(str.begin(), str.end(), cmp));
    }
    return 0;
}