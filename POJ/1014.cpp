/*
#include <iostream>
#include <cstring>
using namespace std;

int marble[6];
char str[6];
int flag = 0;

bool judge(int input[])
{
    int i;
    for (i = 0; i < 6; i++)    str[i] = input[i] + '0';
    if (!(strcmp(str, "111000") && strcmp(str, "101100") && strcmp(str, "100110") && strcmp(str, "011010") && strcmp(str, "100011") && strcmp(str, "010101") && strcmp(str, "000000")&& strcmp(str, "011111")&& strcmp(str, "110111")))
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    while (cin >> marble[0] >> marble[1] >> marble[2] >> marble[3] >> marble[4] >> marble[5] && (marble[0] || marble[1] || marble[2] || marble[3] || marble[4] || marble[5]))
    {
        flag++;
        for (int i = 0; i < 6; i++)    marble[i] = marble[i] % 2;
        if (judge(marble))   cout << "Collection #" << flag << ':' << endl << "Can be divided." << endl;
        else cout << "Collection #" << flag << ':' << endl << "Can't be divided." << endl;
    }
    return 0;
}
**/

#include <iostream>
#include <cstring>
using namespace std;

int marble[6];
char str[6];
int flag = 0;

bool judge(int input[])
{
    int i,sum,value;
    for(i=0;i<6;i++)    sum+=input[i];
    for(i=0;i<6;i++)    value+=input[i]*(i+1);
    if (sum%2==0&&value%2==0)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    while (cin >> marble[0] >> marble[1] >> marble[2] >> marble[3] >> marble[4] >> marble[5] && (marble[0] || marble[1] || marble[2] || marble[3] || marble[4] || marble[5]))
    {
        flag++;
        for (int i = 0; i < 6; i++)    marble[i] = marble[i] % 2;
        if (judge(marble))   cout << "Collection #" << flag << ':' << endl << "Can be divided." << endl;
        else cout << "Collection #" << flag << ':' << endl << "Can't be divided." << endl;
    }
    return 0;
}