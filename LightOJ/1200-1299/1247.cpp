#include <cstdio>

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, m; scanf("%d%d", &n, &m);
		long long ans = 0, x;
		for (int i = 0; i < n; ++i) {
			long long r = 0;
			for (int j = 0; j < m; ++j) {
				scanf("%lld", &x);
				r += x;
			}
			ans ^= r;
		}
		printf("Case %d: %s\n", _, ans ? "Alice" : "Bob");
	}
	return 0;
}
