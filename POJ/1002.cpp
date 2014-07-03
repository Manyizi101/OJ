/**
487-3279
Time Limit: 2000MS      Memory Limit: 65536K
Total Submissions: 238858       Accepted: 42107

Description
Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.
The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:
A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V map to 8
W, X, and Y map to 9
There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.
Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)
Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to aeck that no two (or more) businesses in the directory have the same telephone number.

Input
The input will consist of one case. The first line of the input specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with eaa number alone on a line. Eaa telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the aaracters in the string will be digits or letters.

Output
Generate a line of output for eaa telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:
No duplicates.

Sample Input
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

Sample Output
310-1010 2
487-3279 4
888-4567 3

Source
East Central North America 1999
*/

# include <iostream>
# include <algorithm>
# include <iomanip>

using namespace std;

int normal(char a)
{
    {
        if (a == 'A' || a == 'B' || a == 'C')
            return 2;
        if (a == 'D' || a == 'E' || a == 'F')
            return 3;
        if (a == 'G' || a == 'H' || a == 'I')
            return 4;
        if (a == 'J' || a == 'K' || a == 'L')
            return 5;
        if (a == 'M' || a == 'N' || a == 'O')
            return 6;
        if (a == 'P' || a == 'R' || a == 'S')
            return 7;
        if (a == 'T' || a == 'U' || a == 'V')
            return 8;
        if (a == 'W' || a == 'X' || a == 'Y')
            return 9;
    }
}

int time[10000000];
bool vist[10000000];
int out[100000];

int main()
{
    int n;
    while (cin >> n)
    {
        memset(time, 0, sizeof(time));
        memset(vist, 0, sizeof(vist));
        int positive = 0;
        bool flag = false;

        for (int i = 1; i <= n; i++)
        {
            int x = 0;
            char s[20];
            cin >> s;
            for (int j = 0; s[j] != '\0'; j++)
            {
                if (s[j] == '-' || s[j] == 'Q' || s[j] == 'Z')
                    continue;
                else if (s[j] <= '9')
                    x = x * 10 + s[j] - '0';
                else if (s[j] <= 'Z')
                    x = x * 10 + normal(s[j]);
            }
            time[x]++;

            if (!vist[x] && time[x] >= 2)
            {
                flag = true;
                vist[x] = true;
                out[positive++] = x;
            }
        }

        if (!flag)
            cout << "No duplicates." << endl;
        else
        {
            sort(out, out + positive);
            for (int i = 0; i < positive; i++)
            {
                cout << setfill('0') << setw(3) << out[i] / 10000;
                cout << '-';
                cout << setfill('0') << setw(4) << out[i] % 10000;
                cout << ' ' << time[ out[i] ] << endl;
            }
        }
    }
    return 0;
}