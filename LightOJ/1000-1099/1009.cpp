#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> adj[20005];
vector<bool> visited;
int T, n, m;
void dfs(int u, int* color, int c) {
	visited[u] = true;
	color[c] += 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (visited[v]) continue;
		dfs(v, color, c ^ 1);
	}
}
int solve() {
	map<int, int> h;
	scanf("%d", &m);
	n = 0;
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		if (h.find(u) == h.end()) h[u] = n++;
		if (h.find(v) == h.end()) h[v] = n++;
		int hu = h[u], hv = h[v];
		adj[hu].push_back(hv);
		adj[hv].push_back(hu);
	}
	visited = vector<bool>(n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (!visited[i]) {
			int color[2] = {0, 0};
			dfs(i, color, 0);
			ans += max(color[0], color[1]);
		}
	for (int i = 0; i < n; ++i) adj[i].clear();
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
