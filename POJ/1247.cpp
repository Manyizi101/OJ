#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int table[33];

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n,n)
    {
        memset(table,0,sizeof(table));
        int i;
        for(i=1;i<=n;i++)
        {
            cin>>table[i];
        }
        int sumE=0,sumS=0;
        int postE=n,postS=1;
        while(postS<=postE)
        {
            if(sumE>=sumS) {sumS+=table[postS];postS++;}
            else {sumE+=table[postE];postE--;}
        }
        if(sumE!=sumS)
        {
            cout<<"No equal partitioning."<<endl;
        }
        else cout<<"Sam stops at position "<<--postS<<" and Ella stops at position "<<++postE<<"."<<endl;
    }
    return 0;
}