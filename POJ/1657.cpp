#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int chess[10][10];
int t;
char x1, x2;
int y1, y2;
int king, queen, elephant, vehicle;

void normalize(int x, int y)
{
    int i,j;
    for(i=1;i<9;i++)
        for(j=1;j<9;j++)
        {
            if(i=x||j=y)    chess[i][j]=1;
            else if(abs(i-j)==abs(x-y)) chess[i][j]=2;
            else chess[i][j]=0;
        }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(chess, 0, sizeof(chess));
        cin >> x1 >> y1;
        getchar();
        cin >> x2 >> y2;
        normalize(x1,y1);
    }
    return 0;
}