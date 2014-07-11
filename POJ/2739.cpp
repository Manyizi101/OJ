#include  <iostream>
#include  <cmath>

using namespace std;

int isPrime(int in)
{
    int i;
    for (i = 2; i <= sqrt(in); i++)
    {
        if (in % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int prime[10000], i, j = 0, a;
    for (i = 2; i < 10001; i++)
    {
        if (isPrime(i))
        {
            prime[j] = i;
            j++;
        }
    }
    for(i=0;i<20;i++)	cout<<prime[i]<<endl;
begin:
    while (cin >> a && a != 0)
    {
        for (i = 0; prime[i] <= a; i++)
        {
            int num = 0, sum = 0;
            for (j = i; prime[j] <= a; j++)
            {
                sum += prime[j];
                num++;
                cout<<prime[j];
                if (sum == a)
                {
                    //cout << num << endl;
                    //cout << sum << endl;
                    cout << num << endl;
                    goto begin;
                }
                else if (sum < a)  continue;
                else
                {
                    break;
                }
            }
        }
        cout << 0 << endl;
        goto begin;
    }
    return 0;
}