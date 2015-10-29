#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> adj[1005];
int n, m, a[1005];
bool visited[1005];
int sum, cnt;
void dfs(int u) {
	visited[u] = true;
	sum += a[u], cnt ++;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (visited[v]) continue;
		dfs(v);
	}
}
bool solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) adj[i].clear();
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int tot = accumulate(a + 1, a + n + 1, 0);
	if (tot % n) return false;
	int d = tot / n;
	memset(visited, false, sizeof visited);
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			sum = cnt = 0;
			dfs(i);
			if (sum % cnt) return false;
			if (sum / cnt != d) return false;
		}
	}
	return true;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %s\n", _, solve() ? "Yes" : "No");
	return 0;
}
