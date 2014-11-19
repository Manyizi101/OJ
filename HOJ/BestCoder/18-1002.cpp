#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

float a,b,c,d,l,r;
float A,B,C,Det,k,t,h;
float x1,x2,x3;

void cal()
{
    A=b*b-3*a*c;
    B=b*c-9*a*d;
    C=c*c-3*b*d;
    Det=B*B-4*A*C;
    if(a==0)
    {
        if(b==0)
        {
            if(c==0)
            {

            }
        }
    }
    else
    {
        if(A=B=0)   x1=x2=x3=-b/3/a;
        if(Det==0)
        {
            k=B/A;
            x1=-b/a+k;
            x2=x3=-k/2;
        }
        if(Det<0)
        {
            t=(2*A*b-3*a*B)/(2*sqrt(A*A*A));
            h=acos(t);
            x1=(-b-2*sqrt(A)*cos(h/3));
            x2=(-b+sqrt(A)(cos(h/3)+sqrt(3.0)*sin(h/3)))/(3*a);
            x3=(-b+sqrt(A)(cos(h/3)-sqrt(3.0)*sin(h/3)))/(3*a);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
