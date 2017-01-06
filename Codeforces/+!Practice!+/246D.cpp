
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int n, m, cm = 0, c[maxn];
vector<int> adj[maxn];
bool visited[maxn], show[maxn];
set<int> h[maxn];
void dfs(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (c[u] != c[v])
			h[c[u]].insert(c[v]);
		dfs(v);
	}
}
int main() {
	// freopen("in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	for (int i = 1; i <= n; ++i) {
		show[c[i]] = true;
		cm = max(cm, c[i]);
	}
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		if (!visited[i])
			dfs(i);
	int ans = 0, cnt = -1;
	for (int i = 1; i <= cm; ++i)
		if (show[i] && (int)h[i].size() > cnt)
			ans = i, cnt = h[i].size();
	printf("%d\n", ans);
	return 0;
}