/*
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int priority[101];
struct Job
{
	int priority;
	bool yours;
}job[101];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p,time = 1,pt = 0;
		memset(job,0,sizeof(Job)*100);
		queue<Job> q;
		scanf("%d%d",&n,&p);
		job[p].yours = 1;
		for(int i = 0;i < n;++i)
		{
			scanf("%d",&priority[i]);
			job[i].priority = priority[i];
			q.push(job[i]);
		}
		sort(priority,priority+n,cmp);
		while(q.front().priority != priority[pt] || !q.front().yours)
		{
			Job temp;
			temp = q.front();
			q.pop();
			if(temp.priority == priority[pt])
			{
				pt++;
				++time;
			}
			else	q.push(temp);
		}

		printf("%d/n",time);
	}
	return 0;
}
**/


#include<iostream>
#include<list>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int m,n,k,i,j;
	int v,kk,tmp,sum,summ;
	list<int>pzj;
	list<int>::iterator ita;
	list<int>::iterator itb;
	scanf("%d",&m);
	while(m--)
	{
		sum=0;
		summ=0;
		pzj.clear();
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&v);
			pzj.push_back(v);
			if(i==k)
				kk=v;
		}
		bool cs=0;
		k++;
		while(find(pzj.begin(),pzj.end(),kk)!=pzj.end())
		{
			summ++;
			cs=0;
			tmp=pzj.front();
			for(i=9;i>tmp;i--)
				if(find(pzj.begin(),pzj.end(),i)!=pzj.end())
				{
					cs=1;
					break;
				}
				if(cs)
				{
					pzj.pop_front();
					pzj.push_back(tmp);
					if(summ==k)
					{
						k=n-sum;
						summ=0;
					}
				}
				else
				{
					pzj.pop_front();
					sum++;
					if(summ==k)
						break;
				}
		}
		printf("%d\n",sum);
	}
	return false;
}
