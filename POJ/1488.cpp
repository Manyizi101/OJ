#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string a ;
    int count = 0;
    while (getline(cin, a))
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == '\"')
            {
                if (count == 0)
                {
                    cout << "``";
                    count = 1;
                }
                else
                {
                    count = 0;
                    cout << "''";
                }
            }
            else cout << a[i];
        }
        cout << endl;
    }
}