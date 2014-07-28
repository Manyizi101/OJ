#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010

int arr[MAX];
int i, n, k, t, temp, sum;

bool binary_search( int v, int len )
{
    int l, h, m;
    l = 0, h = len - 1;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (arr[m] == v)   return 1;
        else if ( arr[m] > v ) h = m - 1;
        else    l = m + 1;
    }
    return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >>     k;
        for (i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);

        sum = 0;
        for (i = 0; i < n; ++i)
        {
            if ( binary_search(k - arr[i], n) )
            {
                ++sum;
                if ( i != 0 && arr[i - 1] == arr[i])
                    --sum;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
