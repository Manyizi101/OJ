#include<iostream>
#include<set>
#include<map>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
	int n;
	set<int >s;
	map<int ,int >m;
	while(scanf("%d",&n),n){
		s.clear();
		m.clear();
		s.insert(1000000000);
		m[1000000000]=1;
		int i;
		for(i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d ",a);
			set<int >::iterator it1,it2;
			it1=s.lower_bound(b);
			if(it1==s.begin()) printf("%d\n",m[*it1]);
			else{
				it2=it1--;
				if(abs(*it1-b)>abs(*it2-b)) printf("%d\n",m[*it2]);
				else printf("%d\n",m[*it1]);
			}
			s.insert(b);
			m[b]=a;
		}
	}
}
