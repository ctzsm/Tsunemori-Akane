#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 14 * 14 * 100000 + 5;
int n, p[14][14], f[1 << 14];
int dfs(int mask) {
	if (f[mask] != -1) return f[mask];
	int res = oo;
	for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
		int now = 0;
		for (int j = 0; j < n; ++j) if (mask & (1 << j)) {
			now += p[i][j];
		}
		res = min(res, now + dfs(mask - (1 << i)));
	}
	return f[mask] = res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &p[i][j]);
	}
	memset(f, -1, sizeof f); f[0] = 0;
	return dfs((1 << n) - 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}