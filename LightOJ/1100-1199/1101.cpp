#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int> > PIII;
PIII e[100005];
vector<pair<int, int> > adj[50005];
int N, M, m;
int depth[50005], f[16][50005], maxc[16][50005];
int p[50005];
int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}
bool merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return false;
	p[fy] = fx;
	return true;
}
void dfs(int u, int p, int d, int w) {
	depth[u] = d;
	maxc[0][u] = w;
	f[0][u] = p;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first;
		if (v == p) continue;
		dfs(v, u, d + 1, adj[u][i].second);
	}
}
void buildLCA() {
	dfs(1, 0, 0, 0);
	for (m = 1; (1 << (m + 1)) <= N; ++m);
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= N; ++i) {
			if (!f[j - 1][i]) {
				f[j][i] = f[j - 1][i];
				maxc[j][i] = maxc[j - 1][i];
			} else {
				f[j][i] = f[j - 1][f[j - 1][i]];
				maxc[j][i] = max(maxc[j - 1][i], maxc[j - 1][f[j - 1][i]]);
			}
		}
	}
}
int query(int u, int v) {
	int res = 0;
	if (depth[u] < depth[v]) swap(u, v);
	for (int j = m; j >= 0; --j) {
		if (f[j][u] && depth[u] - (1 << j) >= depth[v]) {
			res = max(res, maxc[j][u]);
			u = f[j][u];
		}
	}
	if (u == v) return res;
	for (int j = m; j >= 0; --j) {
		if (f[j][u] && f[j][u] != f[j][v]) {
			res = max(res, max(maxc[j][u], maxc[j][v]));
			u = f[j][u], v = f[j][v];
		}
	}
	return max(res, max(maxc[0][u], maxc[0][v]));
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; ++i) adj[i].clear();
		for (int i = 0; i < M; ++i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			e[i] = make_pair(w, make_pair(u, v));
		}
		sort(e, e + M);
		for (int i = 1; i <= N; ++i) p[i] = i;
		for (int i = 0, j = 1; i < M && j < N; ++i) {
			int u = e[i].second.first, v = e[i].second.second;
			if (merge(u, v)) {
				adj[u].push_back(make_pair(v, e[i].first));
				adj[v].push_back(make_pair(u, e[i].first));
				j ++;
			}
		}
		buildLCA();
		int Q; scanf("%d", &Q);
		printf("Case %d:\n", _);
		for (int i = 0; i < Q; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}
	return 0;
}
