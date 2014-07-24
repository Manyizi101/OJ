#include <iostream>
#include <string.h>
using namespace std;

int root;
string n;

int main(int argc, char const *argv[])
{

    while (cin>>n&&n!="0")
    {
        root = 0;
        for (int i = 0; i < n.length(); i++)
        {
            root += n[i] - '0';
        }
        root %= 9;
        cout << (root == 0 ? 9 : root) << endl;
    }
    return 0;
}