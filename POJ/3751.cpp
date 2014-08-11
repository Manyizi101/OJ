#include <iostream>
#include <cstdio>
using namespace std;

int t, y, mm, d, h, m, s, tag;
char ch[2][3] = {"am", "pm"};

int main(int argc, char const *argv[])
{

    cin >> t;
    while (t--)
    {
        scanf("%d/%d/%d-%d:%d:%d", &y, &mm, &d, &h, &m, &s);
        if (h < 12)
            tag = 0, h = (h == 0) ? 12 : h;
        else
            tag = 1, h = (h == 12) ? 12 : h - 12;
        printf("%02d/%02d/%04d-%02d:%02d:%02d%s\n", mm, d, y, h, m, s, ch[tag]);
    }
    return 0;
}