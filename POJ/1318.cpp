#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 105

string dic[MAX], out[MAX], tmp;
int n, i;
int flag;

int main(int argc, char const *argv[])
{
    while (cin >> dic[i] && dic[i][0] != 'X')  i++;
    sort(dic, dic + i);
    n = i;
    for (i = 0; i < n; i++)
    {
        out[i] = dic[i];
        sort(dic[i].begin(), dic[i].end());
    }
    while (cin >> tmp)
    {
        if (tmp[0] == 'X')   break;
        flag = 0;
        sort(tmp.begin(), tmp.end());
        for (i = 0; i < n; i++)
        {
            if (tmp == dic[i])
            {
                flag = 1;
                cout << out[i] << endl;
            }
        }
        if (flag == 0)
            cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    return 0;
}