#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int band[11][110];
int price[11][110];
int picked_band[11];
int picked_price[11];
float BP[11][110];
float picked_BP[11]

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		int num,i,j;
		memset(band,0,sizeof(band));
		memset(price,0,sizeof(price));
		memset(BP,0,sizeof(BP));
		memset(picked_band,0,sizeof(picked_band));
		memset(picked_price,0,sizeof(picked_price));
		memset(picked_BP,0,sizeof(picked_BP));
		cin>>i;
		while(i--)
		{
			cin>>j;
			while(j--)
			{
				cin>>band[i][j]>>prince[i][j];
				BP[i][j]=(float)band[i][j]/(float)price[i][j];
				if(BP[i][j]>picked_BP[i])
				{
					picked_BP[i]=BP[i][j];
					picked_band[i]=band[i][j];
					picked_price[i]=band[i][j];
				}
			}
		}
		
	}
	return 0;
}