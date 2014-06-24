#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int T, x, a, b;
void solve() {
	scanf("%d%d%d", &a, &b, &x);
	double r = pow(a, b);
	int q = (int)(r / x);
	if (fabs(q * x - r) <= fabs((q + 1) * x - r)) {
		printf("%d\n", q * x);
	} else {
		printf("%d\n", (q + 1) * x);
	}
}
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}