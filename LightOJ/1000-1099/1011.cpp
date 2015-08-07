#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m[16][16];
int f[1 << 16][16];
int dfs(int mask, int p) {
	if (mask == 0) return 0;
	if (f[mask][p] != -1) return f[mask][p];
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (mask & (1 << i))
			res = max(res, dfs(mask - (1 << i), p - 1) + m[p][i]);
	return f[mask][p] = res;
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &m[i][j]);
	memset(f, -1, sizeof f);
	return dfs((1 << n) - 1, n - 1);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
