#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int n, m, in[100005];
void topsort() {
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			in[v] --;
			if (!in[v]) q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (in[i]) {
			puts("Yes");
			return;
		}
	puts("No");
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			in[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			in[y] ++;
			adj[x].push_back(y);
		}
		topsort();
	}
	return 0;
}
