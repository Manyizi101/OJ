/*
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace  std;

int a[3001];
int record[3001];
int i,n;
int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)    scanf("%d", &a[i]);
        for(i=1;i<n;i++)
        {
            if(a[i]>=a[i-1])    record[i-1]=a[i]-a[i-1];
            if(a[i-1]>a[i])     record[i-1]=a[i-1]-a[i];
        }
        sort(record, record + n-1);
    }
    return 0;
}
*/


/*
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int dif[3000];

int main(){
	int n;
	while(cin >> n){
		memset(dif,0,sizeof(dif));
		int pre,current;
		cin >> pre;
		int i;
		for(i = 1; i < n; i++){
			cin >> current;
			int abs_dif = abs(current - pre);
			dif[abs_dif] = 1;
			pre = current;
		}

		for(i = 1; i < n; i++){
			if(dif[i] == 0)
				break;
		}

		if(i == n)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
}
**/

#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
    int num;

    while(cin>>num){
        int i;
        int *Jump = (int*)malloc(sizeof(int)*num);
        bool *flag = (bool*)malloc(sizeof(bool)*num);
        memset(flag,false,sizeof(bool)*num);

        for(int j=0;j<num;j++){
            cin>>Jump[j];
        }

        for(i=1;i<num;i++){
            int tmp;
            tmp = abs(Jump[i]-Jump[i-1]);
            if(flag[tmp]){
                break;
            }
            flag[tmp] = true;
        }

        if(i==num){
            cout<<"Jolly"<<endl;
        }else{
            cout<<"Not jolly"<<endl;
        }
    }
    return 0;
}
