#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void substitution(char a[], int dis)
{
    int i;
    int len = strlen(a);
    for (i = 0; i < len; i++)
    {
        a[i] += dis;
        if (a[i] > 'Z')    a[i] -= 26;
    }
    return;
}

int main()
{
    bool ans = false;
    int i, j;
    char in[110], out[110], tmp[110];
    cin >> in >> out;
    int len = strlen(in);
    for (i = 0; i < 26; i++)
    {
        strcpy(tmp, in);
        do
        {
            if (!strcmp(tmp, out))
            {
                ans = true;
                goto answer;
            }
        }
        while (next_permutation(tmp, tmp + 10));
        substitution(in, 1);
    }
answer:
    if (ans == true)   cout << "YES";
    else    cout << "NO";
    return 0;
}