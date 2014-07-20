#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n;
double vs,r,c,w;

int main(int argc, char const *argv[])
{
    cin>>vs>>r>>c>>n;
    while(n--)
    {
        cin>>w;
        printf("%.3lf\n",(c*r*w*vs)/sqrt(1+(c*r*w)*(c*r*w)));
    }
    return 0;
}