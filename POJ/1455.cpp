#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int ncases, n, times;
    cin >> ncases;
    while ( ncases-- )
    {
        cin >> n;
        times = n / 2 * (n / 2 - 1) / 2 + (n - n / 2) * (n - n / 2 - 1) / 2;
        cout << times;
        if ( ncases )
            cout << endl;
    }
    return 0;
}
