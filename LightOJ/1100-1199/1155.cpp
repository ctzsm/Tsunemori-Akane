#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 250;
const int maxm = 50000;
const int oo = 0x3f3f3f3f;
struct edge {
	int u, v, cap;
	edge() {}
	edge(int _u, int _v, int _c): u(_u), v(_v), cap(_c) {}
}es[maxm];
int S, T, N, R;
int dis[maxn], cur[maxn];
vector<int> adj[maxn];
void addEdge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(u, v, c);
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
		int flow = dinic_dfs(e.v, min(e.cap, maxflow));
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
int solve() {
	int n, m, b, d;
	scanf("%d", &n);
	S = 0, T = 1, R = 0;
	for (int i = 0; i <= n * 2 + 1; ++i)
		adj[i].clear();
	for (int i = 1; i <= n; ++i) {
		int c; scanf("%d", &c);
		addEdge(i << 1, i << 1 | 1, c);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		addEdge(u << 1 | 1, v << 1, c);
	}
	scanf("%d%d", &b, &d);
	for (int i = 0; i < b; ++i) {
		int u; scanf("%d", &u);
		addEdge(S, u << 1, oo);
	}
	for (int i = 0; i < d; ++i) {
		int u; scanf("%d", &u);
		addEdge(u << 1 | 1, T, oo);
	}
	return dinic();
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
