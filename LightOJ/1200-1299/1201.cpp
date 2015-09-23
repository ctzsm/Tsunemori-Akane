#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int maxn = 2050;
const int maxm = 2100000;
struct edge {
	int v, cap;
	edge() {}
	edge(int v, int c): v(v), cap(c) {}
}es[maxm];
int S, T, R;
int dis[maxn], cur[maxn];
vector<int> adj[maxn];
void addEdge(int u, int v, int c) {
	adj[u].push_back(R);
	es[R++] = edge(v, c);
	adj[v].push_back(R);
	es[R++] = edge(u, 0);
}
bool dinic_bfs() {
	memset(dis, 0x3f, sizeof dis);
	queue<int> q; q.push(S); dis[S] = 0;
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
int solve() {
	int n, m; scanf("%d%d", &n, &m);
	S = 0, T = 1, R = 0;
	for (int i = 0; i < 2 * n + 2; ++i)
		adj[i].clear();
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		addEdge(u << 1, v << 1 | 1, 1);
		addEdge(v << 1, u << 1 | 1, 1);
	}
	for (int i = 1; i <= n; ++i) {
		addEdge(S, i << 1, 1);
		addEdge(i << 1 | 1, T, 1);
	}
	return n - dinic() / 2;
}
int main() {
	freopen("in", "r", stdin);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_)
		printf("Case %d: %d\n", _, solve());
	return 0;
}
