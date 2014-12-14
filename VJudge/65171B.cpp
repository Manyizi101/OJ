/*
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| : |||// \
//                     / _||||| -:- |||||- \
//                       | | \\\ - /// | |
//                     | \_| ''\---/'' | |
//                      \ .-\__ `-` ___/-. /
//                   ___`. .' /--.--\ `. . __
//                ."" '< `.___\_<|>_/___.' >'"".
//               | | : `- \`.;`\ _ /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  ������¥                  BUG����
//          ��Ի:
//                  д��¥��д�ּ䣬д�ּ������Ա��
//                  ������Աд�������ó��򻻾�Ǯ��
//                  ����ֻ���������������������ߣ�
//                  ��������ո��գ����������긴�ꡣ
//                  ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
//                  ���۱������Ȥ���������г���Ա��
//                  ����Ц��߯��񲣬��Ц�Լ���̫����
//                  ��������Ư���ã��ĸ���ó���Ա��
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;


string s;

int main(int argc, char const *argv[])
{
    while( cin >> s )
    {
        int len = s.size();
        vector<int> v;
        bool flag = true;
        string o;

        int pos = 0;
        if(s[0]=='@' || s[len-1]=='@')
        {
            flag = false;
        }
        else
        {
            for(int i=0; i<len; i++) if(s[i] == '@' )
                    v.push_back(i);
            if( v.size()==0 )
                flag = false;

            if(flag)
            {
                for(int i=0; i<v.size()-1; i++)
                {
                    if( v[i+1] - v[i] -1 < 2) flag = false;
                    else
                    {
                        for(int j=pos; j<=v[i]+1; j++) o += s[j];
                        pos = v[i] + 2;
                        o += ',';
                    }
                }
            }
        }
        for(int j=pos; j<s.size(); j++)
            o += s[j];
        if(!flag)
            cout << "No solution\n";
        else
            cout << o << endl;
    }
    return 0;
}
