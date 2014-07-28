#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    long long int  N;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int ret = 0;
        while (N)
        {
            ret = ret + N / 5;
            N = N / 5;
        }
        cout << ret << endl;
    }
    return 0;
}
