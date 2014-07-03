#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    float a, b = 0, i = 2;
    while (scanf("%f", &a)&&a!=0)
    {
        while (a-b>0.001)
        {
            b += 1 / i;
            i++;
        }
        cout << i-2 << ' ' << "card(s)" << endl;
        b=0;
        i=2;
    }
    return 0;
}