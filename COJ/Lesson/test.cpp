/* students please write your program here */

#include <iostream>
using namespace std;
class Integer {
private:
	int _num;
public:
//���캯��
	Integer(int num) {
		_num = num;
	}
//���㵱ǰInteger �� b֮������Լ��
	int gcd(Integer b)
	{
		int x = _num;
		int y = b._num;
		while (y != 0)
		{
			int r = y;
			y = x % y;
			x = r;
		}
		return x;
	}
};



int main() {
	int a, b;
	cin >> a >> b;
	Integer A(a);
	Integer B(b);
	cout << A.gcd(B) << endl;
	return 0;
}
