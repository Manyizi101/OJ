#include <iostream>
using namespace std;

int i;
int day, day1 = 0, coin = 0;

int main(int argc, char const *argv[])
{
    cin >> day;
    while (day)
    {
        coin = 0; day1 = 0;
        i = 0;
        do
        {
            i++;
            day1 += i;
            coin += i * i;
        }
        while (day1 < day);
        if (day1 > day) coin -= (day1 - day) * i;
        cout << day << ' ' << coin << endl;
        cin >> day;
    }
}