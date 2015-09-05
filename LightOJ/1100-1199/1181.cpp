#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
double g(int k, double x) {
	return pow(x, k);
}
double f(int k, double x) {
	return pow(x, k + 1) / (k + 1);
}
double solve() {
	int k;
	double a, b;
	scanf("%d%lf%lf", &k, &a, &b);
	if (fabs(b - a) < eps)
		return g(k, b);
	return (f(k, b) - f(k, a)) / (b - a);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
