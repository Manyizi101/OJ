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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN 3000+50

char str[MAXN];

int main(int argc, char const *argv[])
{
	while (fgets(str, MAXN, stdin))
	{
		int len;
		len = strlen(str);
		int id;
		if(str[len-1]=='\n')
        {
            id = len-1;
        }
        else id = len;
		str[id] = ' ';
		reverse(str, str + id);
		int sl = 0;
		for (int i = 0; i <=len; ++i)
		{
			if (str[i] == ' ')
			{
                    reverse(str + sl, str + i);
					sl = (i + 1);
			}
		}
		str[id] = '\0';
		puts(str);

	}
    return 0;
}