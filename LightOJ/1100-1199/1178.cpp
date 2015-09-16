#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

double area(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		double x = sqrt((a * c * c - c * a * a - a * d * d + c * b * b) / (c - a));
		printf("Case %d: %.10f\n", _, area(a, b, x) + area(c, d, x));
	}
	return 0;
}
