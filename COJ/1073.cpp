#include  <cstdio>
#include  <iostream>
#include  <string>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    if(b.find(a)>a.length())   printf("NO");
    else    printf("YES");
    return 0;
}
