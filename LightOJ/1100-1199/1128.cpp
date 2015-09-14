#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int n, m, q;
int s[100005] = {1}, f[18][100005], depth[100005];
void dfs(int u, int p, int d) {
	depth[u] = d;
	for (int i = 0; i < adj[u].size(); ++i)
		dfs(adj[u][i], u, d + 1);
}
void buildLCA() {
	dfs(0, -1, 0);
	for (m = 1; (1 << (m + 1)) <= n; ++m);
	for (int j = 1; j <= m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (f[j - 1][i] == -1)
				f[j][i] = f[j - 1][i];
			else
				f[j][i] = f[j - 1][f[j - 1][i]];
		}
	}
}
int query(int k, int v) {
	for (int j = m; j >= 0; --j) {
		if (f[j][k] != -1 && s[f[j][k]] >= v)
			k = f[j][k];
	}
	return k;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &q);
		f[0][0] = -1;
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", f[0] + i, s + i);
			adj[f[0][i]].push_back(i);
		}
		buildLCA();
		printf("Case %d:\n", _);
		for (int i = 0; i < q; ++i) {
			int k, v; scanf("%d%d", &k, &v);
			printf("%d\n", query(k, v));
		}
	}
	return 0;
}
