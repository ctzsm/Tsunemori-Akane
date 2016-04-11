#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void solve() {
	int K, C, S;
	scanf("%d%d%d", &K, &C, &S);
	if (C * S < K) {
		printf(" IMPOSSIBLE\n");
		return;
	}
	int t = K / C + (K % C != 0);
	if (K == 1) {
		printf(" 1\n");
		return;
	}
	for (int i = 0, j = 0; i < t; ++i, j += C) {
		long long ans = 0;
		for (int k = 0; k < C; ++k) {
			ans *= K;
			ans += (k + j) % K;
		}
		printf(" %lld", ans + 1);
	}
	printf("\n");
}
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:", _);
		solve();
	}
	return 0;
}
