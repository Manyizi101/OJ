#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    int cipher[26], clear[26];
    memset(cipher, 0, sizeof(cipher));
    memset(clear, 0, sizeof(clear));
    string in, out;
    cin >> in;
    for (i = 0; i < in.length(); i++)
    {
        cipher[in[i] - 'A']++;
    }
    cin >> out;
    for (i = 0; i < out.length(); i++)
    {
        clear[out[i] - 'A']++;
    }
    sort(cipher, cipher + 26);
    sort(clear, clear + 26);
    for (i = 0; i < 26; i++)
        if (cipher[i] != clear[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}