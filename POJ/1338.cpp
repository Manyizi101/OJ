#include <iostream>
using namespace std;

const int MAX_POS = 1500;

int myMin(int a, int b, int c)
{
    int min;
    min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

int main(int argc, char const *argv[])
{
    int ugly[MAX_POS + 1];
    ugly[1] = 1;
    int p2, p3, p5;
    p2 = p3 = p5 = 1;

    for (int i = 2; i <= MAX_POS; i++)
    {
        int value2 = ugly[p2] * 2;
        int value3 = ugly[p3] * 3;
        int value5 = ugly[p5] * 5;
        ugly[i] = myMin(value2, value3, value5);
        if (ugly[i] == value2) p2++;
        if (ugly[i] == value3) p3++;
        if (ugly[i] == value5) p5++;
    }

    int n;
    while (cin >> n, n != 0)
    {
        cout << ugly[n] << endl;
    }

    return 0;
}