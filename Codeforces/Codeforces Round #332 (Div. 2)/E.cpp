#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, q;
bool e[15][15];
int lca[15][15], edge[15];
long long f[1 << 13][13];
bool check(int s, int t, int root, int child) {
	for (int i = 0; i < n; ++i) if (s & (1 << i)) {
		for (int j = 0; j < n; ++j) if (t & (1 << j)) {
			if (lca[i][j] != -1 && lca[i][j] != root) return false;
			if (i == root && j == child) continue;
			if (e[i][j]) return false;
		}
	}
	return true;
}
long long g(int mask, int root) {
	if (~f[mask][root]) return f[mask][root];
	if (!(mask & (1 << root))) return f[mask][root] = 0;
	if (__builtin_popcount(mask) == 1) return f[mask][root] = 1;
	long long res = 0;
	for (int i = (mask - 1) & mask; i; i = (i - 1) & mask) {
		int s = i, t = mask ^ i, hi = -1;
		if (t & (1 << root)) continue;
		for (int j = n - 1; j >= 0; --j)
			if (j != root && (mask & (1 << j))) {
				hi = j;
				break;
			}
		if (!(t & (1 << hi))) continue;
		int cnt = __builtin_popcount(t & edge[root]);
		if (cnt > 1) continue;
		if (cnt == 0) {
			for (int j = 0; j < n; ++j) if (t & (1 << j)) {
				if (check(s, t, root, j))
					res += g(s, root) * g(t, j);
			}
		}
		if (cnt == 1) {
			int r = t & edge[root];
			for (int j = 0; j < n; ++j) if (r & (1 << j)) {
				if (check(s, t, root, j))
					res += g(s, root) * g(t, j);
				break;
			}
		}
	}
	return f[mask][root] = res;
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	memset(e, false, sizeof e);
	memset(lca, -1, sizeof lca);
	memset(f, -1, sizeof f);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		u --, v --;
		e[u][v] = e[v][u] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (e[i][j]) edge[i] |= 1 << j;
	}
	for (int i = 0; i < q; ++i) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		a --, b --, c --;
		if (lca[a][b] != -1 && lca[a][b] != c) {
			printf("0\n");
			return 0;
		}
		if (a == b && a != c) {
			printf("0\n");
			return 0;
		}
		lca[a][b] = lca[b][a] = c;
	}
	printf("%lld\n", g((1 << n) - 1, 0));
	return 0;
}
