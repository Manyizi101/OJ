#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char num[35];
    while (cin >> num && num[0] != '0')
    {
        unsigned int pow = 1, sum = 0;
        for (int i = strlen(num) - 1; i >= 0; i --)
        {
            pow *= 2;
            sum += (num[i] - '0') * (pow - 1);
        }
        cout << sum << endl;
    }
    return 0;
}