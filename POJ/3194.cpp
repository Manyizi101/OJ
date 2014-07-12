#include <iostream>  
#include <cstring>
using namespace std;  
int N, ans;  
int map[101][101];  
int visit[101][101];  
int step[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  
int color[101];  
bool Check(int x, int y)  
{  
    if (x >= N || x < 0 || y >= N || y < 0)  
        return false;  
    return true;  
}  
void DFS(int CurX, int CurY)  
{  
    ans++;  
    visit[CurX][CurY] = 1;  
    color[map[CurX][CurY]] = 1;  
    for (int i = 0; i < 4; i++)  
    {  
        int x = CurX+step[i][0];  
        int y = CurY+step[i][1];  
        if (Check(x, y) == false || visit[x][y] == 1)  
            continue;  
        if (map[CurX][CurY] == map[x][y] || color[map[x][y]] == 0)  
        {  
            DFS(x, y);  
        }  
    }  
}  
int main()  
{  
    while (cin>>N && N !=0)  
    {  
        int index = 1;  
        ans = 0;  
        memset(map, 0, sizeof(map));  
        memset(visit, 0, sizeof(visit));  
        memset(color, 0, sizeof(color));  
        for (int i = 0; i < N-1; i++)  
        {  
            for (int j = 0; j < N; j++)  
            {  
                int a, b;  
                cin>>a>>b;  
                map[a-1][b-1] = index;  
            }  
            index++;  
        }  
        DFS(0, 0);  
        if (ans == N*N)  
            cout<<"good"<<endl;  
        else  
            cout<<"wrong"<<endl;  
    }  
    return 0;  
}  