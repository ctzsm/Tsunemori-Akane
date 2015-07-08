#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, l[15];
char g[15][16];
int f[1 << 15];
int dfs(int mask) {
	if (f[mask] != -1) return f[mask];
	int res = 1000000 * n, x = mask;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			int mask2 = mask - (1 << i);
			int now = 1;
			for (int j = 0; j < n; ++j) {
				if (mask2 & (1 << j))
					now = max(now, g[j][i] - '0');
			}
			res = min(res, dfs(mask2) + (f[1 << i] - 1) / now + 1);
		}
	}
	return f[mask] = res;
}
int solve() {
	scanf("%d", &n);
	memset(f, -1, sizeof f);
	for (int i = 0; i < n; ++i) scanf("%d", &f[1 << i]);
	for (int i = 0; i < n; ++i) scanf("%s", g[i]);
	return dfs((1 << n) - 1);
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
