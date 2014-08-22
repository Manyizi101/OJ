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

char str[200];

void init()
{
    int i;

    str['1'] = '`';
    for (i = 2; i <= 10; i++)
    {
        str['0' + i % 10] = '0' + i - 1;
    }
    str['-'] = '0';
    str['='] = '-';
    str['W'] = 'Q';
    str['E'] = 'W';
    str['R'] = 'E';
    str['T'] = 'R';
    str['Y'] = 'T';
    str['U'] = 'Y';
    str['I'] = 'U';
    str['O'] = 'I';
    str['P'] = 'O';
    str['['] = 'P';
    str[']'] = '[';
    str['\\'] = ']';
    str['S'] = 'A';
    str['D'] = 'S';
    str['F'] = 'D';
    str['G'] = 'F';
    str['H'] = 'G';
    str['J'] = 'H';
    str['K'] = 'J';
    str['L'] = 'K';
    str[';'] = 'L';
    str['\''] = ';';
    str['X'] = 'Z';
    str['C'] = 'X';
    str['V'] = 'C';
    str['B'] = 'V';
    str['N'] = 'B';
    str['M'] = 'N';
    str[','] = 'M';
    str['.'] = ',';
    str['/'] = '.';
}

int main(int argc, char const *argv[])
{
    char ch;

    init();
    while ((ch = getchar()) != EOF)
    {
        if (ch != ' ' && ch != '\n')
        {
            putchar(str[ch]);
        }
        else
        {
            putchar(ch);
        }
    }
    return 0;
}
