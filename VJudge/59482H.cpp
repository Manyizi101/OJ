#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char a[20];
int len[20];
int length;
int n;

void init()
{
    cin>>a;
    length=strlen(a);
}

int cmp(char str[], )

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        init();
        find_palindrome(a,len,length);
        cout<<len[2]<<endl;
    }
    return 0;
}
