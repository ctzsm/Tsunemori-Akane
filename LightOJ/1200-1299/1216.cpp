#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		double r1, r2, h, p;
		scanf("%lf%lf%lf%lf", &r1, &r2, &h, &p);
		double r3 = (r1 - r2) * p / h + r2;
		double v = (r2 * r2 + r2 * r3 + r3 * r3) * p * M_PI / 3;
		printf("Case %d: %.10f\n", _, v);
	}
}
