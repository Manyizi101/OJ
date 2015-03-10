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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-10)
#define inf (1<<28)
#define ll long long int
using namespace std;

#define MAXN

int sign(double x) {
	return (x > eps) - (x < -eps);
}

template<typename func>
double simpson(double a, double b, func f) {
	return (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6;
}

template<typename func>
double integrate(double a, double b, func f) {
	double c = (a + b) / 2;
	double l = simpson(a, c, f);
	double r = simpson(c, b, f);
	double t = simpson(a, b, f);
	return sign(l + r - t) ? integrate(a, c, f) + integrate(c, b, f) : t;
}

struct func {
	double R, H, h, a;
	double operator()(double x) const {
		double nR = sqrt(R * R - x * x);
		double nh = h - (R - nR) * cos(a);
		if (!sign(sin(a))) {
			nh = max(0.0, nh);
			nh = min(nh, nR * 2);
			return nh * H;
		} else if (!sign(cos(a))) {
			nh = max(0.0, nh);
			nh = min(nh, H);
			return 2 * nR * nh;
		} else {
			nh = max(0.0, nh);
			nh = min(nh, nR * 2 * cos(a) + H * sin(a));
			if (min(nR * 2 * cos(a), H * sin(a)) >= nh) {
				return nh / sin(a) * nh / cos(a) / 2;
			} else if (max(nR * 2 * cos(a), H * sin(a)) <= nh) {
				return H * nR * 2
				       - (nR * 2 * cos(a) + H * sin(a) - nh) / sin(a)
				       * (nR * 2 * cos(a) + H * sin(a) - nh) / cos(a)
				       / 2;
			} else if (nR * 2 * cos(a) < H * sin(a)) {
				return (nR * 2 * cos(a)) / sin(a) * (nR * 2 * cos(a)) / cos(a)
				       / 2 + (nh - (nR * 2 * cos(a))) * ((nR * 2) / sin(a));
			} else {
				return (H * sin(a)) / sin(a) * (H * sin(a)) / cos(a) / 2
				       + (nh - (H * sin(a))) * (H / cos(a));
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	func f;
	while (cin >> f.R >> f.H >> f.h >> f.a) {
		f.a *= pi / 180;
		printf("%.7f\n", integrate(-f.R + eps, f.R - eps, f));
	}
	return 0;
}
