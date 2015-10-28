#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[1005];
int f[1005][2], g[1005][2];
inline bool h(int v) {
	return f[v][0] < f[v][1] || (f[v][0] == f[v][1] && g[v][0] > g[v][1]);
}
void dfs(int u, int p) {
	if (f[u][0] != -1) return;
	f[u][0] = 0, f[u][1] = 1;
	g[u][0] = g[u][1] = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		f[u][0] += f[v][1], g[u][0] += g[v][1];
		bool flag = !h(v);
		f[u][1] += f[v][flag], g[u][1] += g[v][flag] + flag;
	}
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) adj[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(f, -1, sizeof f);
		memset(g, -1, sizeof g);
		int ans = 0, cnt = 0;
		for (int i = 0; i < n; ++i)
			if (f[i][0] == -1) {
				dfs(i, -1);
				bool flag = !h(i);
				ans += f[i][flag], cnt += g[i][flag];
			}
		printf("Case %d: %d %d %d\n", _, ans, cnt, m - cnt);
	}
	return 0;
}
