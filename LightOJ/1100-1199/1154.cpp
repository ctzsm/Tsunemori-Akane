#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 205;
const int maxm = 41000;
const int oo = 0x3f3f3f3f;
int S, T, R;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int u, int v, int c): u(u), v(v), cap(c) {}
}es[maxm];
vector<int> adj[maxn];
int dis[maxn], cur[maxn];
void addEdge(int u, int v, int w) {
	adj[u].push_back(R);
	es[R++] = edge(u, v, w);
	adj[v].push_back(R);
	es[R++] = edge(v, u, 0);
}
bool dinic_bfs() {
	memset(dis, 0x3f, sizeof dis); dis[S] = 0;
	queue<int> q; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); ++i) {
			edge& e = es[adj[u][i]];
			if (e.cap < 1 || dis[e.v] < oo) continue;
			dis[e.v] = dis[u] + 1;
			q.push(e.v);
		}
	}
	return dis[T] < oo;
}
int dinic_dfs(int u, int maxflow) {
	if (u == T) return maxflow;
	for (int i = cur[u]; i < adj[u].size(); ++i) {
		cur[u] = i;
		edge& e = es[adj[u][i]];
		if (e.cap < 1 || dis[e.v] != dis[u] + 1) continue;
		int flow = dinic_dfs(e.v, min(maxflow, e.cap));
		if (flow) {
			e.cap -= flow;
			es[adj[u][i] ^ 1].cap += flow;
			return flow;
		}
	}
	return 0;
}
int dinic() {
	int res = 0, flow;
	while (dinic_bfs()) {
		memset(cur, 0, sizeof cur);
		while (flow = dinic_dfs(S, oo))
			res += flow;
	}
	return res;
}
int x[105], y[105], m[105], n[105];
void solve() {
	int ans = 0;
	int N, tot = 0; double D; scanf("%d%lf", &N, &D);
	for (int i = 0; i < N; ++i)
		scanf("%d%d%d%d", x + i, y + i, n + i, m + i);
	for (int i = 0; i < N; ++i) tot += n[i];
	for (int u = 0; u < N; ++u) {
		for (int i = 0; i < 2 * N + 2; ++i) adj[i].clear();
		S = 0, T = 1, R = 0;
		for (int i = 0; i < N; ++i)
			addEdge((i + 1) << 1, (i + 1) << 1 | 1, m[i]);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (i != j && hypot(x[i] - x[j], y[i] - y[j]) <= D)
					addEdge((i + 1) << 1 | 1, (j + 1) << 1, N * 10);
		for (int i = 0; i < N; ++i) {
			if (i == u) T = (i + 1) << 1;
			addEdge(S, (i + 1) << 1, n[i]);
		}
		int flow = dinic();
		// printf("tot = %d, flow = %d\n", tot, flow);
		if (flow == tot) { ans++; printf(" %d", u); }
	}
	if (!ans) printf(" -1\n");
	else printf("\n");
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case %d:", _);
		solve();
	}
	return 0;
}
