#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int sur, def;
    while (scanf("%d%d", &sur, &def) != EOF)
    {
        int val;
        if (def > 4 * sur)  val = 10 * sur - 2 * def;
        else if (2 * def > 3 * sur)  val = 8 * sur - 4 * def;
        else if (3 * def > 2 * sur)  val = 6 * sur - 6 * def;
        else if (4 * def > sur)  val = 3 * sur - 9 * def;
        else  val = -12 * def;

        if (val <= 0)  cout << "Deficit" << endl;
        else  cout << val << endl;
    }
    return 0;
}