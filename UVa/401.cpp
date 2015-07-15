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

char r[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char msg[][30] = {" -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.", " -- is a mirrored palindrome."};

char rev(char x)
{
    if (isalpha(x))  return r[x - 'A'];
    else return r[x - '0' + 25];
}

int main(int argc, char const *argv[])
{
    char s[30];
    while (~scanf("%s", s))
    {
        int len = strlen(s);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (s[i] != s[len - 1 - i])    p = 0;
            if (rev(s[i]) != s[len - 1 - i])   m = 0;
        }
        printf("%s%s\n\n", s, msg[m * 2 + p]);
    }
    return 0;
}