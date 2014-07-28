#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n=12;
	float money,sum=0;
	for(int i=0;i<12;i++)
		{
			cin>>money;
			sum+=money;
		}
	printf("$%.2f", sum/12);
	return 0;
}
