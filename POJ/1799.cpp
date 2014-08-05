#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = acos(-1.0);

int main(int argc, char const *argv[])
{
    int t;
    double R;
    int n, cas = 1;
    cin >> t;
    while (t--)
    {
        cin >> R >> n;
        double m = sin(pi / (double)n);
        printf("Scenario #%d:\n%.3f\n", cas++, m * R / (m + 1));
        if (t) cout << endl;
    }
    return 0;
}
