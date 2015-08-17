#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

double solve() {
	double x1, y1, r1, x2, y2, r2;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
	if (r1 < r2) {
		swap(x1, x2); swap(y1, y2); swap(r1, r2);
	}
	double len = hypot(x1 - x2, y1 - y2);
	if (len >= r1 + r2) return 0.0;
	if (len + r2 <= r1) return M_PI * r2 * r2;
	double a1 = acos((r1 * r1 + len * len - r2 * r2) / (2.0 * r1 * len));
	double a2 = acos((r2 * r2 + len * len - r1 * r1) / (2.0 * r2 * len));
	return a1 * r1 * r1 + a2 * r2 * r2 - r1 * len * sin(a1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %.10f\n", _, solve());
	return 0;
}
