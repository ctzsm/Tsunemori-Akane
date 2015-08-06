#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x7f7f7f7f;
int n, m, d[15][15], de[15];
int f[1 << 15];
int dfs(int mask) {
	if (f[mask] != -1) return f[mask];
	int res = oo;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if ((mask & (1 << i)) && (mask & (1 << j))) {
				int mask2 = mask - (1 << i) - (1 << j);
				res = min(res, dfs(mask2) + d[i][j]);
			}
		}
	return f[mask] = res;
}
int solve() {
	scanf("%d%d", &n, &m);
	memset(d, 0x7f, sizeof d);
	memset(f, -1, sizeof f);
	memset(de, 0, sizeof de);
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		d[u][v] = d[v][u] = min(d[u][v], w);
		de[u]++, de[v]++;
		sum += w;
	}
	for (int i = 0; i < n; ++i) d[i][i] = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (d[i][k] != oo && d[k][j] != oo)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	f[0] = 0;
	int mask = 0;
	for (int i = 0; i < n; ++i)
		if (de[i] & 1)
			mask |= 1 << i;
	return sum + dfs(mask);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
