#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	while(getline(cin, str))
	{
		int start = str.find("you");
		while(start != string::npos) 
		{
			str.replace(start, 3, "we");
			start = str.find("you", start+2); 
		}
		cout << str << endl;
	}
	return 0;
}