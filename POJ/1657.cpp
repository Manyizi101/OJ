#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int t;
char x1, x2;
int y1, y2;
int x, y;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1;
        getchar();
        cin >> x2 >> y2;
        x = abs(x1 - x2);
        y = abs(y1 - y2);
        if (x == 0 && y == 0)  cout << "0 0 0 0" << endl;
        else
        {
            if (x < y) cout << y;
            else cout << x;
            if (x == y || x == 0 || y == 0)    cout << " 1";
            else cout << " 2";
            if (x == 0 || y == 0)  cout << " 1";
            else cout << " 2";
            if (abs(x - y) % 2 != 0) cout << " Inf" << endl;
            else if (x == y)   cout << " 1" << endl;
            else cout << " 2" << endl;
        }
    }
    return 0;
}