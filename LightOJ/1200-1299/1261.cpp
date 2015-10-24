#include <cstdio>
#include <cstdlib>
#include <cstring>

int w[30][30];
bool c[31];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, m, K, q;
		scanf("%d%d%d", &n, &m, &K);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < K; ++j)
				scanf("%d", &w[i][j]);
		memset(c, false, sizeof c);
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int x; scanf("%d", &x);
			c[x] = true;
		}
		bool ans = true;
		for (int i = 0; i < n; ++i) {
			bool now = false;
			for (int j = 0; j < K; ++j)
				now = now || ((w[i][j] > 0) == c[abs(w[i][j])]);
			ans = ans && now;
		}
		printf("Case %d: %s\n", _, ans ? "Yes" : "No");
	}
	return 0;
}
