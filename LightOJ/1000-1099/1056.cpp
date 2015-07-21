#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
double x, y;
void solve() {
	scanf("%lf : %lf", &x, &y);
	double ratio = x / y;
	double ratioc = sqrt(1 + ratio * ratio);
	double e = 2 * asin(1.0 / ratioc) * ratioc + 2 * ratio;
	double w = 400 / e;
	double h = ratio * w;
	printf("%.10f %.10f\n", h, w);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d: ", _);
		solve();
	}
	return 0;
}
