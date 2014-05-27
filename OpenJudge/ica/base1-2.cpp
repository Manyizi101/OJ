#include  <iostream>
#include  <math.h>

using namespace std;

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    if(n-(int)ceil(y/(x*1.0))>=0)
        cout<<n-(int)ceil(y/(x*1.0));
    else
        cout<<0;
    return 0;
}
