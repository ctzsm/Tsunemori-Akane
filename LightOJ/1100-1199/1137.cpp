#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
double calc(double L, double m) {
	if (m < eps) return L;
	double x = (L * L / 4.0 + m * m) / m / 2.0;
	double a = 2.0 * asin(L / 2.0 / x);
	return a * x;
}
double solve() {
	double L, n, C; scanf("%lf%lf%lf", &L, &n, &C);
	double Lp = (1 + n * C) * L;
	if (Lp - L < eps) return 0.0;
	double l = 0.0, r = L / 2;
	while (r - l > eps) {
		double m = (l + r) / 2.0;
		double Ld = calc(L, m);
		if (Ld == Lp) return m;
		else if (Ld > Lp) r = m;
		else l = m;
	}
	return l;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
