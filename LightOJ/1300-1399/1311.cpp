#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

void solve(int _) {
	double v1, v2, v3, a1, a2;
	scanf("%lf%lf%lf%lf%lf", &v1, &v2, &v3, &a1, &a2);
	double t1 = v1 / a1, t2 = v2 / a2;
	printf("Case %d: %.6f %.6f\n", _, v1 * t1 / 2.0 + v2 * t2 / 2.0, v3 * max(t1, t2));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		solve(_);
	return 0;
}
