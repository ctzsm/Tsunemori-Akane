#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, f, ans;
vector<pair<int, int> > adj[30001];
void dfs(int u, int p, int tot) {
	if (ans < tot) {
		ans = tot, f = u;
	}
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (v == p) continue;
		dfs(v, u, tot + w);
	}
}
int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) adj[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	ans = 0;
	dfs(0, -1, 0);
	dfs(f, -1, 0);
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
