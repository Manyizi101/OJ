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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;

char a[9][1025][1025];

void init()
{

	int up = 1 << 2;
	memset( a , ' ' , sizeof( a ) );
	for ( int i = 0 ; i < 9 ; i ++ )
	{
		for ( int j = 0 ; j < up ; j ++ )
		{
			a[i][j][0] = a[i][j][up - 1] =
			                 a[i][0][j] = a[i][up - 1][j] = '*';
			a[i][j][up] = '\0';
		}
		if ( i == 0 )
		{
			up <<= 1;
			continue;
		}

		for ( int k = ( up >> 3 ) + ( up >> 2 ) - 1; k >= up >> 3 ; k -- )
			a[i][up >> 3][k] = a[i][up >> 3][k + (up >> 1)] =
			                       a[i][(up >> 3) + (up >> 2)][k] = a[i][(up >> 3) + (up >> 2)][k + (up >> 1)] = '*';
		for ( int j = ( up >> 3 ) + ( up >> 2 ) - 1; j >= up >> 3 ; j -- )
			a[i][j][up >> 3] = a[i][j][(up >> 3) + (up >> 2) - 1] =
			                       a[i][j][(up >> 3) + (up >> 1)] = a[i][j][(up >> 3) + (up >> 2) - 1 + ( up >> 1) ] = '*';

		for ( int j = ( up >> 1 ) - 1; j >= 0 ; j -- )
			for ( int k = ( up >> 1 ) - 1; k >= 0 ; k -- )
				a[i][j + (up >> 1)][k + (up >> 2)] = a[i - 1][(up >> 1) - 1 - j][(up >> 1) - 1 - k];
		up <<= 1 ;
	}

}

int main(int argc, char const *argv[])
{
	int n;
	init();
	while ( scanf( "%d" , &n ) && n >= 8 )
	{
		int tmp = 4;
		int cnt = 0;
		while ( tmp != n )
		{
			tmp <<= 1;
			cnt ++;
			if ( cnt == 10 )
			{
				cnt = 0;
				break;
			}
		}

		for ( int i = 0 ; i < n ; i ++ )
		{
			printf( "%s\n" , a[cnt][i] );
		}
		puts( "" );
	}
}