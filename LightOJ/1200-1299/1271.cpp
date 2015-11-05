#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[50005];
int a[50005], pre[50005], ans[50005];
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		for (int i = 1; i < 50001; ++i) adj[i].clear();
		for (int i = 1; i < n; ++i) {
			adj[a[i - 1]].push_back(a[i]);
			adj[a[i]].push_back(a[i - 1]);
		}
		for (int i = 1; i < 50001; ++i) sort(adj[i].begin(), adj[i].end());
		int s = a[0], t = a[n - 1];
		memset(pre, -1, sizeof pre);
		queue<int> q; q.push(s); pre[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				if (pre[v] != -1) continue;
				pre[v] = u;
				if (v == t) break;
				q.push(v);
			}
			if (pre[t] != -1) break;
		}
		int c = 0;
		while (t) {
			ans[c++] = t;
			t = pre[t];
		}
		printf("Case %d:\n", _);
		for (int i = c - 1; i >= 0; --i)
			printf("%d%c", ans[i], i ? ' ' : '\n');
	}
	return 0;
}
