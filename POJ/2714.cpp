#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
float x,y;
float dx,dy;
float ans;
int i;

int main(int argc, char const *argv[])
{
    while(cin>>n&&n!=0)
    {
        x=y=ans=0;
        for(i=0;i<n;i++)
        {
            cin>>dx>>dy;
            x+=dx;
            y+=dy;
            ans=ans>sqrt(x*x+y*y)?ans:sqrt(x*x+y*y);
        }
        printf("Maximum distance = %.3f meters.\n", ans);
    }
    return 0;
}