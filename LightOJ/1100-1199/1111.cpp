#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[1005];
int K, N, M;
bool s[1005], d[1005], ans[1005];
void bfs(int s) {
	memset(d, false, sizeof d);
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		d[u] = true;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (d[v]) continue;
			d[v] = true;
			q.push(v);
		}
	}
	for (int i = 1; i <= N; ++i)
		ans[i] = ans[i] && d[i];
}
int solve() {
	scanf("%d%d%d", &K, &N, &M);
	memset(s, false, sizeof s);
	memset(d, false, sizeof d);
	for (int i = 0; i < K; ++i) {
		int x; scanf("%d", &x);
		s[x] = true;
	}
	for (int i = 1; i <= N; ++i) adj[i].clear();
	for (int i = 0; i < M; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= N; ++i) ans[i] = true;
	for (int i = 1; i <= N; ++i) {
		if (s[i])
			bfs(i);
	}
	int res = 0;
	for (int i = 1; i <= N; ++i) 
		res += ans[i];
	return res;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
