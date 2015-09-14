#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
vector<pair<int, int> > adj[maxn];
int n, q, m;
int f[18][maxn], maxc[18][maxn], minc[18][maxn], depth[maxn];
void dfs(int u, int p, int d, int w) {
	depth[u] = d;
	f[0][u] = p;
	maxc[0][u] = minc[0][u] = w;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first;
		if (v == p) continue;
		dfs(v, u, d + 1, adj[u][i].second);
	}
}
void buildLCA() {
	dfs(1, 0, 0, 0);
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (!f[j - 1][i]) {
				f[j][i] = f[j - 1][i];
				maxc[j][i] = maxc[j - 1][i];
				minc[j][i] = minc[j - 1][i];
			} else {
				f[j][i] = f[j - 1][f[j - 1][i]];
				maxc[j][i] = max(maxc[j - 1][i], maxc[j - 1][f[j - 1][i]]);
				minc[j][i] = min(minc[j - 1][i], minc[j - 1][f[j - 1][i]]);
			}
		}
	}
}
pair<int, int> query(int u, int v) {
	if (u == v) return make_pair(0, 0);
	int mn = maxn, mx = 0;
	if (depth[u] < depth[v]) swap(u, v);
	for (int j = m; j >= 0; --j) {
		if (f[j][u] && depth[u] - (1 << j) >= depth[v]) {
			mx = max(mx, maxc[j][u]);
			mn = min(mn, minc[j][u]);
			u = f[j][u];
		}
	}
	if (u == v) return make_pair(mn, mx);
	for (int j = m; j >= 0; --j) {
		if (f[j][u] && f[j][u] != f[j][v]) {
			mx = max(mx, max(maxc[j][u], maxc[j][v]));
			mn = min(mn, min(minc[j][u], minc[j][v]));
			u = f[j][u], v = f[j][v];
		}
	}
	mx = max(mx, max(maxc[0][u], maxc[0][v]));
	mn = min(mn, min(minc[0][u], minc[0][v]));
	return make_pair(mn, mx);
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		scanf("%d", &n);
		for (m = 1; (1 << (m + 1)) <= n; ++m);
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		buildLCA();
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			pair<int, int> ans = query(u, v);
			printf("%d %d\n", ans.first, ans.second);
		}
	}
	return 0;
}
