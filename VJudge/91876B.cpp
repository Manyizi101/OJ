#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
#include<queue>
#define ll long long
using namespace std;

struct node
{
    ll word;
    int id;
    int top;
    node (ll a,int b,int c)
    {
        word = a;
        id = b;
        top = c;
    }
};
queue<node> q;
queue<node> q2;
set<int> s;
set<int> ::iterator it;
string ch;
int Top;
char a[50];
int x;
ll Word;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        while(!q.empty())   q.pop();
        int n;
        s.clear();
        cin>>n;
        Word = 0;
        Top = 0;
        node tmp(0,0,0);
        for(int i=0; i<n; i++)
        {
            scanf("%s",a);
            ch = a;
            // cout<<ch<<endl;
            if(ch!="Prior"&&ch!="Untop")
                scanf("%d",&x);
            printf("Operation #%d: ",i+1);
            if(ch=="Add")
            {
                // cout<<1;
                if(s.find(x)==s.end())
                {

                    q.push(node(0,x,0));
                    s.insert(x);
                    printf("success");
                }
                else
                    printf("same priority");
            }
            else if(ch=="Close")
            {
                int flag = 0;
                int istop = 0;
                int ff = 0;
                if(s.find(x)==s.end())
                {
                    printf("invalid priority");
                }
                else
                {
                    s.erase(x);
                    long long  w;
                    w = 0;
                    if(q.front().id==x)
                        ff =  1;
                    while(!q.empty())
                    {
                        if(q.front().id == x)
                        {
                            w = q.front().word;
                            istop = q.front().top;
                            q.pop();
                        }
                        else
                        {
                            q2.push(q.front());
                            q.pop();
                        }
                    }
                    while(!q2.empty())
                    {
                        q.push(q2.front());
                        q2.pop();
                    }
                    if(istop==1)
                    {
                        Top = 0;
                    }

                    printf("close %d with %I64d",x,w);
                }

            }
            else if(ch=="Chat")
            {
                if(Top==0)
                {
                    if(q.empty())
                    {
                        printf("empty");
                    }
                    else
                    {
                        q.front().word += x;
                        // if(q.front().id==2)
                        //  cout<<q.front().word<<"-------\n";
                        printf("success");
                    }
                }
                else
                {
                    while(!q.empty())
                    {
                        if(q.front().top == 1)
                        {
                            q.front().word += x;
                            // cout<<q.front().word<<"-----------\n";
                            q2.push(q.front());

                            q.pop();
                        }
                        else
                        {
                            q2.push(q.front());
                            q.pop();
                        }
                    }
                    while(!q2.empty())
                    {
                        q.push(q2.front());
                        q2.pop();
                    }
                    printf("success");
                }
            }
            else if(ch=="Rotate")
            {
                int cnt = 1;
                if(x==1)
                    printf("successful");
                else
                {
                    if(x>q.size())
                        printf("out of range");
                    else
                    {
                        while(!q.empty())
                        {
                            if(cnt == x)
                            {

                                // cout<<q.front().id<<"..........\n";
                                tmp = q.front();
                                q.pop();
                            }
                            else
                            {
                                q2.push(q.front());
                                q.pop();
                            }
                            cnt++;
                        }
                        q.push(tmp);
                        while(!q2.empty())
                        {
                            q.push(q2.front());
                            q2.pop();
                        }
                        printf("success");
                    }
                }
            }
            else if(ch=="Prior")
            {
                if(s.size()==0)
                {
                    printf("empty");
                }
                else
                {
                    it = s.end();
                    it--;
                    x = *it;
                    int flag = 0;
                    if(q.front().id == x)
                        printf("successful");
                    else
                    {
                        while(!q.empty())
                        {
                            if(q.front().id == x)
                            {
                                tmp = q.front();
                                flag = 1;
                                q.pop();
                            }
                            else
                            {
                                q2.push(q.front());
                                q.pop();
                            }
                        }
                        if(flag==0)
                        {
                            printf("empty");
                            while(!q2.empty())
                                q.push(q2.front()) , q2.pop();
                        }
                        else
                        {
                            printf("success");
                            q.push(tmp);
                            while(!q2.empty())
                                q.push(q2.front())  ,q2.pop();
                        }

                    }
                }
            }
            else if(ch=="Choose")
            {
                if(s.find(x)==s.end())
                    printf("invalid priority");
                else
                {
                    printf("success");
                    while(!q.empty())
                    {
                        if(q.front().id == x)
                        {
                            tmp = q.front();
                            q.pop();
                        }
                        else
                        {
                            q2.push(q.front());
                            q.pop();
                        }
                    }

                    q.push(tmp);
                    while(!q2.empty())
                    {
                        q.push(q2.front());
                        q2.pop();
                    }

                }
            }
            else  if(ch=="Top")
            {
                if(s.find(x)==s.end())
                    printf("invalid priority\n");
                else
                {
                    printf("success");
                    while(!q.empty())
                    {
                        q.front().top = 0;
                        q2.push(q.front());
                        q.pop();
                    }
                    while(!q2.empty())
                    {
                        if(q2.front().id == x)
                        {
                            q2.front().top = 1;
                            Top = 1;
                        }
                        q.push(q2.front());
                        q2.pop();
                    }
                }
            }
            else if(ch=="Untop")
            {
                if(Top==0)
                    printf("no such person\n");
                else
                {
                    printf("success");
                    Top = 0;
                    while(!q.empty())
                    {
                        q.front().top = 0;
                        q2.push(q.front());
                        q.pop();
                    }
                    while(!q2.empty())
                    {
                        q.push(q2.front());
                        q2.pop();
                    }
                }
            }
            printf(".\n");

            if(i==n-1)
            {
                if(Top==1)
                {
                    while(!q.empty())
                    {
                        if(q.front().top==1)
                        {
                            if(q.front().word)
                            {
                            printf("Bye %d: %I64d\n",q.front().id,q.front().word);
                            }
                            q.pop();
                        }
                        else
                        {
                            q2.push(q.front());
                            q.pop();
                        }
                    }
                    while(!q2.empty())
                        q.push(q2.front());
                }
                else
                {
                    while(!q.empty())
                    {
                        if(q.front().word)
                        {
                            printf("Bye %d: %I64d\n",q.front().id,q.front().word);
                        }
                        q.pop();
                    }
                }

            }
        }
    }
    return 0;
}
