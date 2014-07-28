#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char input[210], str[4];
int ans;

int dfs(char input[], int i)
{
    if (input[i] == '1')
    {
        if (input[i + 1] == '3')
        {
            if (input[i + 2] == '0')
            {
                ans += 52;
            }
            else
            {
                for (int j = i + 3; j < strlen(input) - 1; j++)
                {
                    if (input[j] == '0')
                        ans += 52;
                }
            }
        }
        else
        {
            for (int j = i + 2; j < strlen(input) - 2; j++)
            {
                if (input[j] == '3')
                {
                	if(input[j+1]=='0')
                		ans+=19;
                }
                else
                    for (int k = i + 3; j < strlen(input) - 1; j++)
                    {
                        if (input[j] == '0')
                            ans += 1;
                    }
                
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    while (cin >> input)
        return 0;
}