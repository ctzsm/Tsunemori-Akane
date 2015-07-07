#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T, n, m, topo[10005], p;
vector<int> adj[10005];
bool visited[10005];
void dfs(int u, bool push = true) {
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (visited[v]) continue;
		dfs(v, push);
	}
	if (push) topo[p++] = u;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) adj[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}
		p = 1;
		memset(visited, false, sizeof visited);
		for (int i = 1; i <= n; ++i)
			if (!visited[i])
				dfs(i);
		int ans = 0;
		p = 1;
		memset(visited, false, sizeof visited);
		for (int i = n; i > 0; --i)
			if (!visited[topo[i]]) {
				dfs(topo[i], false);
				ans++;
			}
		printf("Case %d: %d\n", _, ans);
	}
	return 0;
}
