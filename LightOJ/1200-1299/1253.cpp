#include <cstdio>

int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, c = 0, ans = 0; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			if (x == 1) c++;
			ans ^= x;
		}
		if (c == n) ans = c & 1 ^ 1;
		printf("Case %d: %s\n", _, ans ? "Alice" : "Bob");
	}
	return 0;
}
