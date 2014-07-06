#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14

float dis(float x, float y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int n,year,flag;
	float x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		year=1;
		flag=1;
		while(100*year<PI*dis(x,y)*dis(x,y))
			year++;
		cout<<"Property "<<flag<<": This property will begin eroding in year "<<year<<"."<<endl;
		flag++;
	}
	cout<<"END OF OUTPUT.";
	return 0;
}