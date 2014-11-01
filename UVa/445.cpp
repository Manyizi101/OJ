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
#define inf (1<<28)
#define ll long long int
using namespace std;

char s[100010];

int main(int argc, char const *argv[])
{
    while(gets(s))
    {
        int c=0;
        for(int i=0; s[i]!='\0'; i++)
        {
            switch(s[i])
            {
            case 'b':
            {
                for(int j=0; j<c; j++)
                    printf(" ");
                c=0;
                break;
            }
            case '1':
                c=c+1;
                break;
            case '2':
                c=c+2;
                break;
            case '3':
                c=c+3;
                break;
            case '4':
                c=c+4;
                break;
            case '5':
                c=c+5;
                break;
            case '6':
                c=c+6;
                break;
            case '7':
                c=c+7;
                break;
            case '8':
                c=c+8;
                break;
            case '9':
                c=c+9;
                break;
            case '!':
                printf("\n");
            default:
            {
                for(int j=0; j<c; j++)
                    printf("%c",s[i]);
                c=0;
                break;
            }
            }
        }
        printf("\n");
    }
    return 0;
}
