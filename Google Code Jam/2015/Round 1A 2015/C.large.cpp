#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-15;

int N, x[3005], y[3005];
long double a[6005];
void solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < N; ++i) {
		int an = 0, ans = N - 1;
		for (int j = 0; j < N; ++j)
			if (i != j)
				a[an++] = atan2l(y[j] - y[i], x[j] - x[i]);
		sort(a, a + an);
		for (int j = 0; j < an; ++j)
			a[j + an] = a[j] + 2 * M_PI;
		int r = 0;
		for (int j = 0; j < an; ++j) {
			while (r < 2 * an && a[r] - a[j] < M_PI - eps) r++;
			ans = min(ans, r - j - 1);
		}
		printf("%d\n", ans);
	}
}
int main() {
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:\n", _);
		solve();
	}
	return 0;
}
