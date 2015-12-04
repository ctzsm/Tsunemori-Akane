#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int f[maxn], r[maxn], ans[maxn];
vector<int> adj[maxn];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu == fv) return;
	if (r[fu] < r[fv]) {
		f[fu] = fv;
		r[fv] += r[fu];
	} else {
		f[fv] = fu;
		r[fu] += r[fv];
	}
}
int chain;
int dfs(int u, int p) {
	int l = 0, r = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		int d = dfs(v, u) + 1;
		if (d >= l) { r = l; l = d; }
		else if (d > r) { r = d; }
	}
	chain = max(chain, l + r);
	return l;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			f[i] = i, r[i] = 1;
			adj[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
			merge(u, v);
		}
		int x = 0, q;
		memset(ans, 0x3f, sizeof ans);
		for (int i = 1; i <= n; ++i) {
			if (find(i) == i) {
				chain = 0;
				dfs(i, 0);
				x = max(x, r[i]);
				for (int j = 1; j <= chain + 1; ++j)
					ans[j] = min(ans[j], j - 1);
				for (int j = chain + 2; j <= r[i]; ++j)
					ans[j] = min(ans[j], chain + (j - chain - 1) * 2);
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int k; scanf("%d", &k);
			if (k <= x) printf("%d\n", ans[k]);
			else puts("impossible");
		}
	}
	return 0;
}
