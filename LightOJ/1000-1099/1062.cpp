#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
int T;
double x, y, c;
double solve() {
	scanf("%lf%lf%lf", &x, &y, &c);
	double l = 0, r = min(x, y);
	double x2 = x * x, y2 = y * y;
	while (r - l > eps) {
		double mid = (l + r) / 2.0;
		double mid2 = mid * mid;
		double h1 = sqrt(x2 - mid2);
		double h2 = sqrt(y2 - mid2);
		double c1 = h1 * h2 / (h1 + h2);
		if (c1 > c) l = mid;
		else r = mid;
	}
	return l;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
