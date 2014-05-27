#include  <iostream>
#include  <algorithm>
#define  PI  3.14159

using namespace std;

int main()
{
    int h,r;
    cin>>h>>r;
    cout<<(int)(20000/(PI*r*r)/h)+1;
    return 0;
}
