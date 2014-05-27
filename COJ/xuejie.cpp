#include  <iostream>
using namespace std;
int main()
{
    int h[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>h[i];
    }
    int height;
    cin>>height;
    int count = 0;
    for (int j = 0; j < 10; j++)
    {
        if ((height + 30) >= h[j])
        {
            count = count + 1;
        }
    }
    cout<<count;
    return 0;
}
