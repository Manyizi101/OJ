#include<iostream>  
using namespace std;  
  
bool chess[6][6]={false}; 
bool flag;  
int step;  
int r[]={-1,1,0,0,0};
int c[]={0,0,-1,1,0};  
  
bool judge_all(void)
{  
    int i,j;  
    for(i=1;i<5;i++)  
        for(j=1;j<5;j++)  
            if(chess[i][j]!=chess[1][1])  
                return false;  
    return true;  
}  
  
void flip(int row,int col)
{  
    int i;  
    for(i=0;i<5;i++)  
        chess[row+r[i]][col+c[i]]=!chess[row+r[i]][col+c[i]];  
    return;  
}  
  
void dfs(int row,int col,int deep)  
{  
    if(deep==step)  
    {  
        flag=judge_all();  
        return;  
    }  
  
    if(flag||row==5)return;  
  
    flip(row,col);      
    if(col<4)  
        dfs(row,col+1,deep+1);  
    else  
        dfs(row+1,1,deep+1);  
  
    flip(row,col);       
    if(col<4)  
        dfs(row,col+1,deep);  
    else  
        dfs(row+1,1,deep);  
  
    return;  
}  
  
int main(void)  
{  
    char temp;  
    int i,j;  
    for(i=1;i<5;i++)  
        for(j=1;j<5;j++)  
        {  
            cin>>temp;  
            if(temp=='b')   
                chess[i][j]=true;  
        }  
  
    for(step=0;step<=16;step++)   
    {                            
        dfs(1,1,0);  
        if(flag)break;  
    }  
  
    if(flag)  
        cout<<step<<endl;  
    else  
        cout<<"Impossible"<<endl;  
    return 0;  
}  