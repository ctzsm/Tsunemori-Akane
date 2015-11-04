#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int n, d;
double x[20005], y[20005], f[20005];
bool check(double z) {
	for (int i = 0; i < n; ++i)
		f[i] = x[i] - z * y[i];
	sort(f, f + n, greater<double>());
	return accumulate(f, f + n - d, 0.0) >= 0.0;
}
void solve(int _) {
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) scanf("%lf%lf", x + i, y + i);
	double l = 0.0, r = 100.0;
	while (r - l > 1e-8) {
		double m = (l + r) / 2.0;
		if (check(m / 100)) l = m;
		else r = m;
	}
	printf("Case %d: %.8f\n", _, l);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) solve(_);
	return 0;
}
