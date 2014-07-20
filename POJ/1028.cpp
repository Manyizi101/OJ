#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> forward;
stack<string> backward;
string order, tmp, now;

int main(int argc, char const *argv[])
{
    now = "http://www.acm.org/";
    while (cin >> order && order.compare("QUIT"))
    {
        if (!order.compare("VISIT"))
        {
            backward.push(now);
            cin >> now;
            cout << now << endl;
            while (!forward.empty()) forward.pop();
        }
        else if (!order.compare("BACK"))
        {
            if (!backward.empty())
            {
                forward.push(now);
                now = backward.top();
                backward.pop();
                cout << now << endl;
            }
            else
            {
                cout << "Ignored\n";
                continue;
            }
        }
        else if (!order.compare("FORWARD"))
        {
            if (!forward.empty())
            {
                backward.push(now);
                now = forward.top();
                forward.pop();
                cout << now << endl;
            }
            else
            {
                cout << "Ignored\n";
                continue;
            }
        }
    }
    return 0;
}