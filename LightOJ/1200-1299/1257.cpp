#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int, int> > adj[30005];
int ans[30005], len[30005];
int dfs1(int u, int p) {
	int res = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		pair<int, int>& now = adj[u][i];
		int v = now.first;
		if (v == p) continue;
		len[v] = dfs1(v, u) + now.second;
		res = max(res, len[v]);
	}
	return res;
}
void dfs2(int u, int p, int w) {
	int m1 = w, m2 = 0, p1 = p, p2 = -1;
	for (int i = 0; i < adj[u].size(); ++i) {
		pair<int, int>& now = adj[u][i];
		int v = now.first;
		if (v == p) continue;
		if (len[v] >= m1) {
			m2 = m1, p2 = p1;
			m1 = len[v], p1 = v;
		} else if (len[v] >= m2) {
			m2 = len[v], p2 = v;
		}
	}
	ans[u] = m1;
	for (int i = 0; i < adj[u].size(); ++i) {
		pair<int, int>& now = adj[u][i];
		int v = now.first;
		if (v == p) continue;
		dfs2(v, u, (v == p1 ? m2 : m1) + now.second);
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:\n", _);
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) adj[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		dfs1(0, -1);
		dfs2(0, -1, 0);
		for (int i = 0; i < n; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
