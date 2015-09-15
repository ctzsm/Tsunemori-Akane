#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool f[105][2];
vector<int> adj[105];
int solve() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(f, false, sizeof f);
	queue<pair<int, int> > q;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		pair<int, int> s = q.front(); q.pop();
		int u = s.first, g = s.second;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (f[v][g ^ 1]) continue;
			f[v][g ^ 1] = true;
			q.push(make_pair(v, g ^ 1));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (f[i][1]) ans++;
	return ans;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
