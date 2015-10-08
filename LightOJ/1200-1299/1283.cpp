#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[105], f[105][105][105];
int dfs(int p, int l, int r) {
	if (p > n) return 0;
	if (f[p][l][r] != -1) return f[p][l][r];
	int res = dfs(p + 1, l, r);
	if (a[l] <= a[p] && a[p] <= a[r]) {
		res = max(res, dfs(p + 1, p, r) + 1);
		res = max(res, dfs(p + 1, l, p) + 1);
	}
	return f[p][l][r] = res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		a[n + 1] = 1000000;
		memset(f, -1, sizeof f);
		printf("Case %d: %d\n", _, dfs(1, 0, n + 1));
	}
	return 0;
}
